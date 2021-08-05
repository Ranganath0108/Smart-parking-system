#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
//intializing trigger pins
#define trigA 4
#define trigB 5 
#define trigC 6

//intializing echopins
#define echoA 8
#define echoB 9
#define echoC 10

//declaration of supportive vareiables

long duraA;
long duraB;
long duraC;

//distance
int distA;
int distB;
int distC;

void setup() {

//Output of arduino is the input to ultrasonic sensor
pinMode(trigA, OUTPUT); 
pinMode(trigB, OUTPUT); 
pinMode(trigC, OUTPUT); 
//input
pinMode(echoA, INPUT);
pinMode(echoB, INPUT);
pinMode(echoC, INPUT);

lcd.init();
lcd.clear();
lcd.backlight();
  
Serial.begin(9600); 
}
void loop() {
// Clears the trigPin
digitalWrite(trigA, LOW);
digitalWrite(trigB, LOW);
digitalWrite(trigC, LOW);

delayMicroseconds(2);

digitalWrite(trigA, HIGH);
digitalWrite(trigB, HIGH);
digitalWrite(trigC, HIGH);

delayMicroseconds(10);


digitalWrite(trigA, LOW);
digitalWrite(trigB, LOW);
digitalWrite(trigC, LOW);

// Reads 
duraA = pulseIn(echoA, HIGH);
duraB = pulseIn(echoB,HIGH);
duraC = pulseIn(echoC, HIGH);

//distance caluclation
distA= duraA*0.034/2;
distB= duraB*0.034/2;
distC= duraC*0.034/2;

int valA=Available(distA);
int valB=Available(distB);
int valC=Available(distC);

lcd.setCursor(0,0);
lcd.print("SLOT");
lcd.setCursor(0,6);
lcd.print("A");
lcd.setCursor(0,9);
lcd.print("B");
lcd.setCursor(0,12);
lcd.print("C");
lcd.setCursor(1,6);
lcd.print(valA);
lcd.setCursor(1,9);
lcd.print(valB);
lcd.setCursor(1,12);
lcd.print(valC);

}
int Available(int distance){
  if(distance>=25)
  return 1;
  else 
return 0;}
