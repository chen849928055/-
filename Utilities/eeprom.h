/***************************************************************************
* 独立按键的初始化及其功能函数
*
* 文 件: key.h
* 作 者: CJW
* 说 明：独立按键的初始化及其功能函数
* 编写时间: 2016.7.20
* 版 本：1.0
* 修改日期： 无
 
*---------------------------------------------------------------------------
* 注: //00表示没有按键
			//01表示按键1
			//02表示按键2
			//04表示按键3
			//08表示按键4
			//10表示按键5 
*****************************************************************************/
#ifndef __EEPROM_H
#define __EEPROM_H
#include "HC89F303.h" 
/* Includes ------------------------------------------------------------------------------------------------*/
 
 
 #define EEPROM_ADDR 0X3C00  //地址 
      
/*****************************硬件I/O引脚定义,根据实际应用修改******************************/
 

void eeprom_init(void) ;      
void Flash_EraseBlock(unsigned int fui_Address);
void FLASH_WriteData(unsigned char fuc_SaveData, unsigned int fui_Address);
void Flash_WriteArr(unsigned int fui_Address,unsigned char fuc_Length,unsigned char *fucp_SaveArr);
void Flash_ReadArr(unsigned int fui_Address,unsigned char fuc_Length,unsigned char *fucp_SaveArr);
//-------------------------------------------------------------------------------------------------------
#endif



