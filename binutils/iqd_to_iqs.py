#!/usr/bin/python
import sys
def function():
  f = open("/media/joe/My Passport/E312_Tests/GPS_and_CDMA_small.bin", "rb");
  o = open("/media/joe/My Passport/E312_Tests/GPS_small.bin", "wb")
  i = 0;
  try:
    byte = f.read(8)
    while byte != "":
        i = i + 1;
        # Do stuff with byte.
        o.write(byte[0])
        o.write(byte[1])
        o.write(byte[4])
        o.write(byte[5])
        if i % 1000000 == 0:
          print("Wrote " + str(i) + " sample.");
        byte = f.read(8)
  finally:
    f.close()
    o.close()

if __name__ == '__main__':
  function()
