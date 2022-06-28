#ifndef LTC6904_h_ft
#define LTC6904_h_ft

#include "Arduino.h"
#include "Wire.h"

class LTC6904{
  public:
    LTC6904(bool adr);
    void outputConfig(uint8_t CNF); //set CNF flag, very useful
    void setFreq(float freq, uint8_t power); //allow some powering for better adjustment
    void setOct(uint8_t oct);
    void setDac(unsigned short dac);
    void begin(TwoWire &yourWire = Wire);
  private:
    void write();
    TwoWire *_wire;
    uint8_t _CNF = 0x00; //CNF condition
    uint8_t _adr; //I2C Address
    uint8_t firstFrame, secondFrame;
    //ltc6904 doesn't have read register
};

#endif
