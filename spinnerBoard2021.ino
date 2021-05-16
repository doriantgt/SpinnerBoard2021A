#include "defualtComparesCodes.hpp"


//OUTPUT PINS
uint8_t chargeEnablePin;
uint8_t periphrialEnablePin;
//uint8_t boostEnablePin; //is this needed? //maybe tie to high logic

//INPUT PINS
uint8_t usbDetectPin;
uint8_t chargingBatPin;
uint8_t fullChargedBatPin;


//ANALOG INPUT PIN
uint8_t batteryReadPin = A3;

//TOUCH PINS
uint8_t touchPins [3] = {T2, T3, T5};
bool touchPinBool [3] = {true,true,true};
ButtonInterpreter myButtons [3] =  {ButtonInterpreter(defualtPressCodes, 3),
                                    ButtonInterpreter(defualtPressCodes, 3),
                                    ButtonInterpreter(defualtPressCodes, 3)
                                    };


ButtonInterpreter testButton(defualtPressCodes, 3); //this should be called button interpreter;

uint16_t threshold =25;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(usbDetectPin, INPUT);
  pinMode(chargingBatPin, INPUT);
  pinMode(fullChargedBatPin, INPUT);
  
  pinMode(chargeEnablePin, OUTPUT);
  pinMode(periphrialEnablePin, OUTPUT);




}

void loop() {

for(int i =0; i<3; i++){
  if ( touchRead(touchPins[i]) < threshold){
   delayMicroseconds(5); //Remove Ghost press
  if ( touchPins[i] < threshold){  
  touchPinBool[i] = true;  
  }}else{  touchPinBool[i] = false; }

myButtons[i].go(  touchPinBool[i] ,  millis() );
 }

 
    

//bool buttonState = digitalRead(pushButton);
float batteryVoltage = analogRead(batteryReadPin)*2;
    batteryVoltage /= 4096; 
Serial.println("battery voltage = " + (String)batteryVoltage);


}
