/*                                                                                                                        
HC-SR04 Ultrasonic Sensor
VCC to Arduino 5V
GND to Arduino GND
Echo to Arduino pin 12
Trig to Arduino pin 13

LCD Display 
VSS to Arduino GND
VCC to Arduino 5V
VEE to Arduino GND
RS to Arduino pin 11
R/W to Arduino pin 10
E to Arduino pin 9
DB4 to Arduino pin 2
DB5 to Arduino pin 3
DB6 to Arduino pin 4
DB7 to Arduino pin 5
LED+ to Arduino 5V
LED- to Arduino GND
*/

#include <LiquidCrystal.h> //Knjižnjica,ki jo moraš naložiti(Liquid Crystal Library)
LiquidCrystal LCD(11,10,9,2,3,4,5); 

#define trigPin 13 //Echo pin povezan na Arduino pin 13
#define echoPin 12 //Trig pin povezan na Arduino pin 12

void setup()
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

LCD.begin(16,2); //Arduino, naj začne svoj 16-stolpični LCD z 16 stolpci LCD
LCD.setCursor(0,0); //Nastavi kazalec LCD v zgornji levi kot, stolpec 0, vrstica 0

LCD.print("Razdalja:"); //Izpiše sporočilo na prvo vrstico                                                                         
}                                                                                                                         

void loop() {
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);                                                                                              
distance = (duration/2) / 29.1;

LCD.setCursor(0,1); //Nastavi kazalec na prvi stolpec druge vrstice
LCD.print(" "); //Izpiše praznino, da počisti vrstico
LCD.setCursor(0,1); //Ponovno nastavi kazalec v prvi stolpec druge vrstice
LCD.print(distance); //Izpiše izmerjeno razdaljo
LCD.print(" cm                  "); //Izpiše svojo enoto
delay(500); //Premor, da uredi stvari                                                                                               
}
