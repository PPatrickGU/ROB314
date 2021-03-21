#!/usr/bin/env python
# -*- coding:utf-8 -*-

import cv2
import os
import numpy

PATH = ['.\image', r'.\video_output']

for path in PATH:
    if not os.path.exists(path):
        os.makedirs(path)

fps = 30

# Get image size
org_name = os.path.join(PATH[0], os.listdir(PATH[0])[0])   #img name
img = cv2.imread(org_name)
img_w, img_h = img.shape[1], img.shape[0]
size = (img_w, img_h)

fourcc=cv2.VideoWriter_fourcc(*'mp4v')

videoWriter = cv2.VideoWriter(PATH[1]+'\output.mp4', fourcc, fps, size, isColor=True)

for fname in os.listdir(PATH[0]): # file_name
    org_name = os.path.join(PATH[0],fname) # completed file name
    frame = cv2.imread(org_name)
    videoWriter.write(frame)
videoWriter.release()