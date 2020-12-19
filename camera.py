import picamera
import time

camera = picamera.PiCamera()

camera.resolution = (640, 480)
camera.start_preview()
time.sleep(2)
camera.capture('/home/pi/Desktop/PathFinder/Pictures/obstacle.jpg')


