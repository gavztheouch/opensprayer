import cv2       #import opencv needed for webcam
import time
import matplotlib.pyplot as plt    #matplotlib to show images


video_capture = cv2.VideoCapture(0)
time.sleep(3)
ret, frame = video_capture.read()
plt.imshow(frame)
plt.show() 
video_capture.release()
