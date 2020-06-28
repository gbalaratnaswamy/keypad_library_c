# keypad_library_c
keypad library in c for atmel studio and arduino ide.

Most of us started making pojects in arduino ide and later shifted to atmel studio for better performance and optimization. This library is for those who just started learning atmel stuido and struggling with new formats and language or for those using arduino ide and want better performance.
This library has some limitations when compared to arduino library. like it can sense if only one button is pressed at a time, all pins must connect to same port and can't handle more than 4x4 keypad. There is a reason behind this, that is to make this library fast and consume less space.
These limitations donot effect most of the projects and if your project is within limits then you can use it in arduino ide also but you must pass port instead of pins and modify code with delay() instead of _delay_ms().

### syntax
if you want to use it with PORTx (for example like PORTD) then use this
keypad key;
key =kepad_getkey(&PORTx);
don't forgot to include ulit/delay.h
you can use it with muliple keypad connectd to multiple ports like
keypad key1,key2;
key1=kepad_getkey(&PORTx1);
key2=kepad_getkey(&PORTx2);

Here is how can ascess row and colum value with key
key.row    //row value in decimal startin from 0 to 3
key.column //column value in decimal from 0-3
if you get any one of the row or column as 4 it indicates no key is pressed


### example code atmel studio
```
#include<avr/io.h>
#define F_CPU 16000000UL
#include<ulit/delay.h>
#include "keypad.h"

void main(void){
keypad key;
while(1){
key =keypad_getkey(&PORTD);
fprintf(stdout,key.row);
fprintf(stdout,",",key.column);
fprintf(stdout,"\n");
_delay_ms(100);
}
}
```
