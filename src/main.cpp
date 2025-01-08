//Oliver Olsen s205443
//Nils Wulff   s223968

/*
*   8a. The analog value is represented as an int.
*   The highest value when using the 3v3, is 675 (theoretically)
*   
*   8b. The highest value we could read is 3.34
*   
*   8c. It resonates slightly with 0.03 in variation.
*   
*   
*/

#include <Arduino.h>
#define ANALOGPIN A0

#define REDPIN    10
#define BLUEPIN   11
#define GREENPIN  12

float voltage = 0.000;
int potValue = 0;
int blueVal = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(ANALOGPIN, INPUT);
  pinMode(REDPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);


  digitalWrite(REDPIN, HIGH);   //Should alway be on
  digitalWrite(BLUEPIN, LOW);   
  digitalWrite(GREENPIN, LOW);  //Should always be off
}

void loop() {
  //Serial.println(analogRead(ANALOGPIN));
  
  potValue = analogRead(ANALOGPIN);
  // voltage variable
  voltage = potValue * (3.3/675);
  // Forces 3 decimals on the float value of our voltage
  Serial.println(voltage, 3);

  blueVal = map(potValue, 0, 675, 0, 255);
  analogWrite(BLUEPIN, blueVal);

  delay(100);

}
