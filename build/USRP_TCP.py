#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: USRP_TCP
# Author: Gogol
# Description: Transmit data from the E312 to a target via tcp.
# Generated: Wed Aug 10 18:38:07 2016
##################################################

from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio import uhd
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from optparse import OptionParser
import ASPIN
import time


class USRP_TCP(gr.top_block):

    def __init__(self):
        gr.top_block.__init__(self, "USRP_TCP")

        ##################################################
        # Blocks
        ##################################################
        self.uhd_usrp_source_0 = uhd.usrp_source(
        	",".join(("", "")),
        	uhd.stream_args(
        		cpu_format="sc16",
        		otw_format="sc16",
        		channels=range(1),
        	),
        )
        self.uhd_usrp_source_0.set_time_source("gpsdo", 0)
        self.uhd_usrp_source_0.set_samp_rate(4e6)
        self.uhd_usrp_source_0.set_center_freq(1575.42e6, 0)
        self.uhd_usrp_source_0.set_gain(30, 0)
        self.uhd_usrp_source_0.set_antenna("RX2", 0)
        (self.uhd_usrp_source_0).set_min_output_buffer(100)
        (self.uhd_usrp_source_0).set_max_output_buffer(200)
        self.blocks_head_0 = blocks.head(gr.sizeof_short*2, 1024)
        self.ASPIN_Async_TCP_Client_0 = ASPIN.Async_TCP_Client("192.168.10.10", 25565, 1472, 1000000)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.blocks_head_0, 0), (self.ASPIN_Async_TCP_Client_0, 0))    
        self.connect((self.uhd_usrp_source_0, 0), (self.blocks_head_0, 0))    


def main(top_block_cls=USRP_TCP, options=None):
    if gr.enable_realtime_scheduling() != gr.RT_OK:
        print "Error: failed to enable real-time scheduling."

    tb = top_block_cls()
    tb.start()
    try:
        raw_input('Press Enter to quit: ')
    except EOFError:
        pass
    tb.stop()
    tb.wait()


if __name__ == '__main__':
    main()
