/***************************************************************************
* ���������ĳ�ʼ�����书�ܺ���
*
* �� ��: key.h
* �� ��: CJW
* ˵ �������������ĳ�ʼ�����书�ܺ���
* ��дʱ��: 2016.7.20
* �� ����1.0
* �޸����ڣ� ��
 
*---------------------------------------------------------------------------
* ע: //00��ʾû�а���
			//01��ʾ����1
			//02��ʾ����2
			//04��ʾ����3
			//08��ʾ����4
			//10��ʾ����5 
*****************************************************************************/
#ifndef __EEPROM_H
#define __EEPROM_H
#include "HC89F303.h" 
/* Includes ------------------------------------------------------------------------------------------------*/
 
 
 #define EEPROM_ADDR 0X3C00  //��ַ 
      
/*****************************Ӳ��I/O���Ŷ���,����ʵ��Ӧ���޸�******************************/
 

void eeprom_init(void) ;      
void Flash_EraseBlock(unsigned int fui_Address);
void FLASH_WriteData(unsigned char fuc_SaveData, unsigned int fui_Address);
void Flash_WriteArr(unsigned int fui_Address,unsigned char fuc_Length,unsigned char *fucp_SaveArr);
void Flash_ReadArr(unsigned int fui_Address,unsigned char fuc_Length,unsigned char *fucp_SaveArr);
//-------------------------------------------------------------------------------------------------------
#endif



