import serial
ser = serial.Serial('/dev/cu.usbserial-A60205DR',9600)

import urllib

urlarray = ["http://192.168.22.1","http://www.google.com","https://github.com/","http://www.apple.com/","http://google.com/","http://www.google.com","http://www.google.com","http://www.google.com","http://www.google.com","http://www.google.com"]

import string
locationarray = list(string.ascii_lowercase)

resultsarray = []

for x in range(0,len(urlarray)):
  print locationarray[x] + ": " + urlarray[x]

import time
time.sleep(2)
current_milli_time = lambda: int(round(time.time() * 1000))

while True:
  for i in range(0,len(urlarray)):
    t0 = current_milli_time()
    try:
      status = urllib.urlopen(urlarray[i]).getcode()
    except:
      status = 999

    deltat = current_milli_time() - t0

    statusstr = locationarray[i]
    if status > 299:
      statusstr += "d"
    elif deltat < 300:
      statusstr += "a"
    elif deltat >= 300 and deltat < 900:
      statusstr += "b"
    elif deltat >= 900:
      statusstr += "c"

    resultsarray.append(statusstr)

  for result in resultsarray:
    ser.write(result)

  resultsarray = []
