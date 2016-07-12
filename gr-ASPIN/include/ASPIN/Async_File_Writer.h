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


#ifndef INCLUDED_ASPIN_ASYNC_FILE_WRITER_H
#define INCLUDED_ASPIN_ASYNC_FILE_WRITER_H

#include <ASPIN/api.h>
#include <gnuradio/sync_block.h>
#include <string>

namespace gr {
  namespace ASPIN {

    /*!
     * \brief <+description of block+>
     * \ingroup ASPIN
     *
     */
    class ASPIN_API Async_File_Writer : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<Async_File_Writer> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of ASPIN::Async_File_Writer.
       *
       * To avoid accidental use of raw pointers, ASPIN::Async_File_Writer's
       * constructor is in a private implementation
       * class. ASPIN::Async_File_Writer::make is the public interface for
       * creating new instances.
       */
      static sptr make(std::string filename, int queue_size, int block_size);
    };

  } // namespace ASPIN
} // namespace gr

#endif /* INCLUDED_ASPIN_ASYNC_FILE_WRITER_H */

