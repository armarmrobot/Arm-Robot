#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

Servo motor_1;
Servo motor_2;
Servo motor_3;
Servo motor_4;

int servo1 = 80;// salka
int servo2 = 30;// garab bidix
int servo3 = 110;
int servo4 = 140;

#define  trigSer  6
#define  echoSer  5

void setup() {
  // put your setup code here, to run once:

    lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Arm Robot System");
  lcd.setCursor(0,1);
  lcd.print("Welcome ");
  
motor_1.attach(8);
motor_2.attach(9);
motor_3.attach(10);
motor_4.attach(11);

  pinMode(trigSer, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoSer, INPUT); 
 
motor_1.write(servo1); 
motor_2.write(servo2); 
motor_3.write(servo3); 
motor_4.write(servo4); 
Serial.begin(9600);
}

void loop() {

    long duration;
  int distance;
  digitalWrite(trigSer, LOW);   // Makes trigPin low
  delayMicroseconds(2);       // 2 micro second delay

  digitalWrite(trigSer, HIGH);  // tigPin high
  delayMicroseconds(10);      // trigPin high for 10 micro seconds
  digitalWrite(trigSer, LOW);   // trigPin low

  duration = pulseIn(echoSer, HIGH);   //Read echo pin, time in microseconds
  distance = duration * 0.034 / 2;   //Calculating actual/real distance
    Serial.print("Distance = ");        //Output distance on arduino serial monitor
  Serial.println(distance);

if(distance<7 && distance>2){
catchPut();
}
  lcd.setCursor(0,0);
  lcd.print("Arm Robot System");
  lcd.setCursor(0,1);
  lcd.print("Distance: ");
  lcd.setCursor(10,1);
  lcd.print(distance);
  lcd.setCursor(14,1);
  lcd.print("CM");
  delay(600);
  lcd.clear();

}//end void loop


void catchPut(){
for(int i=70;i<160;i++){
motor_1.write(i);
delay(20);
}// salka

for(int k=110;k>50;k--){
motor_3.write(k);
delay(20);
}// garab bidix


for(int j=30;j<80;j++){
motor_2.write(j);
delay(20);
}//garab midig

for(int m=125;m<180;m++){
  motor_4.write(m);
  delay(25);
}//faraha

for(int m=180;m>125;m--){
  motor_4.write(m);
  delay(25);
}///faraha


for(int j=80;j>30;j--){
motor_2.write(j);
delay(20);
}//garab midig

for(int k=50;k<110;k++){
motor_3.write(k);
delay(20);
}// garab bidix


for(int i=160;i>70;i--){
motor_1.write(i);
delay(20);
}// salka

for(int k=110;k>40;k--){
motor_3.write(k);
delay(20);
}// garab bidix

for(int j=30;j<68;j++){
motor_2.write(j);
delay(20);
}//garab midig

////
for(int m=125;m<180;m++){
  motor_4.write(m);
  delay(25);
}//faraha

for(int m=180;m>125;m--){
  motor_4.write(m);
  delay(25);
}///faraha
////

for(int j=68;j>30;j--){
motor_2.write(j);
delay(20);
}//garab midig

for(int k=40;k<110;k++){
motor_3.write(k);
delay(20);
}// garab bidix
}


////////////////////////
void Ultrasonic_Ser()
{
  long duration;
  int distance;
  digitalWrite(trigSer, LOW);   // Makes trigPin low
  delayMicroseconds(2);       // 2 micro second delay

  digitalWrite(trigSer, HIGH);  // tigPin high
  delayMicroseconds(10);      // trigPin high for 10 micro seconds
  digitalWrite(trigSer, LOW);   // trigPin low

  duration = pulseIn(echoSer, HIGH);   //Read echo pin, time in microseconds
  distance = duration * 0.034 / 2;   //Calculating actual/real distance

  Serial.print("Distance = ");        //Output distance on arduino serial monitor
  Serial.println(distance);
  delay(100);
  
}
