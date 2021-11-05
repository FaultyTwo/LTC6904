/* 4KHz-CLK-Driver
 * Author: Chawin 'FaultyTwo' Treesugol
 * Date: 11/5/2021
 * FROM: https://github.com/FaultyTwo/LTC6904-arduino-lib
 * 
 * Desc: This is a very barebone usage example of this library
 * This will output 4kHZ pulse signal.
 * 
 * Hope you didn't connect a speaker to the device
 */

#include <LTC6904.h>

LTC6904 dvc(0); //0x16

void setup() {
  dvc.begin();
  dvc.outputConfig(0x00);
  dvc.setFreq(4.0,3);
}

void loop() {

}
