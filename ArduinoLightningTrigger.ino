//The DIY Life
//Michael Klements
//13 December 2016

int shutterPin = 9;  //Assign the LDR and optocoupler pins
int triggerPin = A5;
int triggerPointPin = A4;
int triggered =0;
int triggerPoint = 0;

void setup() 
{ 
  pinMode(shutterPin,OUTPUT);    //Define the shutter pin as an output
  digitalWrite(shutterPin,LOW);  //Set the shutter pin to low / off / no voltage
}

void loop() 
{ 
  triggered = map(analogRead(triggerPin), 0, 1023, 0, 1023);  //Read the output from the LDR
  if (triggered >= triggerPoint)  //If light is detected, trigger the camera
  {
    delay(50);    //Wait for lightning to be the brightest
    digitalWrite(shutterPin,HIGH);  //Trigger camera
    delay(1000);
    digitalWrite(shutterPin,LOW);   //Reset camera trigger output for next photo
    triggered = 0;
  }
  triggerPoint = map(analogRead(triggerPointPin), 0, 1023, 0, 1023); //Read the output from the potentiometer
}
