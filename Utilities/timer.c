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
*	1��MCU�Ķ�ʱ��0��1�������ֹ�����ʽ
*	   ��ʽ0��16λ�Զ���װ��ʱ��/������
*	   ��ʽ1��16λ��ʱ��/������
*	   ��ʽ2��8λ�Զ���װ��ʱ��/������
*	   ��ʽ3��T0�ֳ�������TL0/TH0��������8λ��ʱ��/��������T1�޴�ģʽ��
*	************************************************************************************
*									 Ӧ��ע������
*	1����ʽ3ʱT0ռ��T1��TR1��TF1���ж�Դ������TR1��T0ռ�ã���ʱ��Ҫ�ر�T1�ɽ�T1��Ϊ����
*	   ��ʽ3
*	2���ڷ�ʽ0��Mode0��ʱTHx(x = 0,1)��TLx(x = 0,1)��д������ѭ�ȸ�λ���λ���������޸�
*	   ��������ʱ����λ�������޸ı䣬ֻҪ��λ���޸ģ���λ��������д��һ�Σ���ʽ 1��2��3
*	   ʱ�޴�Ҫ��
*	************************************************************************************
*  								       �ͻ�����
*	��л��ʹ�����ǵĵ�Ƭ���������ִ����Ժ�����ʹ�ô������ʡ�������Ϻ�оʥ���ӹٷ�QQȺ
*	****************************����֧��Ⱥ��201030494***********************************
*   ************************************************************************************
**/

#include "timer.h" 
#include "key.h" 
#include "buzzer.h" 

#define  key_up     0   //��������
#define  key_down   1   //�������� 
//sbit DO = P5^5;	    //433���ݽ���IO
 extern ux16 KEY_VALUE ;
//u8 RF ;	    //433���ݽ���IO
 
 
u8 a_code1, a_code2, a_code3, a_code4; //��һ��ң�ر���
u8 rf_ok1;//��һ��ң�ر��븳ֵ�ɹ�
u8 b_code1, b_code2, b_code3, b_code4; //�ڶ���ң�ر���
u8 rf_ok2;//�ڶ���ң�ر��븳ֵ�ɹ�
u8 t_code1, t_code2, t_code3, t_code4; //��ʱң�ر���
u8 last_state;//��һ�����룬0Ϊ�ͣ�1Ϊ��
u16 hh_w,ll_w;//�ߵ͵�ƽ���
u8 flag_syn;//ͬ�����־λ����1��ʾ�Ѿ��յ�ͬ���룬��0��ʾδ�յ�ͬ����
u8 rf_data[4]; //����յ���ң�ر���
u8  ma_x;                //���յ��ڼ�λ����
u16 s; // �յ���һ����͵ڶ�����֮�䲻�ܳ���s������
u8 rf_ok=1;
u8 decode_ok=0;

u8 key_state;
u16 key_state_cnt;
u8 config_key2_cnt = 0;   //������������
u8 config_5s_flag = 0;    //�������״̬��־,1->��������״̬,0->û��������״̬
u8 config_rf_15s_cnt;
u8 config_15s_flag;
u16 time_1s_cnt;
u8 time_3s_cnt;
u8 wifi_work_state = 1;  //1->δ����״̬;0->����״̬
u16 timer1;

u8 wifi_start_15s_flag=0; //wifi����15s��־
u8 wifi_start_15s_cnt=0;
u8 time_1s_flag;

u16 wifi_high_cnt;
u16 wifi_low_cnt;

u8 buz_250us_cnt;
u8 buz_10ms_cnt;
u8 buz_10ms_flag;  //�����������������б�־,1����,0������;
u8 rf_key_status;  //1->ң�����а�������;0->ң�����ް�������

u8 key_pressed_20ms_flag;
u8 key_pressed_20ms_cnt;
/***************************************************************************************
  * @ʵ��Ч��	T0��ʱ1ms��ÿ��һ���жϣ�P03��תһ��
***************************************************************************************/
void timer0_init(void) 
{
/**********************************TIM0���ó�ʼ��**************************************/
	TCON1 = 0x00;						//Tx0��ʱ��ʱ��ΪFosc
	TMOD = 0x00;						//16λ��װ�ض�ʱ��/������

	//Tim0����ʱ�� 	= (65536 - 0xFACB) * (1 / (Fosc /Timer��Ƶϵ��))
	//				= 1333 / (16000000 / 12)
	//				= 1 ms

	//��ʱ1ms
	//���Ƴ�ֵ 	= 65536 - ((1/1000) / (1/(Fosc / Timer��Ƶϵ��)))
	//		   	= 65536 - ((1/1000) / (1/(16000000 / 12)))
	//			= 65536 - 1333
	//			= 0xFACB
	
	TH0 = 0xFA;
	TL0 = 0xCB;							//T0��ʱʱ��1ms
	IE |= 0x02;							//��T0�ж�
	TCON |= 0x10;						//ʹ��T0
    
	 
	 
}

/***************************************************************************************
  * @˵��  	T0�жϷ�����
  *	@����	��
  * @����ֵ ��
  * @ע		��
***************************************************************************************/
void TIMER0_Rpt(void) interrupt TIMER0_VECTOR
{
    key_state_cnt++;    //����̧�������
	  if(timer1 >0) timer1--;
	 /*********************10ms��*********************/
	  if(++buz_10ms_cnt>10 ) 
		{
			buz_10ms_cnt = 0;
		  buz_10ms_flag= 1;
		}
		 /*********************20ms��*********************/
	  if(++key_pressed_20ms_cnt>50 ) 
		{
			key_pressed_20ms_cnt = 0;
		  key_pressed_20ms_flag= 1;
		}
	 /*******************3��ʱ�䵽*******************/	
		if(P2_1==0)
		{
			  wifi_high_cnt = 0;
			
				if(++wifi_low_cnt>=3000)
				{
					wifi_low_cnt = 3000;  //�͵�ƽ����ʱ�����3000ms
					wifi_work_state = 0;  //����״̬
				}
				
		}
		else
		{
				wifi_low_cnt = 0;
				
				if(++wifi_high_cnt<=2000)//�ߵ�ƽ����ʱ�����2000ms
				{
						   
						wifi_work_state = 1;  //δ����״̬
				}
			
		 }
	
	
	  /******************1��ʱ�䵽*******************/
		if(++time_1s_cnt>1000)
		{
				time_1s_cnt = 0;
		
			  time_1s_flag = 1;
			
			
			 /*******************5��ʱ�䵽*******************/	
        if(config_key2_status == key_down) //���ⰴ������5s
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
        /*******************15��ʱ�䵽*******************/	
				
				if(++config_rf_15s_cnt >= 15)
				{
					 config_rf_15s_cnt = 0;
					
					 receive_rf_flag = 0;
					 key_code = 0x00; 
				}
				
				/*************************��������15s***************************/
				if(++wifi_start_15s_cnt>=15)
				{
				  wifi_start_15s_flag = 1; //wifi����15s��־
				}
				
		}
}

/***************************************************************************************
  * @ʵ��Ч��	T0��ʱ50us��ÿ��һ���жϣ� 
***************************************************************************************/
void timer1_init(void) 
{
	/**********************************TIM1���ó�ʼ��**************************************/
	TCON1 = 0x00;						//T1��ʱ��ʱ��ΪFosc
	TMOD = 0x00;						//16λ��װ�ض�ʱ��/������

	//Tim1����ʱ�� 	= (65536 - 0xFACB) * (1 / (Fosc /Timer��Ƶϵ��))
	//				= 1333 / (16000000 / 12)
	//				= 1 ms

	//��ʱ1ms
	//���Ƴ�ֵ 	= 65536 - ((50/1000000) / (1/(Fosc / Timer��Ƶϵ��)))
	//		   	= 65536 - ((50/1000000) / (1/(16000000 / 12)))
	//			= 65536 - 67
	//			= 0xFFBD
	
	TH1 = 0xFF;
	TL1 = 0xBD;
	IE |= 0x08;							//��T1�ж�
	TCON |= 0x40;						//ʹ��T1
	 


}
/***************************************************************************************
  * @˵��  	T1�жϷ�����
  *	@����	��
  * @����ֵ ��
  * @ע		��
***************************************************************************************/
void TIMER1_Rpt(void) interrupt TIMER1_VECTOR
{
   	#if  1
	 
	      if(F_Buz==1)
				{
					if(++buz_250us_cnt>=5)
					{
						buz_250us_cnt = 0;
					  BUZ_FLIPS ; //BUZ ȡ�� �����ԴBUZ -- 4K	
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
				
				
	
	      //���յ��͵�ƽ��ll_w�Լӣ���һ״̬��Ϊ�͵�ƽ
        if (!P2_3)
				{ 
            ll_w++;                         
            last_state = 0;
	          
        }    
	      //���յ��ߵ�ƽ��hh_w�Լ�
	      //���е�ͬ�������һλ��ÿ����������һλ�����ɵͱ�Ϊ�ߵġ�
        else 
				{ 
 
            hh_w++;
	          //�����һ״̬Ϊ�͵�ƽ�����ɵͱ�Ϊ�ߵ�������	
            if (!last_state)  
            {   
	 
	              //���δ���յ�ͬ���룬�ж�ͬ����Ŀ�ʼʱ��
								if (((hh_w>=4)&&(hh_w<=6))&&((ll_w>=150)&&(ll_w<=320)))  //7.5ms��10.5ms
								{ 
                    flag_syn = 1 ;
                    ma_x = 0;
                    t_code1=0; 
									  t_code2=0;
										t_code3=0;									
									  t_code4=0; //��ʼ�� 
									
									
									 
	 								
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
															rf_ok1=1;        // ���Խ����� 
															s=1000;          //50ms �ڽ��յĵڶ�֡���ݺ͵�һ֡������ͬ˵�����ճɹ�

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
                 else  //û�а�������
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
              last_state=1;  //��¼���ε�ƽ״̬
		 					 
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
				if((a_code1==b_code1)&&(a_code2==b_code2)&&(a_code4==b_code4)) // a_code3����0xff 0x00���ر�õ�
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
  
      
 




















