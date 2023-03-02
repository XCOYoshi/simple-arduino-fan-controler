#include <GyverMAX6675.h>

#define CLK_PIN   13
#define DATA_PIN  12
#define CS_PIN    10

GyverMAX6675<CLK_PIN, DATA_PIN, CS_PIN> sens;  // sens.readTemp to read sensore data sens.getTemp()is to get the temprature sens.getTempInt() to get the remp as init

void setup() {
  // put your setup code here, to run once:

}

void loop() {
 
}
