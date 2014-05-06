# -*- coding: utf-8 -*-
"""
Created on Wed Mar  5 13:43:26 2014
Project	:Python-Project
Version	:0.0.1
@author	:macrobull

"""


import pygame
import sys, serial, time
import re

from macrobull.misc import serialChecker


def draw(data):
	for i in range(h):
		for j in range(w):
			#print i,j
			b0 = ord(data[2*(i*w+j)])
			b1 = ord(data[2*(i*w+j)+1])
			#rgb = (b0 >> 3, ((b0 & 7)<<3)+(b1 >> 5), b1 & 0x1f)
			rgb = (b0 & 7, (((b0 & 7)<<3)+(b1 >> 5))<<2, (b1 & 0x1f)<<3)
			#rgb = (0, 0, b1 & 0x1f)
			screen.set_at((j,i), rgb)
	pygame.display.flip()


intv = 0.5
dev = serialChecker()


ser = serial.Serial(dev, 9600)
ser.flush()
ser.flushInput()
ser.flushOutput()
ser.close()


ser = serial.Serial(dev, 115200, timeout=intv)
print "dev={} baudrate={}".format(dev, ser.getBaudrate())

buff=''
flag = False
w = 320
h = 240
LEN = w*h*2
rl = 40

screen = pygame.display.set_mode((w,h))
clock = pygame.time.Clock()

try:
	while 1:
		wait=ser.inWaiting()
		if wait:
			s=ser.read(rl)
			buff+=s
			if flag:
				l = len(buff)
				if l>=LEN:
					data = buff[:LEN]
					draw(data)
					buff = buff[LEN:]
					flag = False
				else:
					if l % (rl*2) < rl:
						print l
			else:
				pos = buff.find("READY")
				if pos>=0:
					ser.write("{:03} {:03}".format(w,h))
					ser.flush()
					print buff[:pos+6],
					buff = buff[pos:]
					flag = True
				else:
					print s,
		else:
			time.sleep(intv)

#except (KeyboardInterrupt, SystemExit):
except BaseException,e:
	print(e)

ser.close()
print('Exited')





