/*
 ============================================================================
 Name        : lcd.h
 Author      : kareem mohamed
 Description : define the used driver for lcd support 2line lcd for 4 bit mode and 8 bit mode
 Date        : 21/4/2019
 ============================================================================
 */

#ifndef LCD_H_
#define LCD_H_
#include "datatypes.h"
#include "dioavrRegisters.h"
#include "util/delay.h"
#include "commonMacros.h"
/*******************************************************************/
               /*LCD interface registers */
#define LCD_DATA_REG_DIR DDRD_REG
#define LCD_DATA_REG_PORT PORTD_REG

#define LCD_CTRL_REG_DIR DDRC_REG
#define LCD_CTRL_REG_PORT PORTC_REG

#define PIN_RS 5
#define RS BIT5
#define PIN_RW 6
#define RW BIT6
#define PIN_E 7
#define E BIT7
/******************************************************************/
                /*LCD MODE CONFIGURATION.*/
#define DATA_BIT_MODE 4
#if(DATA_BIT_MODE==8)
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#elif(DATA_BIT_MODE==4)
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_FOUR_BIT_MODE  0x28
#endif
/******************************************************************/
                       /*LCD COMMANDS*/
#define CURSOR_OFF 0x0C
#define CLEAR_COMMAND 0x01
#define SET_CURSOR_LOCATION 0x80
/******************************************************************/
                  /*LCD FUNCTION PROTOTYPES*/
void LCD_init(void);
void LCD_sendCommand(uint8 a_command);
void LCD_sendCharacter(uint8 a_data);
void LCD_displayString(char *str);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_intgerToString(int data);
#endif /* LCD_H_ */
