# -*- coding: utf-8 -*

from __future__ import print_function
import sys
import os
sys.path.append("../")
import time
from DFRobot_TCS34Publics import *
from DFRobot_TCS34 import DFRobot_TCS34

TCS3400_ADDR=0X39 #TCS3400 device addr

class DFRobot_TCS3400(DFRobot_TCS34):

  def __init__(self,bus = 1,addr=TCS3400_ADDR,int=TCS3400_INTEGRATIONTIME_27_8MS,gain=TCS3400_GAIN_1X):
      self.super_cls = self.get_super(DFRobot_TCS3400)
      self.super_cls.__init__(bus,addr,int,gain)

  def get_super(self,cls):
    if sys.version_info[0] == 2:
        return super(cls, self)
    elif sys.version_info[0] == 3:
        return super()
    
  def begin(self):
    if(self.super_cls.begin(TCS3400)):
      return 0
    return -1 
  

  def get_rgbc(self):
    c = self.super_cls.read_reg_word(self.TCS34_CDATAL)
    r = self.super_cls.read_reg_word(self.TCS34_RDATAL)
    g = self.super_cls.read_reg_word(self.TCS34_GDATAL)
    b = self.super_cls.read_reg_word(self.TCS34_BDATAL)
    if(self.tcs34_integration_time == TCS3400_INTEGRATIONTIME_2_78MS):
      time.sleep(0.003)
    elif(self.tcs34_integration_time == TCS3400_INTEGRATIONTIME_27_8MS):
      time.sleep(0.027)
    elif(self.tcs34_integration_time == TCS3400_INTEGRATIONTIME_103MS):
      time.sleep(0.103)
    elif(self.tcs34_integration_time == TCS3400_INTEGRATIONTIME_178MS):
      time.sleep(0.178)
    else:
      time.sleep(712)
    return r,g,b,c
    




