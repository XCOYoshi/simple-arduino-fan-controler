#include <GyverGFX.h> //lib https://github.com/GyverLibs/GyverGFX
#include <GyverMAX6675.h> // lib https://github.com/GyverLibs/GyverMAX6675

#define CLK_PIN  13
#define DATA_PIN  12
#define CS_PIN    10

GyverMAX6675<CLK_PIN, DATA_PIN, CS_PIN> sens;  // sens.readTemp to read sensore data sens.getTemp()is to get the temprature sens.getTempInt() to get the remp as init

const int relais1 = 2;
const int relais2 = 3;
const int relais3 = 4;
const int relais4 = 5;
void setup() {
  pinMode(relais1, OUTPUT);
  pinMode(relais2, OUTPUT);
  pinMode(relais3, OUTPUT);
  pinMode(relais4, OUTPUT);

}

void loop() {
  digitalWrite(relais1, HIGH);
  digitalWrite(relais2, HIGH);
  digitalWrite(relais3, HIGH);
  digitalWrite(relais4, HIGH);
 
}
