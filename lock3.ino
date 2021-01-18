#include <Keypad.h>

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

char keymap[numRows][numCols]= 
{
	{'1', '2', '3', 'A'}, 
	{'4', '5', '6', 'B'}, 
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {1,2,3,4}; //Rows 0 to 3
byte colPins[numCols]= {5,6,7,0}; //Columns 0 to 3

Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

LiquidCrystal lcd(5, 4, 3, 2, A4, A5);


void setup()
{
	Serial.begin(9600);
}


void loop()
{
	char keypressed = myKeypad.getKey();
	if (keypressed != NO_KEY)
	{
		Serial.println(keypressed);
	}
}
