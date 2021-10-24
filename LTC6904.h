#ifndef LTC6904_h_ft
#define LTC6904_h_ft

#if (ARDUINO <  100) && !defined(MPIDE)
#error LTC6904 library requires Arduino 1.0 or later
#endif

#include "Arduino.h"
#include "Wire.h"

class LTC6904{
  public:
    LTC6904(bool _adr);
    void I2CTest(); //test if you connect I2C device properly
    void outputConfig(uint8_t _CNF); //set CNF flag, very useful
    void setFreq(float freq, uint8_t power); //allow some powering for advanced config
    void setOct(uint8_t oct);
    void setDac(short dac);
    uint8_t returnOct(); //why the hell does anyone need this?
    uint8_t returnCNF(); //ugh
    unsigned short returnDac(); //why do you need this again?
  private:
    void write();
    uint8_t CNF = 0x00; //CNF condition
    uint8_t adr; //I2C Address
    uint8_t firstFrame; //first byte transmission
    uint8_t secondFrame; //second byte transmission
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
