#define trigPin  9
#define echoPin  10
#define alaram 13
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
pinMode(alaram,OUTPUT); 
digitalWrite(alaram,LOW);
Serial.begin(9600); 
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delay(2000);
digitalWrite(trigPin, HIGH);
delay(1000);
digitalWrite(trigPin, LOW);
// Reads 
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
// Prints 
if (distance>=5)
{digitalWrite(alaram,LOW);}
else{
digitalWrite(alaram,HIGH);}

Serial.print("Distance: ");
Serial.print(distance);
Serial.print("cm");
Serial.print("\n");}
