/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_PORT_MAP.h
********************************************************************************


*******************************************************************************/
#ifndef __HC89F30x_PORT_MAP_H__
#define __HC89F30x_PORT_MAP_H__

//===============================================================================
#define P0MAP      0x00
#define P1MAP      0x10
#define P2MAP      0x20
#define P3MAP      0x30

#define PINNUM0    0x00
#define PINNUM1    0x01
#define PINNUM2    0x02
#define PINNUM3    0x03
#define PINNUM4    0x04
#define PINNUM5    0x05
#define PINNUM6    0x06
#define PINNUM7    0x07

#define PMAP(port_num, pin_num)						((P##port_num##MAP) | (PINNUM##pin_num))

//===============================================================================

#endif/* __HC89F30x_PORT_MAP_H__ */
