/*
	TCP Server for ASPIN LAB to record data from the ettus E312.
	@Author: Souradeep "Gogol" Bhattacharya

	A Packet must look like the following.
	[byte channel (1 or 2)][int numSamples][int sample0 to int samples(numSamples -1)]
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "readerwriterqueue.h"

#define BUFFER_SIZE 1000000
#define QUEUE_LENGTH 1024
#define FILE_1 "file1.bin"
#define FILE_2 "file2.bin"

// Global is done variable.
bool done = false;

// -----------------------------------------------------------------------------
// 			Helper Functions and structs
// -----------------------------------------------------------------------------

struct Job
{
	int* p_data;
	int numElements;
};

void p_error(const char* msg)
{
	printf("\033[1;31m[!]%s\033[0m\n", msg);
}


void error(const char* msg)
{
	p_error(msg);
	exit(1);
}

void info(const char* msg)
{
	printf("\033[1;36m[I]%s\033[0m\n", msg);
}

void success(const char* msg)
{
	printf("\033[1;32m[*]%s\033[0m\n",msg);
}

// -----------------------------------------------------------------------------

// Interupt handler
void _handler(int s)
{
	info("Caught the signal.\n   Terminating the server now.");
	done = true;
}

// ******************************************************************************
//				File Writer threads
// ******************************************************************************

moodycamel::ReaderWriterQueue<Job> q(QUEUE_LENGTH);
moodycamel::ReaderWriterQueue<Job> q1(QUEUE_LENGTH);

FILE* f1;
FILE* f2;


void writeThread1()
{
	while(!done)
	{
		Job p;
		while(q.try_dequeue(p))
		{
			// Write it to the file.
			fwrite(p.p_data, sizeof(int), p.numElements, f1);
			delete [] p.p_data;
		}
	}
	boost::this_thread::sleep(boost::posix_time::milliseconds(5));
}

void writeThread2()
{
	while(!done)
	{
		Job p;
		while(q1.try_dequeue(p))
		{
			// Write it to the file.
			fwrite(p.p_data, sizeof(int), p.numElements, f2);
			delete [] p.p_data;
		}
	}
	boost::this_thread::sleep(boost::posix_time::milliseconds(5));
}


// ******************************************************************************
int main (int argc, char **argv)
{
	// Process interrupt catch.
	struct sigaction sigIntHandler;
	sigIntHandler.sa_handler = _handler;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;

	sigaction(SIGINT, &sigIntHandler, NULL);

	// Server setup stuff.
	info("Starting Server...");

	int parentfd;
	int childfd = -1;
	int portno;
	socklen_t clientlen;
	struct sockaddr_in serveraddr;
	struct sockaddr_in clientaddr;
	struct hostent *hostp;
	char buf[BUFFER_SIZE];
	char *hostaddrp;
	int optval;
	int n;
	portno = 25565;

	// Create the Parent socket.
	parentfd = socket(AF_INET, SOCK_STREAM, 0);
	if(parentfd < 0)
		error("Failed to open socket");

	optval = 1;
	setsockopt(parentfd, SOL_SOCKET, SO_REUSEADDR, (const void*)&optval, sizeof(int));

	// Setting timeout...
	struct timeval timeout;
	timeout.tv_sec = 10;
	timeout.tv_usec = 0;

	if(setsockopt(parentfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0)
		error("Failed to set recieve timeout.");

	bzero((char*) &serveraddr, sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons((unsigned short)portno);

	info("Binding socket...");

	if(bind(parentfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
		error("Failed to bind socket!");

	if(listen(parentfd, 1) < 0) // Allow 1 connection.
		error("Failed to set listen.");

	clientlen = sizeof(clientaddr);
	success("Server Socket init done.");

	// Init the file writers
	info("Starting the file writers...");
	
	boost::thread writer;
	boost::thread writer2;

	f1 = fopen64(FILE_1, "wb");
	f2 = fopen64(FILE_2, "wb");

	writer = boost::thread(writeThread1);
	writer2 = boost::thread(writeThread2);
	

	success("Filewriter init done.");

	// Main body of server loop.
	success("Server fully initilized...");
	info("Waiting for connection...");

	while(childfd < 0)
	{
		childfd = accept(parentfd, (struct sockaddr*) &clientaddr, &clientlen);
		if(childfd < 0)
		{
			p_error("Could not accept connection...\n   Maybe it timed out?");
		}

	}
	success("Server has a connection!");
 
	hostp = gethostbyaddr((const char*) &clientaddr.sin_addr.s_addr, sizeof(clientaddr.sin_addr.s_addr), AF_INET);
	if(hostp == NULL)
		error("Failed to get host addr");
	hostaddrp = inet_ntoa(clientaddr.sin_addr);
	
	printf("Server established connection with %s (%s)\n", hostp->h_name, hostaddrp);
	// Wait for the program to issue a shutdown.
	while(!done)
	{
		// Read data from the socket.
		bzero(buf, BUFFER_SIZE);
		n = read(childfd, buf, BUFFER_SIZE);
		
		// Convert it to a int.
		int* p = (int*)buf[1];
		// First int is number of elements.
		int numE = p[0];
		// Create a new data pointer.
		int* data = p + 1;
		
		Job j = Job();
		j.numElements = numE;

		j.p_data = new int[numE];

		memcpy(j.p_data, data, sizeof(int)*numE);
		
		// Enque the data
		if(buf[0] == 1)
		{
			// This data is for queue one.
			q.try_enqueue(j);
		}
		else if(buf[0] == 2)
		{
			// This data is for queue two.
			q1.try_enqueue(j);
		}
	}
	info("Closeing the socket.");		
	// Close Close the socket.
	close(childfd);

	info("Waiting for the file writers to catch up.");
	// Wait for the file writers to catch up.

	writer.join();
	writer2.join();
	
	// Close Files.	
	info("Closing out the files.");
	fclose(f1);
	fclose(f2);
	success("Done!");
	return 0;
}
