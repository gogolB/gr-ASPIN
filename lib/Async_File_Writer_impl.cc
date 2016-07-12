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
              gr::io_signature::make(0, 0, 0))
    {
		this->s_filename = filename;
		this->i_queue_size = queue_size;
		this->i_block_size = block_size;
		this->done = false;

		file.open(filename.c_str(), std::ios::out|std::ios::binary);
		writer = boost::thread(boost::bind(&Async_File_Writer_impl::writeThread, this));
    }

    /*
     * Our virtual destructor.
     */
    Async_File_Writer_impl::~Async_File_Writer_impl()
    {
		this->done = true;
		writer.join();
		file.close();
    }

    int
    Async_File_Writer_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const int *in = (const int *) input_items[0];

      // Do <+signal processing+>
	  queue.push(*in);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

	void
	Async_File_Writer_impl::writeThread()
	{
		while(!done)
		{
			int p;
			while(queue.pop(p))
			{
				file.write((char*)&p, sizeof(int));
			}
			
		}
	}

  } /* namespace ASPIN */
} /* namespace gr */

