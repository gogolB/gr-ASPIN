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

#ifndef INCLUDED_ASPIN_ASYNC_FILE_WRITER_IMPL_H
#define INCLUDED_ASPIN_ASYNC_FILE_WRITER_IMPL_H

#include <ASPIN/Async_File_Writer.h>
#include <boost/lockfree/spsc_queue.hpp>
#include <stdio.h>
#include <chrono>
#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "readerwriterqueue.h"
#include <string.h>

namespace gr {
  namespace ASPIN {


    struct Job
    {
	    int* p_data;
	    int numElements;
    };	    
    class Async_File_Writer_impl : public Async_File_Writer
    {
     private:
      // Nothing to declare in this block.
      std::string s_filename;
      int i_queue_size;
      int i_block_size;

      //boost::lockfree::spsc_queue<int, boost::lockfree::capacity<209715200> > queue;
      moodycamel::ReaderWriterQueue<Job> q;
      moodycamel::ReaderWriterQueue<int> q2;

      bool done;

      FILE* pFile;
      FILE* pFile2;
      boost::thread writer;

      long numberEnqued;
      long numberDequed;
      long numberOfDroppedSamples;
      long numberWritten;

     public:
      Async_File_Writer_impl(std::string filename, int queue_size, int block_size);
      ~Async_File_Writer_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);

      void writeThread();

    };

  } // namespace ASPIN
} // namespace gr

#endif /* INCLUDED_ASPIN_ASYNC_FILE_WRITER_IMPL_H */

