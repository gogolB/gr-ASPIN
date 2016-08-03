/* -*- c++ -*- */

#define ASPIN_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "ASPIN_swig_doc.i"

%{
#include "ASPIN/Async_File_Writer.h"
#include "ASPIN/Async_TCP_Client.h"
%}

%include "ASPIN/Async_File_Writer.h"
GR_SWIG_BLOCK_MAGIC2(ASPIN, Async_File_Writer);

%include "ASPIN/Async_TCP_Client.h"
GR_SWIG_BLOCK_MAGIC2(ASPIN, Async_TCP_Client);
