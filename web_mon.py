import serial
ser = serial.Serial('/dev/cu.usbserial-A60205DR',9600)
import Queue
import threading
import urllib
import string
import time

time.sleep(2)

urlarray = ["http://192.168.22.1","http://www.google.com","https://github.com/","http://www.apple.com/"]
pausearray = [2, 5, 5, 5]
locationarray = list(string.ascii_lowercase)
q = Queue.Queue()

current_milli_time = lambda: int(round(time.time() * 1000))

def get_url(q, location, url, pause_seconds):
  t0 = current_milli_time()
  try:
    status = urllib.urlopen(url).getcode()
  except:
    status = 999

  deltat = current_milli_time() - t0

  statusstr = location
  if status > 299:
    statusstr += "d"
  elif deltat < 300:
    statusstr += "a"
  elif deltat >= 300 and deltat < 900:
    statusstr += "b"
  elif deltat >= 900:
    statusstr += "c"

  q.put(statusstr)
  time.sleep(pause_seconds)
  get_url(q, location, url, pause_seconds)

for i in range(0,len(urlarray)):
  print locationarray[i] + ": " + urlarray[i]
  t = threading.Thread(target=get_url, args = (q, locationarray[i], urlarray[i], pausearray[i]))
  t.daemon = True
  t.start()

while True:
  result = q.get()
  ser.write(result)
