/*!
 * @file  DFRobot_TCS3400.h
 * @brief A library of color sensors
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      TangJie(jie.tang@dfrobot.com)
 * @version     V1.0.0
 * @date        2024-04-24
 * @url         https://github.com/DFRobot/DFRobot_TCS
 */
#ifndef _DFROBOT_TCS3400_H_
#define _DFROBOT_TCS3400_H_

#include "Arduino.h"
#include "DFRobot_TCS34.h"
#include "DFRobot_TCS34Publics.h"

#define TCS3400_ADDR 0X39 ///< TCS3400 device addr

#define RET_OK 0
#define RET_ERROR -1

class DFRobot_TCS3400:public DFRobot_TCS34
{
public:
  /**
   * @fn DFRobot_TCS3400
   * @brief TCS3400构造函数
   * @param pWire I2C对象
   * @param it 数据采集等待时间
   * @param gain 数据增益
  */
  DFRobot_TCS3400(TwoWire *pWire=&Wire, uint8_t I2C_addr = TCS3400_ADDR, eIntegrationTime_t it= TCS3400_INTEGRATIONTIME_2_78MS, eGain_t gain= TCS3400_GAIN_1X);
  
  /**
   * @fn begin 
   * @brief 初始化 tcs3400
   * @return 返回初始化状态
   * @retval RET_OK 成功
   * @retval RET_ERROR 失败
  */
  int8_t begin(void);

  /**
	 * @fn getRGBC
	 * @brief Reads the raw red, green, blue and clear channel values
	 * @param r  red.
	 * @param g  green.
	 * @param b  blue.
	 * @param c  color temperature
	 */
	void getRGBC(uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c);
};
#endif
