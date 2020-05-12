/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : Main.c
* Author             : Touch Team
* Version            : V1.0.5.0
* Date               : 2019/10/01
********************************************************************************/
//触摸调试 只要保证differ值和噪音值的差在50~100左右就可以
//蜂鸣器为4k,已调通
//2020/05/08 基本都调通了
//================================================================================
#define  ALLOCATE_EXTERN
#include "HC89F303.h"
#include "HC89F30x_SYS.h"
#include "HC89F30x_IO_INIT.h"
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Lib.h"
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Filter.h"
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Multibutton.h"
#include "HC89F30x_TouchUartDebug_Lib_V1.00\HC89F30x_TouchUartDebug_Lib_CFG.h"
#include "HC89F30x_TouchUartDebug_Lib_V1.00\HC89F30x_TouchUartDebug_Lib.h"



#include "key.h"
#include "timer.h"
#include "eeprom.h"
#include "buzzer.h"
//================================================================================
void  CheckKey(u16 key_flag);
void RF_code_match(void) ; //RF配对处理  接收按键码,并存出起来
void check_wifi_work_state(void);
void check_address_change(void);
void config_rf(void);
void RF_code_process(void);  //RF配对处理
void key_state_check(void);
void RF_LED_Flicker(void ); 
//ux8 test[]={0,1,2,3,4};
//ux8 test1[5]={0xff};
//ux8 test2[5]={0xff};

ux16 KEY_VALUE = 0;
u16 OLD_KEY = 0;


u8 KEY1,KEY2,KEY3; 
 

u8 last_key1_status = 0;    //上一次key1的状态
u8 last_key2_status = 0;    //上一次key2的状态
u8 last_key3_status = 0;    //上一次key3的状态

//u8 last_config_key1_status = 0;    //上一次配网key1的状态
//u8 last_config_key2_status = 0;    //上一次配网key2的状态
//u8 last_config_key3_status = 0;    //上一次配网key3的状态

ux8 Last_addr_high1 = 0;
ux8 Last_addr_low1  = 0;
ux8 Last_addr_high2 = 0;
ux8 Last_addr_low2  = 0;


ux8 write_eerpom_flag;  //往EEPROM写入的次数标志,每写入一次,该标志都取反

ux8 config_key2_status =0;

ux8 ADDR_BUF[20]={0} ;
ux8 addr_high1 ;
ux8 addr_low1 ; 
ux8 addr_high2 ;
ux8 addr_low2 ;
ux8 addr_high_temporary ;  //临时变量
ux8 addr_low_temporary ; 
ux8 Last_KEY1  = 0;
ux8 Last_KEY2  = 0;
ux8 Last_KEY3  = 0;

ux8 config_rf_flag = 0;   //配网标志为1时,把地址码写入eeprom;

ux8 led_flag;
ux8 receive_rf_flag;   //配对时接收到433按键码,该标志置一,此时接收板按下按键,该标志清零;15s内没有配码,该标志也清零
ux8 key_code;          //配对时接收到433按键码,码值临时存储在这个变量里面;15s内没有配码,该变量也清零
ux8 key_status_change_flag;  //1->key的状态发生了变化;0->key的状态没变化
 




void main()
{
	SystemInit();						//时钟初始化函数(默认Fosc=Fcpu=16M)
	IO_Init();
  timer0_init() ;
	timer1_init() ;
	eeprom_init(); 
	
//	Flash_ReadArr(EEPROM_ADDR,5,(u8*)test1);	//读取地址0x3C00所在扇区                     
//	Flash_EraseBlock(EEPROM_ADDR);			 //擦除地址0x3C00所在扇区
//	Flash_ReadArr(EEPROM_ADDR,5,(u8*)test1);
//	Flash_WriteArr(EEPROM_ADDR,5,(u8*)test);  //在地址0x3C00写入数据
//	Flash_ReadArr(EEPROM_ADDR,5,(u8*)test2);	//读取地址0x3C00所在扇区
  Flash_ReadArr(EEPROM_ADDR,8,(u8*)ADDR_BUF);
	addr_high1 = ADDR_BUF[1] ;
	addr_low1  = ADDR_BUF[2] ;
	addr_high2 = ADDR_BUF[3] ;
	addr_low2  = ADDR_BUF[4] ; 
	
  KEY1 = ADDR_BUF[5] ; 
	KEY2 = ADDR_BUF[6] ;
	KEY3 = ADDR_BUF[7] ;
	
	Last_addr_high1 = addr_high1;
  Last_addr_low1  = addr_low1;
  Last_addr_high2 = addr_high2;
  Last_addr_low2  = addr_low2;	
	
	Last_KEY1  = KEY1;
  Last_KEY2  = KEY2;
  Last_KEY3  = KEY3;	
	
	EA = 1;
	CTK_Init();							
#if TouchUartDebugLib_SW
	CTK_TouchUartDebug_Init();			//触摸串口调试初始化
#endif
	
	while(1)
	{
		if(OneCycleScanDone)
		{
			TouchRawDataFilter();		//RawData滤波函数，如需使能数据滤波，需在HC89F30x_GeneralKey_Touch_Filter.h中设置滤波深度，此函数不可删除
			Touch_Signal_Handle();
			TouchMultibuttonHandle();	//最强按键处理函数，如果大于等于两个按键同时有效，那么触摸信号最强的按键判断为有效，其他按键无效
			OneCycleScanDone = 0;

			#if TouchUartDebugLib_SW
				ECTK = 0; 							//触摸串口调试发送数据前，必需现关ECTK，后再打开
				CTK_TouchUartDebug();
				ECTK = 1;
			#endif

			if((TouchKeyFlag) != KEY_VALUE)
			{
				KEY_VALUE = TouchKeyFlag;	//获取新的按键值
				
			}
			else
			{
				
			}
		} 
		CheckKey(KEY_VALUE);
		RF_code_match() ; //RF配对处理  接收按键码,并存出起来				
	  RF_code_process();
		config_rf();
		check_address_change();
		check_wifi_work_state(); 
		
		CmdBuz() ;//蜂鸣器驱动
		key_state_check();    //检测遥控器按键是按下或者抬起		 加这个函数影响触摸 定时器优先级高于触摸的优先级
//		RF_LED_Flicker(); 
		
		
//		Check_Key();
	}
}



void  CheckKey(u16 key_flag)
{   
  
  if(key_flag != OLD_KEY) 
	{

		if((key_flag & 0x10) == K_1)
		{
			P3_5 = 0;
//			key_pressed_20ms_cnt = 0;
//		  key_pressed_20ms_flag= 0;
			
			if(receive_rf_flag == 1)
			{
				receive_rf_flag = 0;
			  config_rf_flag = 1;   //配网标志为1时,把地址码写入eeprom;			
				KEY1 = key_code  ;
			}
			
			SetupBz(M_BZ_KEY,1) ;//按下按键蜂鸣器短响1声 
		}
		else 
		{
//			 if(key_pressed_20ms_flag == 1) 
//		   {
			  P3_5 = 1;
//		   }
			
		}
		if((key_flag & 0x20) == K_2)
		{
			P2_4 = 0;
//			key_pressed_20ms_cnt = 0;
//		  key_pressed_20ms_flag= 0;
			if(receive_rf_flag == 1)
			{
				receive_rf_flag = 0;
			  config_rf_flag = 1;   //配网标志为1时,把地址码写入eeprom;			
				KEY2 = key_code  ;
			} 
			SetupBz(M_BZ_KEY,1) ;//按下按键蜂鸣器短响1声 
		}
		else 
		{
//			if(key_pressed_20ms_flag == 1) 
//			{
			  P2_4 = 1;
//			}
			
		}
		if((key_flag & 0x40) == K_3)
		{
			P0_2 = 0;
//			key_pressed_20ms_cnt = 0;
//		  key_pressed_20ms_flag= 0;
			if(receive_rf_flag == 1)
			{
				receive_rf_flag = 0;
			  config_rf_flag = 1;   //配网标志为1时,把地址码写入eeprom;			
				KEY3 = key_code  ;
			}  
			SetupBz(M_BZ_KEY,1) ;//按下按键蜂鸣器短响1声 
		}
		else 
		{
//			if(key_pressed_20ms_flag == 1) 
//			{
			  P0_2 = 1; 
//			}
			
		}
		OLD_KEY = key_flag;
	}
	 
	
}




/**********************************************
1. 0x60->KEY1 ; 
2. 0x61->KEY2 ; 
3. 0x62->KEY3 ; 
4.  
遥控接收处理函数
***********************************************/

void RF_code_process(void)  //RF配对处理
{
	
	   if(decode_ok==1)
		 {
			 decode_ok = 0;
 
			 if((a_code1==addr_high1&&a_code2==addr_low1)||(a_code1==addr_high2&&a_code2==addr_low2))
			 {			 
				 
				 if(a_code4 == KEY1)
				 {
						 if(last_key1_status == 0)
						 {
								 last_key1_status = 1;
								 key_1 = 0;	
								 SetupBz(M_BZ_KEY,1) ;//按下按键蜂鸣器短响1声 
						 }	 
				 }
				 
				 else if(a_code4 == KEY2)
				 {
						 if(last_key2_status == 0)
						 {
								 last_key2_status = 1;
								 key_2 = 0;	
 			           SetupBz(M_BZ_KEY,1) ;//按下按键蜂鸣器短响1声 							 
						 }	
				 }
				 
				 else if(a_code4 == KEY3) 
				 {
						 if(last_key3_status == 0)
						 {
								 last_key3_status = 1;
								 key_3 = 0;
							   SetupBz(M_BZ_KEY,1) ;//按下按键蜂鸣器短响1声 
						 }		 
				 }
	 
				
			 }
	 }

}


void RF_code_match(void)  //RF配对处理  接收按键码,并存出起来
{
//    if(wifi_work_state ==1)
//		{
			 
					switch(a_code4)
					{
						 case 0x62:     //0x62->key1 
							 receive_rf_flag = 1;
						   key_code = 0x62;
						   addr_high_temporary = a_code1 ;
							 addr_low_temporary  = a_code2 ;  
//						 P3_5 = 0;
//						 P2_4 = 0;
//						 P0_2 = 0; 
							break;

						 case 0x61:    //0x61->key2		
							 receive_rf_flag = 1;
						   key_code = 0x61	;	
							 addr_high_temporary = a_code1 ;
							 addr_low_temporary  = a_code2 ;  
//						 P3_5 = 1;
//						 P2_4 = 1;
//						 P0_2 = 1; 
							break;

						 case 0x60:    //0x60->key3
							 receive_rf_flag = 1;
						   key_code = 0x60;
						   addr_high_temporary = a_code1 ;
							 addr_low_temporary  = a_code2 ;
						 				
							break;
						 
						 default:
								
								break;
					}
				 
//		}

}
 

	

/************************************************************
无线配对:首先保证wifi模块处于配对状态,然后长按随意贴的任意键
持续5s后,RF配对指示灯(红灯)闪烁,在红灯闪烁的15s内再按开关的任
意键,这时配对指示灯(红灯)灭,配对成功;如果一次没成功,重复这一
过程.
************************************************************/
void config_rf(void)
{
	
	
	if(config_rf_flag == 1)
	{
		config_rf_flag =0;
 
		if(ADDR_BUF[1] == addr_high_temporary && ADDR_BUF[2] == addr_low_temporary)  //
		{
			 addr_high1 = addr_high_temporary ;
			 addr_low1  = addr_low_temporary ;
			 
		   ADDR_BUF[1] = addr_high_temporary;
			 ADDR_BUF[2] = addr_low_temporary;
		}
		else
		{
			if(ADDR_BUF[3] == addr_high_temporary && ADDR_BUF[4] == addr_low_temporary)
		  {
				addr_high2 = addr_high_temporary ;
			  addr_low2  = addr_low_temporary ;
			  ADDR_BUF[3] = addr_high_temporary;
			  ADDR_BUF[4] = addr_low_temporary;
			}
			else
			{
				addr_high1 = addr_high_temporary ;
			  addr_low1  = addr_low_temporary ;
				
			  ADDR_BUF[1] = addr_high_temporary;
			  ADDR_BUF[2] = addr_low_temporary;
				
				
			}
		}
		
		
		
    ADDR_BUF[5] = KEY1;
		ADDR_BUF[6] = KEY2;
		ADDR_BUF[7] = KEY3;
	}
}

void check_address_change(void)
{
	
	if((Last_addr_high1 != addr_high1)||(Last_addr_low1 != addr_low1)||(Last_addr_high2 != addr_high2)||(Last_addr_low2 != addr_low2)||(Last_KEY1 != KEY1)||(Last_KEY2 != KEY2)||(Last_KEY3 != KEY3))
	{	  

		 Last_addr_high1 = addr_high1;
     Last_addr_low1 = addr_low1;		
		 Last_addr_high2 = addr_high2;
     Last_addr_low2 = addr_low2;
		 Last_KEY1  = KEY1;
		 Last_KEY2  = KEY2;
		 Last_KEY3  = KEY3;
		  
//     EEPROM_SectorErase(EE_ADDRESS1); //扇区擦除
//     EEPROM_write_n(EE_ADDRESS1, ADDR_BUF, 8);  //写数据	
//     EEPROM_read_n(EE_ADDRESS1, ADDR_BUF, 8);	
 	  
		Flash_EraseBlock(EEPROM_ADDR);			 //擦除地址0x3C00所在扇区
		Flash_WriteArr(EEPROM_ADDR,8,(u8*)ADDR_BUF);  //在地址0x3C00写入数据
	  Flash_ReadArr(EEPROM_ADDR,8,(u8*)ADDR_BUF);

	}
		 		 
}


void key_status_up(void)
{
	key_1 = 1;  // 按键抬起
	key_2 = 1;
	key_3 = 1;
}

void key_state_check(void)
{
	static u8 Last_key_state=0;
	if(Last_key_state != key_state)
	{	  
		 Last_key_state = key_state;	
     key_status_change_flag = 1;	  
		 key_state_cnt = 0;				 
	}
	if(key_status_change_flag == 1)
	{
		if((key_state==key_up)&&(key_state_cnt>=50))//按键状态是抬起,且持续50ms
		{
			last_key1_status = 0;    //上一次key1的状态  按键抬起状态
			last_key2_status = 0;    //上一次key2的状态  按键抬起状态
			last_key3_status = 0;    //上一次key3的状态  按键抬起状态			
			key_status_up();
			
			key_status_change_flag = 0;
		}	
	}
} 


/*******************************************************************
1.检测wifi是否联网?wifi_work_state = 1;  //1->未联网状态;0->联网状态

*******************************************************************/
 u8 last_wifi_work_state=0;
void check_wifi_work_state(void)
{
  
  if(last_wifi_work_state != wifi_work_state)
	{	  
		 last_wifi_work_state = wifi_work_state;
		 if(wifi_start_15s_flag == 1) //wifi启动15s标志
		 {
			 if(wifi_work_state == 1)
			 {
				 EA = 0;
				 Flash_EraseBlock(EEPROM_ADDR);
 				 EA = 1; 
			 }	
     }		 
		  		 
	}

}

//配网指示灯闪烁(红灯)
//void RF_LED_Flicker(void) 
//{
//// 				 P3_5 = 0;
////				 P2_4 = 0;
////				 P0_2 = 0; 
////	  static u8 Color = 0;
////	  static u8 i = 0;
//		if(config_key == 1)
//		{
//				if(timer1 == 0)
//				{
//						timer1 = 200;  //闪烁时间
////						Color = !Color;
//						if (timer1==200)
//						{
//							 P3_5 = 0;
//							 P2_4 = 0;
//							 P0_2 = 0; 				 
//						}
//						else if (timer1==1)
//						{
//							 P3_5 = 0;
//							 P2_4 = 0;
//							 P0_2 = 0; 	
//							 config_key = 0;
//						}
//						 
//				}			
//		}
//		 
//}	

















































/*********************************END OF FILE************************************/
/******************* (C) COPYRIGHT 2009~2019 holychip ***************************/
