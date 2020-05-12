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
#ifndef __TIMER_H
#define __TIMER_H
#include "HC89F303.h" 
/* Includes ------------------------------------------------------------------------------------------------*/
 
#define  key_up     0   //按键抬起
#define  key_down   1   //按键按下 

extern u8 a_code1, a_code2, a_code3, a_code4; //第一次遥控编码
extern u8 decode_ok;
extern u8 key_state;
extern u16 key_state_cnt;
extern u8 config_5s_flag;    //对码键的状态标志,1->进入配码状态,0->没进入配码状态
extern u8 config_15s_flag;
extern u16 timer1;
extern u8 wifi_work_state  ;  //1->未联网状态;0->联网状态
extern u8 time_1s_flag;

extern ux8 config_key2_status ;
extern u8 wifi_start_15s_flag; //wifi启动15s标志 
extern u8 buz_10ms_flag;  
extern u8 rf_key_status;  //1->遥控器有按键按下;0->遥控器无按键按下  
extern u8 key_pressed_20ms_flag;
extern u8 key_pressed_20ms_cnt;
/*****************************硬件I/O引脚定义,根据实际应用修改******************************/
 
void timer0_init(void); 
void timer1_init(void);        

//-------------------------------------------------------------------------------------------------------
#endif



