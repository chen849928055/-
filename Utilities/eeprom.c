/**
*   ************************************************************************************
*								上海芯圣电子股份有限公司
*								    www.holychip.cn
*	************************************************************************************
*	@Examle Version		V1.0.2.0
*	@Demo	Version		V1.0.2.0
*	@Date				2019.7.30
*	************************************************************************************
*									 模块性能介绍
*	1、Flash擦写次数10万次以上
*	2、扇区擦除时间约5ms，且擦除时不响应任何中断，但会置相关标志位，擦除完成后响应
*	3、可设置应用程序读保护，应用程序写保护（以4K字节为保护单位）
*	4、可以设置仿真器扇区读保护，扇区写保护（以4K字节为保护单位）
*	5、设置保护后无法擦写程序，读取的数据全为零
*   6、每一颗MCU在出厂时会固化一个CHIP_ID，一共8个字节，一颗芯片一个ID，不会重复
*	************************************************************************************
*									 应用注意事项
*	1、Fcpu需要配置为1-16MHz之间的正整数，且Flash擦写之前需要配置FREQ_CLK寄存器，该寄存器
*	   值即为当前CPU时钟频率。当CPU时钟频率低于1MHz时，不能进行Flash的IAP擦写操作。
*	2、扇区擦除写入过程中不能被打断
*	3、数据存放地址需要在程序存放地址之后
*   4、Flsah操作最低电压限制为2.0V，所以建议进行Flash操作前进行电压检测或者打开BOR，BOR电
*      压建议设置为2.4V及2.4V以上
*	5、建议在进行Flash擦写操作前关闭中断，擦写完成后再打开中断
*	6、必须先擦除后再写
*	************************************************************************************
*  								       客户服务
*	感谢您使用我们的单片机，若发现错误或对函数的使用存在疑问。请添加上海芯圣电子官方QQ群
*	****************************技术支持群：201030494***********************************
*   ************************************************************************************
**/

 
#include "eeprom.h"



void Flash_EraseBlock(unsigned int fui_Address);//扇区擦除
void FLASH_WriteData(unsigned char fui_Address, unsigned int fuc_SaveData);//写入一个数据
void Flash_WriteArr(unsigned int fui_Address,unsigned char fuc_Length,unsigned char *fucp_SaveArr);//写入任意长度数据
void Flash_ReadArr(unsigned int fui_Address,unsigned char fuc_Length,unsigned char *fucp_SaveArr);//读取任意长度数据

unsigned char guc_num = 0;
/***************************************************************************************
  * @实现效果	通过串口工具发送地址0x3C00处1个数据，掉电后再上电，串口发送上个数据加1，实现掉电存储数据
  * @操作步骤   接上RXD TXD短路帽，通过串口工具，上位机界面接收到数据。
***************************************************************************************/
void eeprom_init(void) 
{

/**********************************Flash配置初始化*************************************/
	FREQ_CLK = 0x10;					//指明当前系统时钟
//	Flash_ReadArr(EEPROM_ADDR,1,&guc_num);	//读取地址0x3C00所在扇区
//  guc_num++;                              //数据加1
//	Flash_EraseBlock(EEPROM_ADDR);			 //擦除地址0x3C00所在扇区
//	Flash_WriteArr(EEPROM_ADDR,1,&guc_num);  //在地址0x3C00写入数据
	
 
}
	
/**
  * @说明  	扇区擦除，约消耗5ms的时间
  * @参数  	fui_Address ：被擦除的扇区内的任意一个地址
  * @返回值 无
  * @注		只要操作扇区里面的任意一个地址，就可以擦除此扇区
  */
#pragma disable							//确保调整时不会进中断导致调整失败
void Flash_EraseBlock(unsigned int fui_Address)
{
	IAP_CMD = 0xF00F;					//Flash解锁
	IAP_ADDR = fui_Address;				//写入擦除地址
	IAP_CMD = 0xD22D;					//选择操作方式， 扇区擦除
	IAP_CMD = 0xE11E; 					//触发后IAP_ADDRL&IAP_ADDRH指向0xFF，同时自动锁定
}

/**
  * @说明  	写入一个字节数据到Flash里面
  * @参数  	fui_Address ：FLASH地址
  *	@参数	fucp_SaveData：写入的数据
  * @返回值 无
  * @注		写之前必须先对操作的扇区进行擦除
  */
#pragma disable							//确保调整时不会进中断导致调整失败
void FLASH_WriteData(unsigned char fuc_SaveData, unsigned int fui_Address)
{
	IAP_DATA = fuc_SaveData;
	IAP_CMD=0xF00F;					//Flash解锁
	IAP_ADDR = fui_Address;
	IAP_CMD=0xB44B;					//字节编程
	IAP_CMD=0xE11E;					//触发一次操作
}

/**
  * @说明  	写入任意长度的数据到FLASH里面
  * @参数  	fui_Address ：FLASH起始地址
  *	@参数	fuc_Length ： 写入数据长度
  *			取值范围：0x00-0xFF
  *	@参数	*fucp_SaveArr：写入的数据存放区域的首地址
  * @返回值 无
  * @注		写之前必须先对操作的扇区进行擦除
  */
#pragma disable						//确保调整时不会进中断导致调整失败
void Flash_WriteArr(unsigned int fui_Address,unsigned char fuc_Length,unsigned char *fucp_SaveArr)
{
	unsigned char fui_i = 0;
	for(fui_i=0;fui_i<fuc_Length;fui_i++)
	{
		FLASH_WriteData(*(fucp_SaveArr++), fui_Address++); 
	}
}

/**
  * @说明  	从FLASH里面读取任意长度的数据
  * @参数  	fui_Address ：FLASH起始地址
  *	@参数	fuc_Length ：读取数据长度
  *			取值范围：0x00-0xFF
  *	@参数	*fucp_SaveArr：读取数据存放的区域首地址
  * @返回值 无
  * @注		无
  */
void Flash_ReadArr(unsigned int fui_Address,unsigned char fuc_Length,unsigned char *fucp_SaveArr)
{
	while(fuc_Length--)
	*(fucp_SaveArr++)=*((unsigned char code *)(fui_Address++));//读取数据
}
 
      
 




















