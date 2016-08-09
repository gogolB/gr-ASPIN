/*
	TCP Server for ASPIN LAB to record data from the ettus E312.
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

#include "readerwriterqueue.h"

#define BUFFER_SIZE 1024
#define QUEUE_LENGTH 1024


// Global is done variable.
bool done = false;

// -----------------------------------------------------------------------------
// 			Helper Functions and structs
// -----------------------------------------------------------------------------

struct Job
{
	int* pData;
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
	info("Caught the signal");
	exit(2);
}

// ******************************************************************************
//				File Writer threads
// ******************************************************************************



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

	// Wait for the program to issue a shutdown.
	while(!done)
	{
		// Read data from the socket.

		// Enque the data
	}		
	// Close Close the socket.

	// Wait for the file writers to catch up.

	// Close Files.	
}
