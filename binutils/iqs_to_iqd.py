#!/usr/bin/python
import sys

def function():
  f2 = open("/media/joe/My Passport/HISTORY/cdma_5min_3p2.bin", "rb");
  f1 = open("/media/joe/My Passport/HISTORY/gps_5min_3p2.bin", "rb");
  o  = open("/media/joe/My Passport/HISTORY/gogol_combined.bin", "wb")
  i = 0;
  try:
    byte = f1.read(4)
    byte2 = f2.read(4)
    while byte != "":
        i = i + 1;
        # Do stuff with byte.
        o.write(byte[0])
        o.write(byte[1])
        o.write(byte2[0])
        o.write(byte2[1])
        o.write(byte[2])
        o.write(byte[3])
        o.write(byte2[2])
        o.write(byte2[3])
        if i % 1000000 == 0:
          print("Wrote " + str(i) + " sample.");
        byte = f1.read(4)
        byte2 = f2.read(4)
  finally:
    f1.close()
    f2.close()
    o.close()

if __name__ == '__main__':
  function()
