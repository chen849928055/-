/***************************************************************************
*  ���������ĳ�ʼ�����书�ܺ���
*
* �� ��: key.c
* �� ��: CJW
* ˵ �������������ĳ�ʼ�����书�ܺ���
* ��дʱ��: 2016.7.20
* ���뻷�� : RealView MDK-ARM 4.73
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
#include "key.h"
#include "timer.h"
 

 

//������ʼ������
/************** ������ʼ������*******************************
* ˵��: ������ʼ������
* ��ڲ���:��
* ���ڲ���:��
* ע: key1->PD1  key2->PB9  keywakeup->PC15
***************************************************************/	
extern ux16 KEY_VALUE ;   
u8 Get_Key(void) //IO��ʼ��
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
* ����: ��������ɨ��,10msɨ��һ��.
* ����ֵ:ö������,{NO_KEY,STOP,START,SEL,ADD,DEC,SETUP}. 
* ����: 
********************************************************************************************/
 
unsigned int key_time = 0;                    // ��������ʱ
 
u8 Read_Key(void)
{
        
        static unsigned char key_state = 0;                  // ��¼����ɨ��ǰ��״̬
        static unsigned char key_press_old = 0;              // ��¼��һ�ΰ���״̬
        static unsigned char key_value_old = K_NO ;          // ������һ�ΰ�������ֵ
        unsigned char key_return = K_NO;                     // �������ܷ���ֵ
        unsigned char key_press;
        
        key_press = Get_Key();                               // ������I/O��ƽ,ֻ���������µļ�(�����µļ�λΪ1)
        switch (key_state)
        {
						case key_state_0:                                // 1.������ʼ̬
										if (key_press)
										{ 
														key_state = key_state_1;               // ��������,״̬ת��������ȷ��̬
														key_press_old = key_press;             // ���浱ǰ����״̬
										}
										break;
						case key_state_1:                                        // 2.����ȷ��̬
										if (key_press == key_press_old)                  // ���ʼ̬�İ���״̬��ͬ?
										{
											key_time = 0;                                  // ���㰴��ʱ�������
											switch(key_press)
											{
												case K_1:
																key_state  = key_state_2;                         // ת�����ͷ�̬
																key_return = K_1;                               // "+"��
																break;
												case K_2:
																key_state  = key_state_2;                         // ת�����ͷ�̬
																key_return = K_2;                               // "-"��                                                
																break;        
												case K_3:
																key_state  = key_state_2;                         // ת������̬
																key_return = K_3;                             // "��Դ"��                                                                
																break;        
												case K_Back:
																key_state  = key_state_2;                         // ת������̬
																key_return = K_Back;                            // "����"��
																break;        
												case K_Enter:
																key_state  = key_state_2;                         // ת������̬
																key_return = K_Enter;                             // "ȷ��"��
																break;
												case K_1|K_2:                                        // "���"��,������
																key_state  = key_state_2;                        // ��ϼ������԰��£�״̬ת������ʱ1
																break;  
 			
												default:
																key_state  = key_state_4;                         // ת�����ͷ�̬
																break;
											}
										}
										else if (!key_press)
												key_state = key_state_0;                                   // ������̧��(�Ǹ���),ת����������ʼ̬
										else
														key_state = key_state_4;                               // �����ѷ����仯,ת�������ͷ�̬ 
														
										key_value_old = key_return;                                     // ���水������ֵ
										break;
						case key_state_2:                                                       // 3.������ȷ��̬
								   
										if (key_press == key_press_old) 
										{
 
												if (key_press == (K_1|K_2))                        // "����"��
												{
													                                                     // ������ʱ
														if(key_time >= MuxKeyTime)                         // ��ϼ�������ʱ
														{
															
															      key_return = (K_1|K_2);                // ��ϼ�����,"����"��
																		key_state = key_state_4;                   // ����ʱ��>=MuxKeyTime,ת�������ͷ�״̬
																		 
														}
												}
											else if (key_press == K_Back)  
												{
													                                                    // ������ʱ
														if(key_time>= OneKeyTime)                         // ����������ʱ
														{
															 
															      key_return = K_Long ;                     // ���س������ļ�ֵ
																		key_state = key_state_4;                  // ����ʱ��>=OneKeyTime 																		                                       
 
														}
												}
												
												
 										else if(key_press == K_1||key_press == K_2)   
												{
													  
														if(key_time >= OneKeyTime2s )                     // ����������ʱ
														{
																		key_state = key_state_3;                  // ����ʱ��>=OneKeyTime,ת����������̬,���ڴ�����������
																		key_time = 0;                                        // �尴��������
																		key_return = key_value_old;               // ������һ�ΰ���ֵ
														}
													 
												}		
										}
										else
										{
														key_state = key_state_4;                           // �����ѷ����仯,ת�������ͷ�̬
 
										}
										break;
						case key_state_3:                                                  // 4.������������
										if (key_press == key_press_old) 
										{
														if (++key_time >= RepeatTime)                      // ����ʱ����� 
														{
																		key_time = 0;                              // ����ʱ��>=0.05s����0����������
																		key_return = key_value_old;                // ������һ�ΰ���ֵ
														}                                
										}
										else
												key_state = key_state_4;                              // �����ѷ����仯,ת�������ͷ�̬
										break;
						case key_state_4:                                                 // 5.�ȴ����а����ͷſ�
										//if (!key_press)                                         // �ȴ����а����ͷ�,�Ž���һ���µİ���ȷ�Ϲ���
										if (key_press != key_press_old)                           // ���������仯,�ͽ���һ���µ�ȷ�Ϲ���
												key_state = key_state_0;                              // �������ͷ�,ת������ʼ̬.
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
							config_rf_flag = 1;   //������־Ϊ1ʱ,�ѵ�ַ��д��eeprom;
					
					    receive_rf_flag = 0;
						  KEY1 = key_code  ;
					
					P3_5 = !P3_5;
							break;
					
					case K_2: // 
							config_rf_flag = 1;   //������־Ϊ1ʱ,�ѵ�ַ��д��eeprom;
					    receive_rf_flag = 0;
						  KEY2 = key_code  ;
							break;
					
					case K_3: // 
							config_rf_flag = 1;   //������־Ϊ1ʱ,�ѵ�ַ��д��eeprom;
					
					    receive_rf_flag = 0;
						  KEY3 = key_code  ;
							break;
					
						
					
					case 0: //�ް�������
							break; 
					default:
							
						 break;
				}
//	 }	
			
}










