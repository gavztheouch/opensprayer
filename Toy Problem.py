import cv2       #import opencv needed for webcam
import time
import matplotlib.pyplot as plt    #matplotlib to show images


video_capture = cv2.VideoCapture(0)
time.sleep(3)
ret, frame = video_capture.read()
crop_img = frame[0:256, 0:256]     #this is numpy slicing x and y coords for box
plt.imshow(frame)
plt.show() 
plt.imshow(crop_img)
plt.show() 
video_capture.release()
