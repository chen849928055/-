/**
*   ************************************************************************************
*								�Ϻ�оʥ���ӹɷ����޹�˾
*								    www.holychip.cn
*	************************************************************************************
*	@Examle Version		V1.0.2.0
*	@Demo	Version		V1.0.2.0
*	@Date				2019.7.30
*	************************************************************************************
*									 ģ�����ܽ���
*	1��Flash��д����10�������
*	2����������ʱ��Լ5ms���Ҳ���ʱ����Ӧ�κ��жϣ���������ر�־λ��������ɺ���Ӧ
*	3��������Ӧ�ó����������Ӧ�ó���д��������4K�ֽ�Ϊ������λ��
*	4���������÷���������������������д��������4K�ֽ�Ϊ������λ��
*	5�����ñ������޷���д���򣬶�ȡ������ȫΪ��
*   6��ÿһ��MCU�ڳ���ʱ��̻�һ��CHIP_ID��һ��8���ֽڣ�һ��оƬһ��ID�������ظ�
*	************************************************************************************
*									 Ӧ��ע������
*	1��Fcpu��Ҫ����Ϊ1-16MHz֮�������������Flash��д֮ǰ��Ҫ����FREQ_CLK�Ĵ������üĴ���
*	   ֵ��Ϊ��ǰCPUʱ��Ƶ�ʡ���CPUʱ��Ƶ�ʵ���1MHzʱ�����ܽ���Flash��IAP��д������
*	2����������д������в��ܱ����
*	3�����ݴ�ŵ�ַ��Ҫ�ڳ����ŵ�ַ֮��
*   4��Flsah������͵�ѹ����Ϊ2.0V�����Խ������Flash����ǰ���е�ѹ�����ߴ�BOR��BOR��
*      ѹ��������Ϊ2.4V��2.4V����
*	5�������ڽ���Flash��д����ǰ�ر��жϣ���д��ɺ��ٴ��ж�
*	6�������Ȳ�������д
*	************************************************************************************
*  								       �ͻ�����
*	��л��ʹ�����ǵĵ�Ƭ���������ִ����Ժ�����ʹ�ô������ʡ�������Ϻ�оʥ���ӹٷ�QQȺ
*	****************************����֧��Ⱥ��201030494***********************************
*   ************************************************************************************
**/

 
#include "eeprom.h"



void Flash_EraseBlock(unsigned int fui_Address);//��������
void FLASH_WriteData(unsigned char fui_Address, unsigned int fuc_SaveData);//д��һ������
void Flash_WriteArr(unsigned int fui_Address,unsigned char fuc_Length,unsigned char *fucp_SaveArr);//д�����ⳤ������
void Flash_ReadArr(unsigned int fui_Address,unsigned char fuc_Length,unsigned char *fucp_SaveArr);//��ȡ���ⳤ������

unsigned char guc_num = 0;
/***************************************************************************************
  * @ʵ��Ч��	ͨ�����ڹ��߷��͵�ַ0x3C00��1�����ݣ���������ϵ磬���ڷ����ϸ����ݼ�1��ʵ�ֵ���洢����
  * @��������   ����RXD TXD��·ñ��ͨ�����ڹ��ߣ���λ��������յ����ݡ�
***************************************************************************************/
void eeprom_init(void) 
{

/**********************************Flash���ó�ʼ��*************************************/
	FREQ_CLK = 0x10;					//ָ����ǰϵͳʱ��
//	Flash_ReadArr(EEPROM_ADDR,1,&guc_num);	//��ȡ��ַ0x3C00��������
//  guc_num++;                              //���ݼ�1
//	Flash_EraseBlock(EEPROM_ADDR);			 //������ַ0x3C00��������
//	Flash_WriteArr(EEPROM_ADDR,1,&guc_num);  //�ڵ�ַ0x3C00д������
	
 
}
	
/**
  * @˵��  	����������Լ����5ms��ʱ��
  * @����  	fui_Address ���������������ڵ�����һ����ַ
  * @����ֵ ��
  * @ע		ֻҪ�����������������һ����ַ���Ϳ��Բ���������
  */
#pragma disable							//ȷ������ʱ������жϵ��µ���ʧ��
void Flash_EraseBlock(unsigned int fui_Address)
{
	IAP_CMD = 0xF00F;					//Flash����
	IAP_ADDR = fui_Address;				//д�������ַ
	IAP_CMD = 0xD22D;					//ѡ�������ʽ�� ��������
	IAP_CMD = 0xE11E; 					//������IAP_ADDRL&IAP_ADDRHָ��0xFF��ͬʱ�Զ�����
}

/**
  * @˵��  	д��һ���ֽ����ݵ�Flash����
  * @����  	fui_Address ��FLASH��ַ
  *	@����	fucp_SaveData��д�������
  * @����ֵ ��
  * @ע		д֮ǰ�����ȶԲ������������в���
  */
#pragma disable							//ȷ������ʱ������жϵ��µ���ʧ��
void FLASH_WriteData(unsigned char fuc_SaveData, unsigned int fui_Address)
{
	IAP_DATA = fuc_SaveData;
	IAP_CMD=0xF00F;					//Flash����
	IAP_ADDR = fui_Address;
	IAP_CMD=0xB44B;					//�ֽڱ��
	IAP_CMD=0xE11E;					//����һ�β���
}

/**
  * @˵��  	д�����ⳤ�ȵ����ݵ�FLASH����
  * @����  	fui_Address ��FLASH��ʼ��ַ
  *	@����	fuc_Length �� д�����ݳ���
  *			ȡֵ��Χ��0x00-0xFF
  *	@����	*fucp_SaveArr��д������ݴ��������׵�ַ
  * @����ֵ ��
  * @ע		д֮ǰ�����ȶԲ������������в���
  */
#pragma disable						//ȷ������ʱ������жϵ��µ���ʧ��
void Flash_WriteArr(unsigned int fui_Address,unsigned char fuc_Length,unsigned char *fucp_SaveArr)
{
	unsigned char fui_i = 0;
	for(fui_i=0;fui_i<fuc_Length;fui_i++)
	{
		FLASH_WriteData(*(fucp_SaveArr++), fui_Address++); 
	}
}

/**
  * @˵��  	��FLASH�����ȡ���ⳤ�ȵ�����
  * @����  	fui_Address ��FLASH��ʼ��ַ
  *	@����	fuc_Length ����ȡ���ݳ���
  *			ȡֵ��Χ��0x00-0xFF
  *	@����	*fucp_SaveArr����ȡ���ݴ�ŵ������׵�ַ
  * @����ֵ ��
  * @ע		��
  */
void Flash_ReadArr(unsigned int fui_Address,unsigned char fuc_Length,unsigned char *fucp_SaveArr)
{
	while(fuc_Length--)
	*(fucp_SaveArr++)=*((unsigned char code *)(fui_Address++));//��ȡ����
}
 
      
 




















