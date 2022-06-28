#include "LTC6904.h"

LTC6904::LTC6904(bool adr){
  _adr = 0x16 | uint8_t(adr); //i mean.. it works!
}

void LTC6904::begin(TwoWire &yourWire){
  _wire = &yourWire;
  _wire->begin();
}

void LTC6904::outputConfig(uint8_t CNF){ // pass
  _CNF = CNF;
  if(_CNF >= 0x04) //check for illegal conditions
    _CNF = 0x00; //reset back to default mode
  secondFrame = ((secondFrame >> 2) << 2) | _CNF;
  write();
}

void LTC6904::setOct(uint8_t oct){ //why?
  if(oct > 15) //illegal condition
    oct = 15;
  firstFrame = ((firstFrame << 4) >> 4) | (oct << 4);
  write();
}

void LTC6904::setDac(unsigned short dac){
  if(dac >= 1024)
    dac = 1023;
  firstFrame = ((firstFrame >> 4) << 4) | (dac >> 6);
  secondFrame = ((secondFrame << 6) >> 6) | (dac << 2);
  write();
}

void LTC6904::setFreq(float freq, uint8_t power){ // should be float for precision
  /* "Mr whote, whee is my 20003 km/h of methe???"
   * OCT = 3.322(log(freq/1039));
   * DAC = 2048 * 2078 * 2^10 / f;
   * use short to save those poor bytes
   */
  float fre = freq*pow(10,power);
  
  if(fre < 1.039*pow(10,3)) //bs handling
    fre = 1.039*pow(10,3); 
  if(fre >= 68.03*pow(10,6)) //bs handling
    fre = 68.03*pow(10,6); 
  
  short oct = short(floor(3.322*log10(float(fre/1039.0))));
  short dac = short(round(2048-((2078.0*pow(2,10))/fre)));

  firstFrame = secondFrame = 0x00; //clease all value
  firstFrame = (oct << 4) | (dac >> 6);
  secondFrame = (dac << 2) | _CNF;
  write();
}

void LTC6904::write(){
  _wire->beginTransmission(_adr);
  _wire->write(firstFrame);
  _wire->write(secondFrame);
  _wire->endTransmission();
}
