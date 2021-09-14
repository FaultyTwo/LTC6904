#include "LTC6904.h"

LTC6904::LTC6904(bool _adr){
  adr = 0x16 | byte(_adr); //i mean.. it works!
  Wire.begin();
}

void LTC6904::I2CTest(){
  //OCT = 0 freq = 1.5k, CLK channel only
  //if output isn't the same as this, then check your I2C bus connections
  firstFrame = 0b00000000;
  secondFrame = 0b00001010;
  write();
}

void LTC6904::outputConfig(byte _CNF){ // pass
  CNF = _CNF;
  if(CNF >= 0x04) //check for illegal conditions
    CNF = 0x00; //reset back to default mode
  secondFrame >>= 2; //shift to the right by 2
  secondFrame <<= 2; //shift to the left by 2
  secondFrame |= CNF; //or it back
  write();
}

void LTC6904::setOct(byte oct){ //why?
  if(oct > 15) //if oct were set in illegal range
    oct = 15; //just set it to the max range (15)
  if(oct < 0)
    oct = 0; //okay, now you are just being annoying
  firstFrame <<= 4; //shift to left 4 times
  firstFrame >>= 4; //shift to right 4 times
  firstFrame |= oct << 4; //go to right four time*/
  write();
}

void LTC6904::setDac(short dac){
  if(dac > 2048) //if dac is more than 2048
    dac = 2048;
  if(dac < 0) //if dac is in negative
    dac = 0;
  firstFrame >>= 4; //shift to right 4 times
  firstFrame <<= 4; //shift to left 4 times
  firstFrame |= dac >> 6; //shift dac to right by 6 to leave only DAC9 - DAC6
  //Serial.println(firstFrame,BIN);

  secondFrame <<= 6; //shift to left 6 times
  secondFrame >>= 6; //shift to right 6 times
  secondFrame |= dac << 2; //shift dac to left by 2 to leave only DAC5 - DAC0

  write(); //do your thing
}

void LTC6904::setFreq(float freq, byte power){ // should be float for precision
  /* Time to do some meth
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

  firstFrame = 0x00; //cleansing all values
  secondFrame = 0x00;
  
  firstFrame |= oct << 4; //first, shift oct into its position
  firstFrame |= dac >> 6; //second, shift dac to right by 6 to leave only DAC9 - DAC6

  secondFrame |= dac << 2; //third, shift dac to left by 2 to leave only DAC5 - DAC0
  secondFrame |= CNF; //last, add back CNF condition

  write(); //do your thing
}

void LTC6904::write(){
  Wire.beginTransmission(adr);
  Wire.write(firstFrame);
  Wire.write(secondFrame);
  Wire.endTransmission();
}
