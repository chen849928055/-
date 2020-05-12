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
*	1、MCU的定时器0，1共有四种工作方式
*	   方式0：16位自动重装定时器/计数器
*	   方式1：16位定时器/计数器
*	   方式2：8位自动重装定时器/计数器
*	   方式3：T0分成两个（TL0/TH0）独立的8位定时器/计数器（T1无此模式）
*	************************************************************************************
*									 应用注意事项
*	1、方式3时T0占用T1的TR1、TF1及中断源，由于TR1被T0占用，此时需要关闭T1可将T1设为工作
*	   方式3
*	2、在方式0（Mode0）时THx(x = 0,1)和TLx(x = 0,1)读写操作遵循先高位后低位。并且在修改
*	   重载数据时，低位无论有无改变，只要高位被修改，低位都必须再写入一次，方式 1、2、3
*	   时无此要求
*	************************************************************************************
*  								       客户服务
*	感谢您使用我们的单片机，若发现错误或对函数的使用存在疑问。请添加上海芯圣电子官方QQ群
*	****************************技术支持群：201030494***********************************
*   ************************************************************************************
**/

#include "timer.h" 
#include "key.h" 
#include "buzzer.h" 

#define  key_up     0   //按键弹起
#define  key_down   1   //按键按下 
//sbit DO = P5^5;	    //433数据接收IO
 extern ux16 KEY_VALUE ;
//u8 RF ;	    //433数据接收IO
 
 
u8 a_code1, a_code2, a_code3, a_code4; //第一次遥控编码
u8 rf_ok1;//第一次遥控编码赋值成功
u8 b_code1, b_code2, b_code3, b_code4; //第二次遥控编码
u8 rf_ok2;//第二次遥控编码赋值成功
u8 t_code1, t_code2, t_code3, t_code4; //临时遥控编码
u8 last_state;//上一个编码，0为低，1为高
u16 hh_w,ll_w;//高低电平宽度
u8 flag_syn;//同步码标志位，置1表示已经收到同步码，置0表示未收到同步码
u8 rf_data[4]; //最后收到的遥控编码
u8  ma_x;                //接收到第几位编码
u16 s; // 收到第一个码和第二个码之间不能超过s个周期
u8 rf_ok=1;
u8 decode_ok=0;

u8 key_state;
u16 key_state_cnt;
u8 config_key2_cnt = 0;   //配网键计数器
u8 config_5s_flag = 0;    //对码键的状态标志,1->进入配码状态,0->没进入配码状态
u8 config_rf_15s_cnt;
u8 config_15s_flag;
u16 time_1s_cnt;
u8 time_3s_cnt;
u8 wifi_work_state = 1;  //1->未联网状态;0->联网状态
u16 timer1;

u8 wifi_start_15s_flag=0; //wifi启动15s标志
u8 wifi_start_15s_cnt=0;
u8 time_1s_flag;

u16 wifi_high_cnt;
u16 wifi_low_cnt;

u8 buz_250us_cnt;
u8 buz_10ms_cnt;
u8 buz_10ms_flag;  //蜂鸣器驱动函数运行标志,1运行,0不运行;
u8 rf_key_status;  //1->遥控器有按键按下;0->遥控器无按键按下

u8 key_pressed_20ms_flag;
u8 key_pressed_20ms_cnt;
/***************************************************************************************
  * @实现效果	T0定时1ms，每进一次中断，P03翻转一次
***************************************************************************************/
void timer0_init(void) 
{
/**********************************TIM0配置初始化**************************************/
	TCON1 = 0x00;						//Tx0定时器时钟为Fosc
	TMOD = 0x00;						//16位重装载定时器/计数器

	//Tim0计算时间 	= (65536 - 0xFACB) * (1 / (Fosc /Timer分频系数))
	//				= 1333 / (16000000 / 12)
	//				= 1 ms

	//定时1ms
	//反推初值 	= 65536 - ((1/1000) / (1/(Fosc / Timer分频系数)))
	//		   	= 65536 - ((1/1000) / (1/(16000000 / 12)))
	//			= 65536 - 1333
	//			= 0xFACB
	
	TH0 = 0xFA;
	TL0 = 0xCB;							//T0定时时间1ms
	IE |= 0x02;							//打开T0中断
	TCON |= 0x10;						//使能T0
    
	 
	 
}

/***************************************************************************************
  * @说明  	T0中断服务函数
  *	@参数	无
  * @返回值 无
  * @注		无
***************************************************************************************/
void TIMER0_Rpt(void) interrupt TIMER0_VECTOR
{
    key_state_cnt++;    //按键抬起计数器
	  if(timer1 >0) timer1--;
	 /*********************10ms到*********************/
	  if(++buz_10ms_cnt>10 ) 
		{
			buz_10ms_cnt = 0;
		  buz_10ms_flag= 1;
		}
		 /*********************20ms到*********************/
	  if(++key_pressed_20ms_cnt>50 ) 
		{
			key_pressed_20ms_cnt = 0;
		  key_pressed_20ms_flag= 1;
		}
	 /*******************3秒时间到*******************/	
		if(P2_1==0)
		{
			  wifi_high_cnt = 0;
			
				if(++wifi_low_cnt>=3000)
				{
					wifi_low_cnt = 3000;  //低电平持续时间大于3000ms
					wifi_work_state = 0;  //联网状态
				}
				
		}
		else
		{
				wifi_low_cnt = 0;
				
				if(++wifi_high_cnt<=2000)//高电平持续时间大于2000ms
				{
						   
						wifi_work_state = 1;  //未联网状态
				}
			
		 }
	
	
	  /******************1秒时间到*******************/
		if(++time_1s_cnt>1000)
		{
				time_1s_cnt = 0;
		
			  time_1s_flag = 1;
			
			
			 /*******************5秒时间到*******************/	
        if(config_key2_status == key_down) //任意按键按下5s
				{
					if(++config_key2_cnt>=5)
					{
						 config_key2_cnt = 0;
						 config_5s_flag  = 1;					  
					}
			  }
				else
				{
				     config_key2_cnt = 0 ;
				}
        /*******************15秒时间到*******************/	
				
				if(++config_rf_15s_cnt >= 15)
				{
					 config_rf_15s_cnt = 0;
					
					 receive_rf_flag = 0;
					 key_code = 0x00; 
				}
				
				/*************************开机启动15s***************************/
				if(++wifi_start_15s_cnt>=15)
				{
				  wifi_start_15s_flag = 1; //wifi启动15s标志
				}
				
		}
}

/***************************************************************************************
  * @实现效果	T0定时50us，每进一次中断， 
***************************************************************************************/
void timer1_init(void) 
{
	/**********************************TIM1配置初始化**************************************/
	TCON1 = 0x00;						//T1定时器时钟为Fosc
	TMOD = 0x00;						//16位重装载定时器/计数器

	//Tim1计算时间 	= (65536 - 0xFACB) * (1 / (Fosc /Timer分频系数))
	//				= 1333 / (16000000 / 12)
	//				= 1 ms

	//定时1ms
	//反推初值 	= 65536 - ((50/1000000) / (1/(Fosc / Timer分频系数)))
	//		   	= 65536 - ((50/1000000) / (1/(16000000 / 12)))
	//			= 65536 - 67
	//			= 0xFFBD
	
	TH1 = 0xFF;
	TL1 = 0xBD;
	IE |= 0x08;							//打开T1中断
	TCON |= 0x40;						//使能T1
	 


}
/***************************************************************************************
  * @说明  	T1中断服务函数
  *	@参数	无
  * @返回值 无
  * @注		无
***************************************************************************************/
void TIMER1_Rpt(void) interrupt TIMER1_VECTOR
{
   	#if  1
	 
	      if(F_Buz==1)
				{
					if(++buz_250us_cnt>=5)
					{
						buz_250us_cnt = 0;
					  BUZ_FLIPS ; //BUZ 取反 针对无源BUZ -- 4K	
					}
									 
				}
				else
				{
				  buz_250us_cnt = 0;
				}
	
//				if( KEY_VALUE !=0)
//				{
//				  return;
//				}
				
				
	
	      //接收到低电平，ll_w自加，上一状态设为低电平
        if (!P2_3)
				{ 
            ll_w++;                         
            last_state = 0;
	          
        }    
	      //接收到高电平，hh_w自加
	      //所有的同步码最后一位，每个编码的最后一位都是由低变为高的。
        else 
				{ 
 
            hh_w++;
	          //如果上一状态为低电平，即由低变为高的上升沿	
            if (!last_state)  
            {   
	 
	              //如果未接收到同步码，判断同步码的开始时刻
								if (((hh_w>=4)&&(hh_w<=6))&&((ll_w>=150)&&(ll_w<=320)))  //7.5ms到10.5ms
								{ 
                    flag_syn = 1 ;
                    ma_x = 0;
                    t_code1=0; 
									  t_code2=0;
										t_code3=0;									
									  t_code4=0; //初始化 
									
									
									 
	 								
                }
								else if (flag_syn == 1 && ma_x>=32)
								{   
 
                     
                 }  
                  else if ((flag_syn) ) 
									{ 
											
											 switch (ma_x)
											 { 
													 case 0 : {if((ll_w >= 4)&&(ll_w <= 6)) t_code1=t_code1 | 0x80;break;}	
													 case 1 : {if((ll_w >= 4)&&(ll_w <= 6)) t_code1=t_code1 | 0x40;break;}	
													 case 2 : {if((ll_w >= 4)&&(ll_w <= 6)) t_code1=t_code1 | 0x20;break;} 
													 case 3 : {if((ll_w >= 4)&&(ll_w <= 6)) t_code1=t_code1 | 0x10;break;}
													 case 4 : {if((ll_w >= 4)&&(ll_w <= 6)) t_code1=t_code1 | 0x08;break;} 
													 case 5 : {if((ll_w >= 4)&&(ll_w <= 6)) t_code1=t_code1 | 0x04;break;} 
													 case 6 : {if((ll_w >= 4)&&(ll_w <= 6)) t_code1=t_code1 | 0x02;break;} 
													 case 7 : {if((ll_w >= 4)&&(ll_w <= 6)) t_code1=t_code1 | 0x01;break;}
													 case 8 : {if((ll_w >= 4)&&(ll_w <= 6)) t_code2=t_code2 | 0x80;break;} 
													 case 9 : {if((ll_w >= 4)&&(ll_w <= 6)) t_code2=t_code2 | 0x40;break;} 
													 case 10: {if((ll_w >= 4)&&(ll_w <= 6)) t_code2=t_code2 | 0x20;break;}
													 case 11: {if((ll_w >= 4)&&(ll_w <= 6)) t_code2=t_code2 | 0x10;break;}
													 case 12: {if((ll_w >= 4)&&(ll_w <= 6)) t_code2=t_code2 | 0x08;break;}
													 case 13: {if((ll_w >= 4)&&(ll_w <= 6)) t_code2=t_code2 | 0x04;break;}
													 case 14: {if((ll_w >= 4)&&(ll_w <= 6)) t_code2=t_code2 | 0x02;break;} 
													 case 15: {if((ll_w >= 4)&&(ll_w <= 6)) t_code2=t_code2 | 0x01;break;} 
													 case 16: {if((ll_w >= 4)&&(ll_w <= 6)) t_code3=t_code3 | 0x80;break;}
													 case 17: {if((ll_w >= 4)&&(ll_w <= 6)) t_code3=t_code3 | 0x40;break;} 
													 case 18: {if((ll_w >= 4)&&(ll_w <= 6)) t_code3=t_code3 | 0x20;break;}
													 case 19: {if((ll_w >= 4)&&(ll_w <= 6)) t_code3=t_code3 | 0x10;break;} 
													 case 20: {if((ll_w >= 4)&&(ll_w <= 6)) t_code3=t_code3 | 0x08;break;} 
													 case 21: {if((ll_w >= 4)&&(ll_w <= 6)) t_code3=t_code3 | 0x04;break;}
													 case 22: {if((ll_w >= 4)&&(ll_w <= 6)) t_code3=t_code3 | 0x02;break;}
													 case 23: {if((ll_w >= 4)&&(ll_w <= 6)) t_code3=t_code3 | 0x01;break;}        
													 case 24: {if((ll_w >= 4)&&(ll_w <= 6)) t_code4=t_code4 | 0x80;break;} 
													 case 25: {if((ll_w >= 4)&&(ll_w <= 6)) t_code4=t_code4 | 0x40;break;} 
													 case 26: {if((ll_w >= 4)&&(ll_w <= 6)) t_code4=t_code4 | 0x20;break;}
													 case 27: {if((ll_w >= 4)&&(ll_w <= 6)) t_code4=t_code4 | 0x10;break;}  
													 case 28: {if((ll_w >= 4)&&(ll_w <= 6)) t_code4=t_code4 | 0x08;break;} 
													 case 29: {if((ll_w >= 4)&&(ll_w <= 6)) t_code4=t_code4 | 0x04;break;} 
													 case 30: {if((ll_w >= 4)&&(ll_w <= 6)) t_code4=t_code4 | 0x02;break;}
													 case 31: {if((ll_w >= 4)&&(ll_w <= 6)) t_code4=t_code4 | 0x01;break;}
		  										               
                        } 
											
                       
											ma_x++; 	 
											if(ma_x>=32)
											{
												 if(!rf_ok1)
												 {
															a_code4=t_code4;
															a_code3=t_code3;
															a_code2=t_code2;
															a_code1=t_code1;
															rf_ok1=1;        // 可以解码了 
															s=1000;          //50ms 内接收的第二帧数据和第一帧数据相同说明接收成功

															if(a_code4==0x60||a_code4==0x61||a_code4==0x62)
															{
																rf_key_status = 1;
																key_state = key_down;
																 
															}
															else
															{
																decode_ok=0;		
																rf_key_status = 1;																
																key_state = key_up;
																  
															}
														
													}
													else
													{
															b_code4=t_code4;
															b_code3=t_code3;
															b_code2=t_code2;
															b_code1=t_code1;
															rf_ok2=1; 
													}   
													flag_syn=0;
											
											 }
                 }
                 else  //没有按键按下
								 {
										ma_x=0; 
								    flag_syn=0;
									  t_code4=0;
								    t_code3=0;
								    t_code2=0; 
								    t_code1=0;

										a_code4=0;
										a_code3=0;
										a_code2=0;
										a_code1=0;
									
									  key_state = key_up;
									 rf_key_status = 1;
									  
									  config_key2_status = key_up;
								 } 
								 
                 ll_w=0;
								 hh_w=0; 
             }          
              last_state=1;  //记录本次电平状态
		 					 
				}
	  if(rf_ok1)  
		{
		 
			s--;
			if(!s) 
			{
				rf_ok1=0;
			}
			
			if(rf_ok2) 
			{
				if((a_code1==b_code1)&&(a_code2==b_code2)&&(a_code4==b_code4)) // a_code3总是0xff 0x00来回变幻的
				{
					rf_ok=1; 
          decode_ok=1;
					rf_key_status = 1;
					key_state = key_down;					
				}
				else
				{
					rf_ok=0;
					decode_ok=0;
				}
					rf_ok1=0;
					rf_ok2=0;
			}                   
		}
 
 #endif
} 
  
      
 




















