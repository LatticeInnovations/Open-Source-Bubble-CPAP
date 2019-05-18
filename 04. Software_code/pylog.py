from __future__ import print_function
import serial, time, io, datetime
from serial import Serial

#'ser = serial.Serial("/dev/ttyACM0", 9600, timeout=0)'

addr = "/dev/ttyACM0" ## serial port to read data from, this to be changed accordingly.
baud = 115200 ## baud rate for instrument

ser = serial.Serial(
    port = addr,\
    baudrate = baud,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
    timeout=0)


print("Connected to: " + ser.portstr)

filename="log.csv"
while True:
    datafile=open(filename, 'a')
    data = ser.readline()
    datafile.write(data)
    print(data)
    time.sleep(1)
datafile.close()
ser.close()


    
