#include <LTC6904.h>

LTC6904 dvc(0); //0x16

void setup() {
  dvc.outputConfig(0x00);
  dvc.setFreq(4.0,3);
}

void loop() { //hello, i am useless

}
