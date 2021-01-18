#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

Servo servo_10;

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
int kursor = 0;


void setup(){
   Serial.begin(9600);
   lcd.begin(16, 2);
   lcd.setCursor(LCDRow, 0);
   servo_10.attach(9, 500, 2500);
   kunciPintu();
   
 }
  
void loop(){  
  char key = keypad.getKey();
  
  //Masukan 4 digit akhir nik
  if (key !=NO_KEY){
	lcd.clear();
	
	for(int i = 0;i <= 4;i++){
		if(key == nik[currentposition]){
			lcd.setCursor(i,0);
			Serial.print(kursor);
			lcd.print(key);
			pass += key; 	
			++currentposition;
		}
		
	}

	if(currentposition == 4){
		bukaPintu();
		tutupPintu();
	}
  }
  
  
}

void kunciPintu(){
	delay(2000);
	currentposition = 0;
	servo_10.write(0);
	lcd.print("Masukan 4 digit ");
	lcd.setCursor(LCDRow, 1);
	lcd.print("akhir nik anda");
}

void tutupPintu(){
	lcd.clear();
	lcd.print("Pintu akan ter");
	lcd.setCursor(0, 1);
	lcd.print("tutup stlh 2 detik");
	delay(2000);
	lcd.clear();
	servo_10.write(0);
	kunciPintu();
}

void bukaPintu(){
	lcd.clear();
	lcd.print("Silahkan masuk");
	servo_10.write(90);
	delay(2000);
}