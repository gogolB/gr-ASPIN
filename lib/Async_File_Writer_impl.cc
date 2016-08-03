/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "Async_File_Writer_impl.h"
#include <string>

namespace gr {
  namespace ASPIN {

    Async_File_Writer::sptr
    Async_File_Writer::make(std::string filename, int queue_size, int block_size)
    {
      return gnuradio::get_initial_sptr
        (new Async_File_Writer_impl(filename, queue_size, block_size));
    }
;
    /*
     * The private constructor
     */
    Async_File_Writer_impl::Async_File_Writer_impl(std::string filename, int queue_size, int block_size)
      : gr::sync_block("Async_File_Writer",
              gr::io_signature::make(1, block_size, sizeof(int)),
              gr::io_signature::make(0, 0, 0)),q(block_size),q2(queue_size)
    {
		this->s_filename = filename;
		this->i_queue_size = queue_size;
		this->i_block_size = block_size;
		this->done = false;
		this->numberEnqued = 0;
		this->numberDequed = 0;
		this->numberOfDroppedSamples=0;
		this->numberWritten = 0;		
#ifdef USE_JOB_SYSTEM
	      	pFile = fopen64((filename+"_job").c_str(), "wb");
#else
		pFile2 = fopen64(filename.c_str(), "wb");
#endif
		writer = boost::thread(boost::bind(&Async_File_Writer_impl::writeThread, this));
    }

    /*
     * Our virtual destructor.
     */
    Async_File_Writer_impl::~Async_File_Writer_impl()
    {
		this->done = true;
		printf("\nPlease wait writing %ld samples to disk...\n", numberEnqued - numberDequed);
		writer.join();
		//fclose(pFile);
		fclose(pFile2);
		printf("Enque: %ld, Dequed: %ld, Failed to write: %ld, Dropped: %ld\n", numberEnqued, numberDequed, numberEnqued - numberWritten, numberOfDroppedSamples);
    }

    int
    Async_File_Writer_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      // Create our own local copy of the pointer.
      const int *in = (const int *) input_items[0];

      // Do <+signal processing+>
#ifdef USE_JOB_SYSTEM
      // Uses the Job system.
      Job J = Job();
      int* p_samples = new int[noutput_items];
      if(p_samples == nullptr)
      {
	printf("\033[1;31mFailed to allocate array in memory.\033[0m\n");
	return 0;
      }

      memcpy(p_samples, in,  sizeof(int) * noutput_items);
      int val = memcmp(in, p_samples, sizeof(int) * noutput_items);
      if(val != 0)
	printf("\033[1;31mAll values failed to copied.\033[0m\n");

      J.p_data = p_samples;
      J.numElements = noutput_items;
      if(q.try_enqueue(J))
      {
	      numberEnqued += noutput_items;
      }
      else
      {
	      numberOfDroppedSamples += noutput_items;
	      printf("\033[1;31m[!] Failed to Enque! Currently dropped %ld samples. Current queue size: %ld\033[0m\n", numberOfDroppedSamples,numberEnqued-numberDequed);
      }
      
#else 
	for(int i = 0; i< noutput_items; i++)
	{
		if(q2.try_enqueue(in[i]))
		{
			numberEnqued++;
		}
		else
		{
			numberOfDroppedSamples++;
			printf("\033[1;31m[!] Failed to Enque! Currently dropped %ld samples. Current queue size: %ld\033[0m\n", numberOfDroppedSamples,numberEnqued-numberDequed);
 
		}
	}

#endif	
      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

	void
	Async_File_Writer_impl::writeThread()
	{
		
		while(!done)
		{
#ifdef USE_JOB_SYSTEM
			Job p;
			while(q.try_dequeue(p))
			{
				numberDequed+=p.numElements;
				if(fwrite(p.p_data, sizeof(int), p.numElements, pFile) == p.numElements)
				{
					numberWritten+=p.numElements;
				}
				else
				{
					perror("\033[1;31m [!] Failed to write sample to disk. Error");
					printf("\033[0m");

				}
				delete [] p.p_data;
			}


#else
			int d;
			while(q2.try_dequeue(d))
			{
				numberDequed++;
				if(fwrite(&d, sizeof(int), 1, pFile2) == 1)
				{
					numberWritten++;
				}
				else
				{
					perror("\033[1;31m [!] Failed to write sample to disk. Error");
					printf("\033[0m");

				}
			}			
#endif
			boost::this_thread::sleep(boost::posix_time::milliseconds(5));
		}
	}

  } /* namespace ASPIN */
} /* namespace gr */

