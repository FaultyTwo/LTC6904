/* ltc6904-getinfo
 * Author: Chawin 'FaultyTwo' Treesugol
 * Date: 10/08/2024
 * FROM: https://github.com/FaultyTwo/LTC6904-arduino-lib
 * 
 * Desc: A simple sketch file for testing 'OCT', 'DAC' and 'CNF' value
 * 
 * Enjoy!
 */

#include <LTC6904.h>

LTC6904 dvc(0x16);

void setup() {

  randomSeed(analogRead(0));
  dvc.begin();
  Serial.begin(9600);

  dvc.outputConfig(random(0, 4));
  dvc.setFreq(random(10, 1000),random(3, 6));
  delay(1000);
  Serial.println("OCT: %d", dvc.getOct());
  Serial.println("DAC: %d", dvc.getDac());
  Serial.println("CNF: %d", dvc.getCNF());
  
}

void loop() {

}
