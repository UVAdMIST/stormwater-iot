/*Feel free to use this code.
Author: Tom Bonar
Date: 12-11-2013
Analog pin 1 for reading in the analog voltage from the MaxSonar device.
This variable is a constant because the pin will not change throughout execution of this code.*/
const int anPin = 0;
long anVolt, cm;
void setup() {
  //This opens up a serial connection to shoot the results back to the PC console
  Serial.begin(9600);
}

void loop() {
  {
    //Used to read in the analog voltage output that is being sent by the XL-MaxSonar device.
    //Scale factor is (Vcc/1024) per centimeter. A 5V supply yields ~4.9mV/cm for standard range sensors
    anVolt = analogRead(anPin); // this is for the standard range sensors
  }  
  cm = anVolt;
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(1000);
}
