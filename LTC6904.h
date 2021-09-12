#ifndef LTC6904_h_ft
#define LTC6904_h_ft

#include "Arduino.h"
#include "Wire.h"

class LTC6904{
  public:
    LTC6904(bool _adr);
    void I2CTest(); //test if you connect I2C device properly
    void outputConfig(byte _CNF); //set CNF flag, very useful
    void setFreq(float freq, byte power); //allow some powering for advacned config
    void setOct(byte oct);
    void setDac(short dac);
  private:
    void write();
    byte CNF = 0x00; //CNF condition
    byte adr; //I2C Address
    byte firstFrame; //first byte transmission
    byte secondFrame; //second byte transmission
};

/* what does LTC6904 functionality needs
 * - Only has 2 addresses because fuck you that's why
 * - A function for accepting frequency value (in kHz?)
 * - Manually writing frequency with OCT and DAC
 *  - Must have some foolproof code to make sure OCT doesn't go overboard or go lower deck
 *  - DAC must be in range of 2048, beyond or lower than that is dead sentences
 *  - A calculation function for calculating stuffs
 */

#endif
