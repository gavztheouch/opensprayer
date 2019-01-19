import cv2       #import opencv needed for webcam
import time
import matplotlib.pyplot as plt    #matplotlib to show images


video_capture = cv2.VideoCapture(0)
time.sleep(1)
ret, frame = video_capture.read()
crop_img = frame[0:256, 0:256]     #this is numpy slicing 0:256 is y values between 0 and 256 the other is x values of the matrix
crop_img2 = frame[0:256, 256:512]     #this is numpy slicing
gray = cv2.cvtColor(crop_img, cv2.COLOR_BGR2GRAY )   #convert to grayscale
gray2 = cv2.cvtColor(crop_img2, cv2.COLOR_BGR2GRAY )   #convert to grayscale
ret,im_bw = cv2.threshold(gray, 128, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
plt.imshow(frame)
plt.show() 
plt.imshow(gray, cmap=plt.cm.gray)
plt.show()
plt.imshow(gray2, cmap=plt.cm.gray)
plt.show()
plt.imshow(im_bw, cmap=plt.cm.gray)
plt.show() 
video_capture.release()

#cv2.imshow('image',im_bw)
#cv2.waitKey(0)
#cv2.destroyAllWindows()
