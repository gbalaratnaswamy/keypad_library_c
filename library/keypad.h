// atmel studio keypad header file
/*
This is a keypad library for atmel studio.
This library works only when keypad is 4*4 or less and all keypad pins are connected to only one port
This library outputs single key pressed if multikeys are pressed at a time this library donot work well
This library output values in keypad data type defined in this library you can ascess by typing .row and .column infront of them

*/   

//if delay lib was not included
#ifndef F_CPU
#warinig "util/delay.h not included or included after this library"
#endif
//time delay between setting pins low and reading form input.
#define keypad_excdelay 1
//a macro function to set costum delay time.
#define keypad_set_delay(n)  (#define keypad_excdelay n)

//defining new data type for simple usage and saving space.
typedef struct {
	uint8_t row : 2;
	uint8_t column :2;
	} keypad;
// keypad function which returns key pressed when called.
// port must be given as input with &before it eg: &PORTD
// returns rows and colums in keypad data form defined before.
// incase of fail reading or key is not pressed returns rows and colums as 15 
keypad keypad_getkey(volatile uint8_t *Port)
{
	uint8_t i=0;
	keypad key;
	key.row=4;                         //
	key.column=4;                      //initilize column and row to 4 value which indicates error.
	*(port-1) =0xF0;                   //set colums as output and rows as input.
	*(port) =0x0F;                     //set colums low and rows with pull_up resistors
	_delay_ms(keypad_excdelay);        //wait for settings to take effect
	i=*(port-2)^0x0F;                  //reads row number.
	if(i==0)
		return key;
	if(i==8)
	    key.row= 3;
	else key.row= i>>1;
	*(port-1) =0x0F;
	*(port) =0xF0;
	_delay_ms(keypad_excdelay);
	i|=*(port-2)^0xF0;                //reads column number.
	i=i>>4;
	if(i==8)
	  key.column= 3;
	else key.column= i>>1;
	return key;
}
