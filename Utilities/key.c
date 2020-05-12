/***************************************************************************
*  独立按键的初始化及其功能函数
*
* 文 件: key.c
* 作 者: CJW
* 说 明：独立按键的初始化及其功能函数
* 编写时间: 2016.7.20
* 编译环境 : RealView MDK-ARM 4.73
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
#include "key.h"
#include "timer.h"
 

 

//按键初始化函数
/************** 按键初始化函数*******************************
* 说明: 按键初始化函数
* 入口参数:无
* 出口参数:无
* 注: key1->PD1  key2->PB9  keywakeup->PC15
***************************************************************/	
extern ux16 KEY_VALUE ;   
u8 Get_Key(void) //IO初始化
{
	u8 ReadKey=0;
		if (KEY_VALUE == 0x10) //Shift  K4
		{
			ReadKey |= K_1;
		}
		else
		{
			ReadKey &= ~K_1;
		}
		if (KEY_VALUE == 0x20) //Up     K3
		{
			ReadKey |= K_2;			
		}
		else
		{
			ReadKey &= ~K_2;			
		}
		if (KEY_VALUE == 0x40) //Down    K2
		{
			ReadKey |= K_3;
		}
		else
		{
			ReadKey &= ~K_3;
		}
		 
		return ReadKey;	   
		  
}
 
/********************************************************************************************
* eKEY ReadKey(void);
* 功能: 独立按键扫描,10ms扫描一次.
* 返回值:枚举类型,{NO_KEY,STOP,START,SEL,ADD,DEC,SETUP}. 
* 参数: 
********************************************************************************************/
 
unsigned int key_time = 0;                    // 长按键计时
 
u8 Read_Key(void)
{
        
        static unsigned char key_state = 0;                  // 记录按键扫当前描状态
        static unsigned char key_press_old = 0;              // 记录上一次按键状态
        static unsigned char key_value_old = K_NO ;          // 保存上一次按键返回值
        unsigned char key_return = K_NO;                     // 按键功能返回值
        unsigned char key_press;
        
        key_press = Get_Key();                               // 读按键I/O电平,只保留被按下的键(被按下的键位为1)
        switch (key_state)
        {
						case key_state_0:                                // 1.按键初始态
										if (key_press)
										{ 
														key_state = key_state_1;               // 键被按下,状态转换到按键确认态
														key_press_old = key_press;             // 保存当前按键状态
										}
										break;
						case key_state_1:                                        // 2.按键确认态
										if (key_press == key_press_old)                  // 与初始态的按键状态相同?
										{
											key_time = 0;                                  // 清零按键时间计数器
											switch(key_press)
											{
												case K_1:
																key_state  = key_state_2;                         // 转按键释放态
																key_return = K_1;                               // "+"键
																break;
												case K_2:
																key_state  = key_state_2;                         // 转按键释放态
																key_return = K_2;                               // "-"键                                                
																break;        
												case K_3:
																key_state  = key_state_2;                         // 转长按键态
																key_return = K_3;                             // "电源"键                                                                
																break;        
												case K_Back:
																key_state  = key_state_2;                         // 转长按键态
																key_return = K_Back;                            // "返回"键
																break;        
												case K_Enter:
																key_state  = key_state_2;                         // 转长按键态
																key_return = K_Enter;                             // "确认"键
																break;
												case K_1|K_2:                                        // "组合"键,长按键
																key_state  = key_state_2;                        // 组合键按键仍按下，状态转换到计时1
																break;  
 			
												default:
																key_state  = key_state_4;                         // 转按键释放态
																break;
											}
										}
										else if (!key_press)
												key_state = key_state_0;                                   // 按键已抬起(是干扰),转换到按键初始态
										else
														key_state = key_state_4;                               // 按键已发生变化,转到按键释放态 
														
										key_value_old = key_return;                                     // 保存按键返回值
										break;
						case key_state_2:                                                       // 3.长按键确认态
								   
										if (key_press == key_press_old) 
										{
 
												if (key_press == (K_1|K_2))                        // "配置"键
												{
													                                                     // 按键计时
														if(key_time >= MuxKeyTime)                         // 组合键长按计时
														{
															
															      key_return = (K_1|K_2);                // 组合键功能,"配置"键
																		key_state = key_state_4;                   // 按下时间>=MuxKeyTime,转到按键释放状态
																		 
														}
												}
											else if (key_press == K_Back)  
												{
													                                                    // 按键计时
														if(key_time>= OneKeyTime)                         // 单键长按计时
														{
															 
															      key_return = K_Long ;                     // 返回长按键的键值
																		key_state = key_state_4;                  // 按下时间>=OneKeyTime 																		                                       
 
														}
												}
												
												
 										else if(key_press == K_1||key_press == K_2)   
												{
													  
														if(key_time >= OneKeyTime2s )                     // 单键长按计时
														{
																		key_state = key_state_3;                  // 按下时间>=OneKeyTime,转到连发功能态,用于触发连发功能
																		key_time = 0;                                        // 清按键计数器
																		key_return = key_value_old;               // 返回上一次按键值
														}
													 
												}		
										}
										else
										{
														key_state = key_state_4;                           // 按键已发生变化,转到按键释放态
 
										}
										break;
						case key_state_3:                                                  // 4.按键连发功能
										if (key_press == key_press_old) 
										{
														if (++key_time >= RepeatTime)                      // 按键时间计数 
														{
																		key_time = 0;                              // 按下时间>=0.05s，清0按键计数器
																		key_return = key_value_old;                // 返回上一次按键值
														}                                
										}
										else
												key_state = key_state_4;                              // 按键已发生变化,转到按键释放态
										break;
						case key_state_4:                                                 // 5.等待所有按键释放开
										//if (!key_press)                                         // 等待所有按键释放,才进入一次新的按键确认过程
										if (key_press != key_press_old)                           // 按键发生变化,就进入一次新的确认过程
												key_state = key_state_0;                              // 按键已释放,转换到初始态.
										break;                        
        }        
    return key_return;
}




void  Check_Key(void)
{ 
//   if(wifi_work_state ==1)
//	 {	
				switch(Read_Key())
				{
					case K_1: // 
							config_rf_flag = 1;   //配网标志为1时,把地址码写入eeprom;
					
					    receive_rf_flag = 0;
						  KEY1 = key_code  ;
					
					P3_5 = !P3_5;
							break;
					
					case K_2: // 
							config_rf_flag = 1;   //配网标志为1时,把地址码写入eeprom;
					    receive_rf_flag = 0;
						  KEY2 = key_code  ;
							break;
					
					case K_3: // 
							config_rf_flag = 1;   //配网标志为1时,把地址码写入eeprom;
					
					    receive_rf_flag = 0;
						  KEY3 = key_code  ;
							break;
					
						
					
					case 0: //无按键按下
							break; 
					default:
							
						 break;
				}
//	 }	
			
}










