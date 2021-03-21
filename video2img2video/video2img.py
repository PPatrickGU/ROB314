#!/usr/bin/env python
# -*- coding:utf-8 -*-

import cv2
import os

PATH = ['.\image', r'.\video_output']

for path in PATH:
    if not os.path.exists(path):
        os.makedirs(path)

vc = cv2.VideoCapture(r'.\vedio\giraffes_full_720.mp4')
n = 1

if vc.isOpened():
    ret, frame = vc.read()
else:
    ret = False
    
timeF = 10  # frame hertz
i = 0
while ret:  #
    ret, frame = vc.read()
    if (n % timeF == 0):  # every timeF frame
        i += 1
        # print(i)
        cv2.imwrite(PATH[0] + r'\{}.jpg'.format(i),frame)
    n = n + 1
    cv2.waitKey(1)
vc.release()


