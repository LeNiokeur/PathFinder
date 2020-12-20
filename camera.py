import picamera
import time
import random

camera = picamera.PiCamera()

camera.resolution = (2592, 1944)
camera.start_preview()
time.sleep(2)
camera.capture(randow()'/home/pi/Desktop/PathFinder/Pictures/obstacle_time.jpg')


