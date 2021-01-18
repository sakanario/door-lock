#include <Keypad.h>
#include <LiquidCrystal.h>

String pass = "";
String nik = "4567";

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {1,2,3,4}; //Rows 0 to 3
byte colPins[COLS]= {5,6,7,8}; //Columns 0 to 3
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int LCDRow = 0;
bool pintuBuka = false;
int currentposition = 0;


void setup(){
   Serial.begin(9600);
   lcd.begin(16, 2);
   lcd.setCursor(LCDRow, 0);
   lcd.print("Masukan 4 digit ");
   lcd.setCursor(LCDRow, 1);
   lcd.print("akhir nik anda");
 }
  
void loop(){
  char key = keypad.getKey();
  
  //Masukan 4 digit akhir nik
  if (key !=NO_KEY){
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("PASSWORD:");
	lcd.setCursor(7,1);
	lcd.print(" ");
	lcd.setCursor(7,1);
	for(int i = 0;i <= currentposition;++i)
	{
		lcd.print("*");
	}
  }
  
  if (key==nik[currentposition])
		{
			++currentposition;
			if(currentposition==4)
			{
				unlockdoor();
				currentposition=0;
			}
		}
		else
		{
			incorrect();
			currentposition=0;
		}
 
 //Cek jika inputan benar
  if(pass.equals(nik)){
	  Serial.println("Silahkan masuk");
	  pintuBuka = true;
  }

  
}

void unlockdoor(){
	lcd.print("Silahkan masuk");
}

void incorrect(){
	lcd.print("NIK salah");
}