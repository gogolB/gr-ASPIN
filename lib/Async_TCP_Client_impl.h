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

#ifndef INCLUDED_ASPIN_ASYNC_TCP_CLIENT_IMPL_H
#define INCLUDED_ASPIN_ASYNC_TCP_CLIENT_IMPL_H

#include <ASPIN/Async_TCP_Client.h>
#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "readerwriterqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>

namespace gr {
  namespace ASPIN {

    class Async_TCP_Client_impl : public Async_TCP_Client
    {
     private:
      char* s_ServerIP;
      short s_Port;
      int i_payloadSizeInSamples;
      bool isConnected = false;

      void attemptToConnect();

     public:
      Async_TCP_Client_impl(char* serverIP, short port, int payloadSizeInSamples);
      ~Async_TCP_Client_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace ASPIN
} // namespace gr

#endif /* INCLUDED_ASPIN_ASYNC_TCP_CLIENT_IMPL_H */
