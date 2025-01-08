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

float voltage = 0.000;

void setup() {
  Serial.begin(9600);
  pinMode(ANALOGPIN, INPUT);

}

void loop() {
  //Serial.println(analogRead(ANALOGPIN));
  
  // voltage variable
  voltage = analogRead(ANALOGPIN) * (3.3/675);

  // Forces 3 decimals on the float value of our voltage
  Serial.println(voltage, 3);
  delay(300);
}
