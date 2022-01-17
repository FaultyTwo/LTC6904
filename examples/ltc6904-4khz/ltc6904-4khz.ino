/* ltc6904-4khz
 * Author: Chawin 'FaultyTwo' Treesugol
 * Date: 11/20/2021
 * FROM: https://github.com/FaultyTwo/LTC6904-arduino-lib
 * 
 * Desc:
 * This is a very barebone usage example of LTC6904
 * 
 * Enjoy!
 */

#include <LTC6904.h>

LTC6904 dvc(0); //0x16

void setup() {
  dvc.begin();
  Serial.begin(9600);
  dvc.outputConfig(0x02); //turn off ~CLK output
  dvc.setFreq(4.0,3);
  delay(1000);
  Serial.print("DAC: ");
  Serial.println(dvc.returnDac());
  Serial.print("OCT: ");
  Serial.println(dvc.returnOct());
  Serial.print("CNF: ");
  Serial.println(dvc.returnCNF());
}

void loop() {

}
