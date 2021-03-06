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
#include "readerwriterqueue.h"

// Networking includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>
#include <malloc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

namespace gr {
  namespace ASPIN {

    struct Job
    {
	int* p_data;
	int numElements;
    };

    class Async_TCP_Client_impl : public Async_TCP_Client
    {
     private:
      // Nothing to declare in this block.
      const char* ServerIP;
      int port;
      int payloadSize;


      moodycamel::ReaderWriterQueue<Job> q;

      int sockfd;
      struct sockaddr_in serv_addr;
      struct hostent *server;

      char* buf;

      void connectToServer();
      void disconnectFromServer();


      boost::thread sender;


      long numberEnqued;
      long numberDequed;
      long numberOfDroppedSamples;
      long numberWritten;
      bool done;

     public:
      Async_TCP_Client_impl(std::string serverIP, int port, int payloadSize, int queueSize);
      ~Async_TCP_Client_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);

      void sendPackets();
    };

  } // namespace ASPIN
} // namespace gr

#endif /* INCLUDED_ASPIN_ASYNC_TCP_CLIENT_IMPL_H */

