#include <Arduino.h>
#include <AccelStepper.h>
#include <Sensor-Bibo.h>

//-----Hauptprogramm-----//

AccelStepper HL(1, 22, 23);
AccelStepper HR(1, 24, 25); 
AccelStepper VL(1, 26, 27); 
AccelStepper VR(1, 28, 29); 

int Gang;
int counter;

void setMotor(int pin, int v) // set up Motor 
{
  pinMode(pin, OUTPUT);     // SET PIN
  pinMode(pin + 1, OUTPUT);
  pinMode(pin + 2, OUTPUT); 

  digitalWrite(pin, v & 1 ? HIGH : LOW);     // WRITE PIN
  digitalWrite(pin + 1, v & 2 ? HIGH : LOW); 
  digitalWrite(pin + 2, v & 4 ? HIGH : LOW); 

  HL.setMaxSpeed(3000); // set Maxpeed
  HR.setMaxSpeed(3000); 
  VL.setMaxSpeed(3000); 
  VR.setMaxSpeed(3000); 

}


void setup() {
  Serial.begin(9600);
  Gang = 5;           // set up Motor 
  setMotor(30, Gang); 
  setMotor(33, Gang); 
  setMotor(36, Gang); 
  setMotor(39, Gang); 
}

void loop() {
  
  if(steering_value() >= 1) {
    
    VR.setSpeed(-1500);  
    VL.setSpeed(1500); 
    HR.setSpeed(-1500); 
    HL.setSpeed(1500); 

  }else{

    VR.setSpeed(3000);  
    VL.setSpeed(3000); 
    HR.setSpeed(3000); 
    HL.setSpeed(3000); 
  }

  VR.runSpeed(); 
  VL.runSpeed(); 
  HR.runSpeed(); 
  HL.runSpeed(); 
  
}