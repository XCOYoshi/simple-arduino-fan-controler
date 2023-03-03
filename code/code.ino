#include <GyverMAX6675.h> // lib https://github.com/GyverLibs/GyverMAX6675

//pinaut interface to MAX6675
#define CLK_PIN 13 //sck
#define DATA_PIN  12 //S0
#define CS_PIN  10 //CS

GyverMAX6675<CLK_PIN, DATA_PIN, CS_PIN> sens;  // sens.readTemp to read sensore data sens.getTemp()is to get the temprature sens.getTempInt() to get the remp as init

// Relai outputs
const int relais1 = 2; // low is on
const int relais2 = 3; // low is on
const int relais3 = 4; // low is on
const int relais4 = 5; // low is on

//system storage
bool runfan1 = false;

//setings
const float startfanat = 35.00;
const float stopfanat = 30.00;

void setup() {
  Serial.begin(9600);
  
  // pin config
  pinMode(relais1, OUTPUT);
  pinMode(relais2, OUTPUT);
  pinMode(relais3, OUTPUT);
  pinMode(relais4, OUTPUT);

}

void loop() {

 if (sens.readTemp()){
   tempsenseandrunfan1(relais1, sens.getTemp(), startfanat, stopfanat);
   Serial.print(sens.getTemp());
   Serial.print("\n");
  };
 delay(1000);
  
}

void tempsenseandrunfan1(int relai, float temprature, int startfantmp, int stopfantmp){
  // temp sense
  if(temprature >= startfantmp){runfan1 = true;}
  if(temprature <= stopfantmp){runfan1 = false;}

  // run fan or turn of fan
  if(runfan1 == true){ 
                      digitalWrite(relai, LOW);}
  if(runfan1 == false){
                        digitalWrite(relai, HIGH);} 
  }
