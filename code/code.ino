#include <GyverGFX.h> //lib https://github.com/GyverLibs/GyverGFX
#include <GyverMAX6675.h> // lib https://github.com/GyverLibs/GyverMAX6675

//setings
const int startfanat = 40;
const int stopfanat = 28;

//spi interface to MAX6675
const int CLK_PIN = 13; //sck
const int DATA_PIN = 12; //S0
const int CS_PIN = 10; //CS

GyverMAX6675<CLK_PIN, DATA_PIN, CS_PIN> sens;  // sens.readTemp to read sensore data sens.getTemp()is to get the temprature sens.getTempInt() to get the remp as init

// Relai outputs
const int relais1 = 2; // low is on
const int relais2 = 3; // low is on
const int relais3 = 4; // low is on
const int relais4 = 5; // low is on

//system storage
bool runfan = false;

void setup() {
  pinMode(relais1, OUTPUT);
  pinMode(relais2, OUTPUT);
  pinMode(relais3, OUTPUT);
  pinMode(relais4, OUTPUT);

}

void loop() {
  // temp sense
  if(sens.getTempInt() >= startfanat){runfan = true;}
  if(sens.getTempInt() <= stopfanat){runfan = true;}

  // run fan or turn of fan
  if(runfan == true){digitalWrite(relais1, LOW);}
  if(runfan == false){digitalWrite(relais1, HIGH);}
  
}
