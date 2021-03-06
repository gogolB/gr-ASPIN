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
#include "Async_TCP_Client_impl.h"

namespace gr {
  namespace ASPIN {

    Async_TCP_Client::sptr
    Async_TCP_Client::make(std::string serverIP, int port, int payloadSize, int queueSize)
    {
      return gnuradio::get_initial_sptr
        (new Async_TCP_Client_impl(serverIP, port, payloadSize, queueSize));
    }

    /*
     * The private constructor
     */
    Async_TCP_Client_impl::Async_TCP_Client_impl(std::string serverIP, int port, int payloadSize, int queueSize)
      : gr::sync_block("Async_TCP_Client",
              gr::io_signature::make(1, 1, sizeof(int)),
              gr::io_signature::make(0, 0, 0)),
	      q(queueSize)
    {
	this->ServerIP = serverIP.c_str();
	this->port = port;
	this->payloadSize = payloadSize;
	this->sockfd = -1;

	this->done = false;
	this->numberEnqued = 0;
	this->numberDequed = 0;
	this->numberOfDroppedSamples=0;
	this->numberWritten = 0;

	//buf = new char[payloadSize * sizeof(int) + sizeof(int) + 1];

	connectToServer();

	printf("\033[1;36m[*]Starting sender thread...\033[0m\n");
	sender = boost::thread(boost::bind(&Async_TCP_Client_impl::sendPackets, this));
	
    }

    /*
     * Our virtual destructor.
     */
    Async_TCP_Client_impl::~Async_TCP_Client_impl()
    {
	
	if(sockfd > 0)
	{
		this->done = true;
		printf("\n\033[1;34m[!]Please wait writing %ld samples to disk...\033[0m\n", numberEnqued - numberDequed);
		sender.join();
		disconnectFromServer();
	}
    }

    int
    Async_TCP_Client_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const int *in = (const int *) input_items[0];

      // Do <+signal processing+>
      Job p = Job();
      int* p_samples = (int*) memalign(4096, sizeof(int)*noutput_items);
      if(p_samples == nullptr)
      {
	printf("\033[1;31m[!]Failed to allocate the array in memory.\033[0m\n");
	return 0;
      }

      memcpy(p_samples, in, sizeof(int) * noutput_items);
      p.p_data = p_samples;
      p.numElements = noutput_items;
      if(q.try_enqueue(p))
      {
	      numberEnqued += noutput_items;
      }
      else
      {
	      numberOfDroppedSamples += noutput_items;
	      printf("\033[1;31m[!] Failed to Enque! Currently dropped %ld samples. Current queue size: %ld\033[0m\n", numberOfDroppedSamples,numberEnqued-numberDequed);
      }


      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

    // This function will attempt to connect to ServerIP:port. It will wait forever.
    void Async_TCP_Client_impl::connectToServer()
    {
	printf("\033[1;36m[*]Attempting to connect to server (%s)...\033[0m\n",ServerIP);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		printf("\033[1;31m[!]Error opening socket!\033[0m\n");
		exit(10);
	}

	server = gethostbyname(ServerIP);

	if(server == NULL)
	{
		printf("\033[1;31m[!]Error getting Server!\033[0m\n");
		exit(11);
	}

 	bzero((char *) &serv_addr, sizeof(serv_addr));
   	serv_addr.sin_family = AF_INET;
   	if(inet_aton(ServerIP, &serv_addr.sin_addr) < 0)
	{
		printf("\033[1;31m[!]Error creating server addr struct! (%s)\033[0m\n", ServerIP);
		exit(12);
	}
   	serv_addr.sin_port = htons(port);
   
   	/* 
		Now connect to the server
		Will retry 5 times per second until it works.
	*/
  	while(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
      		printf("\033[1;31m[!]Error Connecting to Server!\033[0m\n");
		boost::this_thread::sleep(boost::posix_time::milliseconds(200));
   	}
	printf("\033[1;33m[!]Connected to Server!\033[0m\n");
	 	
    }

    // Will disconnect client from server.
    void Async_TCP_Client_impl::disconnectFromServer()
    {
	close(sockfd);
    }

    void Async_TCP_Client_impl::sendPackets()
    {
		while(!done)
		{
			Job p;
			while(q.try_dequeue(p))
			{
				numberDequed+=p.numElements;
				buf = (char*)memalign(4096 , sizeof(int)*p.numElements + sizeof(int) + sizeof(char));
				buf[0] = 1;
				int*pd = (int*) buf+1;
				pd[0] = p.numElements;
				memcpy(pd+1, p.p_data, sizeof(int)*p.numElements);

				if(write(sockfd, buf, sizeof(int)*p.numElements + sizeof(int) + sizeof(char)) == sizeof(int)*p.numElements + sizeof(int) + sizeof(char))
				{
					numberWritten+=p.numElements;
				}
				else
				{
					printf("\033[1;31m [!] Failed to send sample to Server.");
					printf("\033[0m");

				}
				free(p.p_data);
				free(buf);
			}
			boost::this_thread::sleep(boost::posix_time::milliseconds(200));
		}
    }

  } /* namespace ASPIN */
} /* namespace gr */

