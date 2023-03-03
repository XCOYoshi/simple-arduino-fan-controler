#include <GyverGFX.h> //lib https://github.com/GyverLibs/GyverGFX
#include <GyverMAX6675.h> // lib https://github.com/GyverLibs/GyverMAX6675

//setings
const int startfanat = 40;
const int stopfanat = 28;

//pinaut interface to MAX6675
#define CLK_PIN 8 //sck
#define DATA_PIN  7 //S0
#define CS_PIN  6 //CS

GyverMAX6675<CLK_PIN, DATA_PIN, CS_PIN> sens;  // sens.readTemp to read sensore data sens.getTemp()is to get the temprature sens.getTempInt() to get the remp as init

// Relai outputs
const int relais1 = 2; // low is on
const int relais2 = 3; // low is on
const int relais3 = 4; // low is on
const int relais4 = 5; // low is on

//aux outputs
const int onboardled = 13;

//system storage
bool runfan1 = false;

void setup() {
  Serial.begin(9600);
  
  // pin config
  pinMode(relais1, OUTPUT);
  pinMode(relais2, OUTPUT);
  pinMode(relais3, OUTPUT);
  pinMode(relais4, OUTPUT);
  pinMode(onboardled, OUTPUT);

}

void loop() {
  Serial.print(runfan1);
  tempsenseandrunfan1(relais1, sens.getTempInt(), startfanat, stopfanat);

  
}

void tempsenseandrunfan1(int relai, int temprature, int startfantmp, int stopfantmp){
  // temp sense
  if(temprature >= startfantmp){runfan1 = true;}
  if(temprature <= stopfantmp){runfan1 = false;}

  // run fan or turn of fan
  if(runfan1 == true){ 
                      digitalWrite(relai, LOW);
                      digitalWrite(onboardled, LOW);}
  if(runfan1 == false){
                        digitalWrite(relai, HIGH); 
                        digitalWrite(onboardled, HIGH);}
  }
