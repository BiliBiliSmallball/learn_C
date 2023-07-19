#ifndef __LCDZIKU_H
#define __LCDZIKU_H
#include <system.h>

unsigned char const Hzk[] =
{

    0x00, 0x20, 0x20, 0x20, 0x20, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x40, 0x20, 0x30, 0x18, 0x10, 0x00,
    0x10, 0x30, 0x18, 0x08, 0x04, 0x7F, 0x00, 0x00, 0x00, 0x3F, 0x40, 0x40, 0x40, 0x40, 0x78, 0x00, /*"北",0*/

    0x00, 0x04, 0x04, 0xE4, 0x24, 0x24, 0x25, 0x26, 0x24, 0x24, 0x24, 0xE4, 0x06, 0x04, 0x00, 0x00,
    0x00, 0x20, 0x10, 0x19, 0x0D, 0x41, 0x81, 0x7F, 0x01, 0x01, 0x05, 0x0D, 0x38, 0x10, 0x00, 0x00, /*"京",1*/

    0x02, 0x02, 0x02, 0xF2, 0x12, 0x12, 0x1E, 0x16, 0x12, 0x12, 0x12, 0xF2, 0x02, 0x02, 0x02, 0x00,
    0x00, 0x00, 0x00, 0xFF, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0xFF, 0x00, 0x00, 0x00, 0x00, /*"百",2*/

    0x10, 0x12, 0x92, 0x72, 0xFE, 0x51, 0x91, 0x00, 0x22, 0xCC, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00,
    0x04, 0x02, 0x01, 0x00, 0xFF, 0x00, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0xFF, 0x01, 0x01, 0x00, /*"科",3*/

    0x84, 0x64, 0x24, 0x24, 0x2F, 0x24, 0x24, 0xA4, 0x24, 0x24, 0x2F, 0x24, 0x24, 0xA4, 0x64, 0x00,
    0x40, 0x42, 0x22, 0x22, 0x12, 0x0A, 0x06, 0xFF, 0x06, 0x0A, 0x12, 0x22, 0x22, 0x42, 0x40, 0x00, /*"荣",0*/

    0x40, 0x20, 0xD0, 0x4C, 0x43, 0x44, 0x48, 0xD8, 0x30, 0x10, 0x00, 0xFC, 0x00, 0x00, 0xFF, 0x00,
    0x00, 0x00, 0x3F, 0x40, 0x40, 0x42, 0x44, 0x43, 0x78, 0x00, 0x00, 0x07, 0x20, 0x40, 0x3F, 0x00, /*"创",5*/

    0x00, 0x80, 0x40, 0x20, 0x18, 0x06, 0x80, 0x00, 0x07, 0x18, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x20, 0x70, 0x28, 0x26, 0x21, 0x20, 0x20, 0x24, 0x38, 0x60, 0x00, 0x01, 0x01, 0x00, /*"公",6*/

    0x00, 0x10, 0x12, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x12, 0x12, 0x02, 0xFE, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3F, 0x10, 0x10, 0x10, 0x10, 0x3F, 0x00, 0x40, 0x80, 0x7F, 0x00, 0x00, 0x00, /*"司",7*/


    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",0*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",1*/

    0x00, 0xFC, 0x84, 0x84, 0x84, 0xFC, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0xFF, 0x10, 0x10, 0x00,

    0x00, 0x3F, 0x10, 0x10, 0x10, 0x3F, 0x00, 0x00, 0x01, 0x06, 0x40, 0x80, 0x7F, 0x00, 0x00, 0x00, /*"时",0*/

    0x20, 0x10, 0x2C, 0xE7, 0x24, 0x24, 0x00, 0xF0, 0x10, 0x10, 0xFF, 0x10, 0x10, 0xF0, 0x00, 0x00,

    0x01, 0x01, 0x01, 0x7F, 0x21, 0x11, 0x00, 0x07, 0x02, 0x02, 0xFF, 0x02, 0x02, 0x07, 0x00, 0x00, /*"钟",1*/

    0x10, 0x0C, 0x04, 0x84, 0x14, 0x64, 0x05, 0x06, 0xF4, 0x04, 0x04, 0x04, 0x04, 0x14, 0x0C, 0x00,

    0x04, 0x84, 0x84, 0x44, 0x47, 0x24, 0x14, 0x0C, 0x07, 0x0C, 0x14, 0x24, 0x44, 0x84, 0x04, 0x00, /*"实",6*/

    0x02, 0xFA, 0x82, 0x82, 0xFE, 0x80, 0x40, 0x20, 0x50, 0x4C, 0x43, 0x4C, 0x50, 0x20, 0x40, 0x00,

    0x08, 0x18, 0x48, 0x84, 0x44, 0x3F, 0x40, 0x44, 0x58, 0x41, 0x4E, 0x60, 0x58, 0x47, 0x40, 0x00, /*"验",7*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",8*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",9*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",0*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",1*/

    0x00, 0x00, 0xF0, 0xE0, 0xA0, 0xA0, 0x50, 0xF0, 0xD0, 0xD0, 0x10, 0x10, 0x20, 0xE0, 0x20, 0x00,
    0x00, 0x00, 0x1F, 0x1F, 0x12, 0x16, 0x1D, 0x1B, 0x1D, 0x1D, 0x12, 0x12, 0x12, 0x1F, 0x00, 0x00, /*"图",2*/

    0x00, 0x00, 0x20, 0x20, 0xE0, 0x20, 0xE0, 0x20, 0x20, 0x40, 0x40, 0x20, 0xA0, 0xB0, 0x00, 0x00,
    0x00, 0x11, 0x19, 0x0D, 0x07, 0x01, 0x1F, 0x19, 0x11, 0x12, 0x12, 0x19, 0x09, 0x0C, 0x06, 0x00, /*"形",3*/

    0x00, 0x00, 0x20, 0x60, 0x40, 0xC0, 0xA0, 0xE0, 0xB0, 0xB0, 0xE0, 0xA0, 0xA0, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x19, 0x0A, 0x06, 0x01, 0x3F, 0x0A, 0x0B, 0x05, 0x07, 0x0B, 0x18, 0x18, 0x10, 0x00, /*"液",4*/

    0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0xD0, 0xD0, 0xD0, 0xD0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3E, 0x1A, 0x1B, 0x1A, 0x3E, 0x00, 0x3E, 0x3E, 0x2B, 0x2A, 0x2A, 0x3E, 0x02, 0x00, /*"晶",5*/

    0x00, 0x00, 0x00, 0xE0, 0xF0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xF0, 0x60, 0x00, 0x00, 0x00,
    0x00, 0x30, 0x10, 0x16, 0x15, 0x11, 0x1F, 0x11, 0x11, 0x1F, 0x11, 0x15, 0x36, 0x30, 0x10, 0x00, /*"显",6*/

    0x00, 0x80, 0x80, 0x80, 0xB0, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xA0, 0x80, 0x80, 0x80, 0x80,
    0x00, 0x01, 0x08, 0x0C, 0x06, 0x22, 0x20, 0x3F, 0x1F, 0x00, 0x06, 0x04, 0x09, 0x11, 0x01, 0x00, /*"示",7*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",8*/
    /*--  ??:  24   --*/
    /*--  ??12;  ??????????:?x?=16x16   --*/
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};


/****************************************/
/*        ??ASCII??8?*16?		    */
/****************************************/
unsigned char const Ezk[] =
{

//  (0)  (1) W(2) W(3) W(4) .(5) R(6) 8(7) C(8) .(9) C(10) O(11) M(12)  (13)  (14)  (15)


    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",0*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",1*/

    0xF8, 0x08, 0x00, 0xF8, 0x00, 0x08, 0xF8, 0x00, 0x03, 0x3C, 0x07, 0x00, 0x07, 0x3C, 0x03, 0x00, /*"W",2*/

    0xF8, 0x08, 0x00, 0xF8, 0x00, 0x08, 0xF8, 0x00, 0x03, 0x3C, 0x07, 0x00, 0x07, 0x3C, 0x03, 0x00, /*"W",3*/

    0xF8, 0x08, 0x00, 0xF8, 0x00, 0x08, 0xF8, 0x00, 0x03, 0x3C, 0x07, 0x00, 0x07, 0x3C, 0x03, 0x00, /*"W",4*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, /*".",5*/

    0x08, 0xF8, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x03, 0x0C, 0x30, 0x20, /*"R",6*/

    0x00, 0x70, 0x88, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x1C, 0x22, 0x21, 0x21, 0x22, 0x1C, 0x00, /*"8",7*/

    0xC0, 0x30, 0x08, 0x08, 0x08, 0x08, 0x38, 0x00, 0x07, 0x18, 0x20, 0x20, 0x20, 0x10, 0x08, 0x00, /*"C",8*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, /*".",9*/

    0xC0, 0x30, 0x08, 0x08, 0x08, 0x08, 0x38, 0x00, 0x07, 0x18, 0x20, 0x20, 0x20, 0x10, 0x08, 0x00, /*"C",10*/

    0xE0, 0x10, 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x0F, 0x10, 0x20, 0x20, 0x20, 0x10, 0x0F, 0x00, /*"O",11*/

    0x08, 0xF8, 0xF8, 0x00, 0xF8, 0xF8, 0x08, 0x00, 0x20, 0x3F, 0x00, 0x3F, 0x00, 0x3F, 0x20, 0x00, /*"M",12*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",13*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",14*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",15*/

};

unsigned char const ascll[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",0*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",1*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*"",2*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",3*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",4*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",5*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",6*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",7*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",8*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*"	",9*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",10*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",11*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",12*/

    0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x0E, 0x07, 0x03, 0x3F, 0x3F, 0x03, 0x07, /*"",13*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",14*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",15*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",16*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",17*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",18*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",19*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",20*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",21*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",22*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",23*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",24*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",25*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",26*/

    0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /*"",27*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*"",28*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*"",29*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*"",30*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*"",31*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*" ",32*/

    0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x00, /*"!",33*/

    0x00, 0x10, 0x0C, 0x02, 0x10, 0x0C, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*""",34*/

    0x00, 0x40, 0xC0, 0x78, 0x40, 0xC0, 0x78, 0x00, 0x00, 0x04, 0x3F, 0x04, 0x04, 0x3F, 0x04, 0x00, /*"#",35*/

    0x00, 0x70, 0x88, 0x88, 0xFC, 0x08, 0x30, 0x00, 0x00, 0x18, 0x20, 0x20, 0xFF, 0x21, 0x1E, 0x00, /*"$",36*/

    0xF0, 0x08, 0xF0, 0x80, 0x60, 0x18, 0x00, 0x00, 0x00, 0x31, 0x0C, 0x03, 0x1E, 0x21, 0x1E, 0x00, /*"%",37*/

    0x00, 0xF0, 0x08, 0x88, 0x70, 0x00, 0x00, 0x00, 0x1E, 0x21, 0x23, 0x2C, 0x19, 0x27, 0x21, 0x10, /*"&",38*/

    0x00, 0x12, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*"'",39*/

    0x00, 0x00, 0x00, 0xE0, 0x18, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x07, 0x18, 0x20, 0x40, 0x00, /*"(",40*/

    0x00, 0x02, 0x04, 0x18, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x18, 0x07, 0x00, 0x00, 0x00, /*")",41*/

    0x40, 0x40, 0x80, 0xF0, 0x80, 0x40, 0x40, 0x00, 0x02, 0x02, 0x01, 0x0F, 0x01, 0x02, 0x02, 0x00, /*"*",42*/

    0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x0F, 0x01, 0x01, 0x01, /*"+",43*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, /*",",44*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, /*"-",45*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, /*".",46*/

    0x00, 0x00, 0x00, 0x00, 0xC0, 0x38, 0x04, 0x00, 0x00, 0x60, 0x18, 0x07, 0x00, 0x00, 0x00, 0x00, /*"/",47*/

    0x00, 0xE0, 0x10, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x00, 0x0F, 0x10, 0x20, 0x20, 0x10, 0x0F, 0x00, /*"0",48*/

    0x00, 0x00, 0x10, 0x10, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, /*"1",49*/

    0x00, 0x70, 0x08, 0x08, 0x08, 0x08, 0xF0, 0x00, 0x00, 0x30, 0x28, 0x24, 0x22, 0x21, 0x30, 0x00, /*"2",50*/

    0x00, 0x30, 0x08, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x18, 0x20, 0x21, 0x21, 0x22, 0x1C, 0x00, /*"3",51*/

    0x00, 0x00, 0x80, 0x40, 0x30, 0xF8, 0x00, 0x00, 0x00, 0x06, 0x05, 0x24, 0x24, 0x3F, 0x24, 0x24, /*"4",52*/

    0x00, 0xF8, 0x88, 0x88, 0x88, 0x08, 0x08, 0x00, 0x00, 0x19, 0x20, 0x20, 0x20, 0x11, 0x0E, 0x00, /*"5",53*/

    0x00, 0xE0, 0x10, 0x88, 0x88, 0x90, 0x00, 0x00, 0x00, 0x0F, 0x11, 0x20, 0x20, 0x20, 0x1F, 0x00, /*"6",54*/

    0x00, 0x18, 0x08, 0x08, 0x88, 0x68, 0x18, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x01, 0x00, 0x00, 0x00, /*"7",55*/

    0x00, 0x70, 0x88, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x1C, 0x22, 0x21, 0x21, 0x22, 0x1C, 0x00, /*"8",56*/

    0x00, 0xF0, 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x00, 0x01, 0x12, 0x22, 0x22, 0x11, 0x0F, 0x00, /*"9",57*/

    0x00, 0x00, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, /*":",58*/

    0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, /*";",59*/

    0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x00, 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x00, /*"<",60*/

    0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, /*"=",61*/

    0x00, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, /*">",62*/

    0x00, 0x70, 0x48, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x00, 0x00, 0x30, 0x37, 0x00, 0x00, 0x00, /*"?",63*/

    0xC0, 0x30, 0xC8, 0x28, 0xE8, 0x10, 0xE0, 0x00, 0x07, 0x18, 0x27, 0x28, 0x2F, 0x28, 0x17, 0x00, /*"@",64*/

    0x00, 0x00, 0xC0, 0x38, 0xE0, 0x00, 0x00, 0x00, 0x20, 0x3C, 0x23, 0x02, 0x02, 0x27, 0x38, 0x20, /*"A",65*/

    0x08, 0xF8, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x20, 0x3F, 0x20, 0x20, 0x20, 0x11, 0x0E, 0x00, /*"B",66*/

    0xC0, 0x30, 0x08, 0x08, 0x08, 0x08, 0x38, 0x00, 0x07, 0x18, 0x20, 0x20, 0x20, 0x10, 0x08, 0x00, /*"C",67*/

    0x08, 0xF8, 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x20, 0x3F, 0x20, 0x20, 0x20, 0x10, 0x0F, 0x00, /*"D",68*/

    0x08, 0xF8, 0x88, 0x88, 0xE8, 0x08, 0x10, 0x00, 0x20, 0x3F, 0x20, 0x20, 0x23, 0x20, 0x18, 0x00, /*"E",69*/

    0x08, 0xF8, 0x88, 0x88, 0xE8, 0x08, 0x10, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x03, 0x00, 0x00, 0x00, /*"F",70*/

    0xC0, 0x30, 0x08, 0x08, 0x08, 0x38, 0x00, 0x00, 0x07, 0x18, 0x20, 0x20, 0x22, 0x1E, 0x02, 0x00, /*"G",71*/

    0x08, 0xF8, 0x08, 0x00, 0x00, 0x08, 0xF8, 0x08, 0x20, 0x3F, 0x21, 0x01, 0x01, 0x21, 0x3F, 0x20, /*"H",72*/

    0x00, 0x08, 0x08, 0xF8, 0x08, 0x08, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, 0x00, /*"I",73*/

    0x00, 0x00, 0x08, 0x08, 0xF8, 0x08, 0x08, 0x00, 0xC0, 0x80, 0x80, 0x80, 0x7F, 0x00, 0x00, 0x00, /*"J",74*/

    0x08, 0xF8, 0x88, 0xC0, 0x28, 0x18, 0x08, 0x00, 0x20, 0x3F, 0x20, 0x01, 0x26, 0x38, 0x20, 0x00, /*"K",75*/

    0x08, 0xF8, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x30, 0x00, /*"L",76*/

    0x08, 0xF8, 0xF8, 0x00, 0xF8, 0xF8, 0x08, 0x00, 0x20, 0x3F, 0x01, 0x3E, 0x01, 0x3F, 0x20, 0x00, /*"M",77*/

    0x08, 0xF8, 0x30, 0xC0, 0x00, 0x08, 0xF8, 0x08, 0x20, 0x3F, 0x20, 0x00, 0x07, 0x18, 0x3F, 0x00, /*"N",78*/

    0xE0, 0x10, 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x0F, 0x10, 0x20, 0x20, 0x20, 0x10, 0x0F, 0x00, /*"O",79*/

    0x08, 0xF8, 0x08, 0x08, 0x08, 0x08, 0xF0, 0x00, 0x20, 0x3F, 0x21, 0x01, 0x01, 0x01, 0x00, 0x00, /*"P",80*/

    0xE0, 0x10, 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x0F, 0x10, 0x28, 0x28, 0x30, 0x50, 0x4F, 0x00, /*"Q",81*/

    0x08, 0xF8, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x03, 0x0C, 0x30, 0x20, /*"R",82*/

    0x00, 0x70, 0x88, 0x08, 0x08, 0x08, 0x38, 0x00, 0x00, 0x38, 0x20, 0x21, 0x21, 0x22, 0x1C, 0x00, /*"S",83*/

    0x18, 0x08, 0x08, 0xF8, 0x08, 0x08, 0x18, 0x00, 0x00, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x00, 0x00, /*"T",84*/

    0x08, 0xF8, 0x08, 0x00, 0x00, 0x08, 0xF8, 0x08, 0x00, 0x1F, 0x20, 0x20, 0x20, 0x20, 0x1F, 0x00, /*"U",85*/

    0x08, 0x78, 0x88, 0x00, 0x00, 0xC8, 0x38, 0x08, 0x00, 0x00, 0x07, 0x38, 0x0E, 0x01, 0x00, 0x00, /*"V",86*/

    0x08, 0xF8, 0x00, 0xF8, 0x00, 0xF8, 0x08, 0x00, 0x00, 0x03, 0x3E, 0x01, 0x3E, 0x03, 0x00, 0x00, /*"W",87*/

    0x08, 0x18, 0x68, 0x80, 0x80, 0x68, 0x18, 0x08, 0x20, 0x30, 0x2C, 0x03, 0x03, 0x2C, 0x30, 0x20, /*"X",88*/

    0x08, 0x38, 0xC8, 0x00, 0xC8, 0x38, 0x08, 0x00, 0x00, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x00, 0x00, /*"Y",89*/

    0x10, 0x08, 0x08, 0x08, 0xC8, 0x38, 0x08, 0x00, 0x20, 0x38, 0x26, 0x21, 0x20, 0x20, 0x18, 0x00, /*"Z",90*/

    0x00, 0x00, 0x00, 0xFE, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x40, 0x40, 0x40, 0x00, /*"[",91*/

    0x00, 0x04, 0x38, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x38, 0xC0, 0x00, /*"\",92*/

    0x00, 0x02, 0x02, 0x02, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x7F, 0x00, 0x00, 0x00, /*"]",93*/

    0x00, 0x00, 0x04, 0x02, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*"^",94*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, /*"_",95*/

    0x00, 0x02, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*"`",96*/

    0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x19, 0x24, 0x24, 0x12, 0x3F, 0x20, 0x00, /*"a",97*/

    0x10, 0xF0, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x11, 0x20, 0x20, 0x11, 0x0E, 0x00, /*"b",98*/

    0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x0E, 0x11, 0x20, 0x20, 0x20, 0x11, 0x00, /*"c",99*/

    0x00, 0x00, 0x80, 0x80, 0x80, 0x90, 0xF0, 0x00, 0x00, 0x1F, 0x20, 0x20, 0x20, 0x10, 0x3F, 0x20, /*"d",100*/

    0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x1F, 0x24, 0x24, 0x24, 0x24, 0x17, 0x00, /*"e",101*/

    0x00, 0x80, 0x80, 0xE0, 0x90, 0x90, 0x20, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, 0x00, /*"f",102*/

    0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x6B, 0x94, 0x94, 0x94, 0x93, 0x60, 0x00, /*"g",103*/

    0x10, 0xF0, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x20, 0x3F, 0x21, 0x00, 0x00, 0x20, 0x3F, 0x20, /*"h",104*/

    0x00, 0x80, 0x98, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, 0x00, /*"i",105*/

    0x00, 0x00, 0x00, 0x80, 0x98, 0x98, 0x00, 0x00, 0x00, 0xC0, 0x80, 0x80, 0x80, 0x7F, 0x00, 0x00, /*"j",106*/

    0x10, 0xF0, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x20, 0x3F, 0x24, 0x06, 0x29, 0x30, 0x20, 0x00, /*"k",107*/

    0x00, 0x10, 0x10, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, 0x00, /*"l",108*/

    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x3F, 0x20, 0x00, 0x3F, /*"m",109*/

    0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x20, 0x3F, 0x21, 0x00, 0x00, 0x20, 0x3F, 0x20, /*"n",110*/

    0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x1F, 0x20, 0x20, 0x20, 0x20, 0x1F, 0x00, /*"o",111*/

    0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x91, 0x20, 0x20, 0x11, 0x0E, 0x00, /*"p",112*/

    0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 0x0E, 0x11, 0x20, 0x20, 0x91, 0xFF, 0x80, /*"q",113*/

    0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x20, 0x20, 0x3F, 0x21, 0x20, 0x00, 0x01, 0x00, /*"r",114*/

    0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x33, 0x24, 0x24, 0x24, 0x24, 0x19, 0x00, /*"s",115*/

    0x00, 0x80, 0x80, 0xE0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x20, 0x20, 0x10, 0x00, /*"t",116*/

    0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x1F, 0x20, 0x20, 0x20, 0x10, 0x3F, 0x20, /*"u",117*/

    0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x03, 0x0C, 0x30, 0x0C, 0x03, 0x00, 0x00, /*"v",118*/

    0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x80, 0x80, 0x01, 0x0E, 0x30, 0x0C, 0x07, 0x38, 0x06, 0x01, /*"w",119*/

    0x00, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x20, 0x31, 0x0E, 0x2E, 0x31, 0x20, 0x00, /*"x",120*/

    0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x81, 0x86, 0x78, 0x18, 0x06, 0x01, 0x00, /*"y",121*/

    0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x21, 0x30, 0x2C, 0x22, 0x21, 0x30, 0x00, /*"z",122*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x3E, 0x40, 0x40, /*"{",123*/

    0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, /*"|",124*/

    0x02, 0x02, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x3E, 0x01, 0x00, 0x00, 0x00, 0x00, /*"}",125*/

    0x00, 0x02, 0x01, 0x02, 0x02, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*"~",126*/

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*"",127*/

};


#endif




