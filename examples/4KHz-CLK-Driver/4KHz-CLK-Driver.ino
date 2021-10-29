/* 4KHz-CLK-Driver
 * Author: Chawin 'FaultyTwo' Treesugol
 * Date: 9/12/2021
 * FROM: https://github.com/FaultyTwo/LTC6904-arduino-lib
 * 
 * Desc: This is a very barebone usage example of this library
 * This will output 4kkHZ pulse signal (also known as tinnitus simulator).
 * 
 */

#include <LTC6904.h>

LTC6904 dvc(0); //0x16

void setup() {
  dvc.outputConfig(0x00);
  dvc.setFreq(4.0,3);
}

void loop() {

}
