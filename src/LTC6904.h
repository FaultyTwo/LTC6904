/* 
   LTC6904 - Arduino Library for LTC6904, 1kHz to 68MHz I2C Programmable Oscillator.
   By: Chawin 'FaultyTwo' Treesugol <https://github.com/FaultyTwo/LTC6904-arduino-lib>
*/

#ifndef LTC6904_h_ft
#define LTC6904_h_ft

#include "Arduino.h"
#include "Wire.h"

// using boolean for specifying address is a no-no
// use value instead to make it clear

/// @brief A LTC6904 class
class LTC6904{
  public:
    /// @brief Specify the LTC6904 device
    /// @param adr The i2c address of LTC6904
    LTC6904(uint8_t adr);
    /// @brief Initial a LTC6904 device
    /// @param wire A TwoWire object, leave blank for default
    void begin(TwoWire &wire = Wire);
    /// @brief Configure the output
    /// @param CNF Conditional flag value
    /// @note https://github.com/FaultyTwo/LTC6904-arduino-lib
    void outputConfig(uint8_t CNF);
    /// @brief Set the frequency of the output
    /// @param freq The frequency value
    /// @param power The exponential value
    void setFreq(float freq, uint8_t power);
    /// @brief Set the 'OCT' parameter
    /// @param oct The 'OCT' value
    void setOct(uint8_t oct);
    /// @brief Set the 'DAC' parameter
    /// @param dac The 'DAC' value
    void setDac(unsigned short dac);
  private:
    void write();
    TwoWire *_wire;
    uint8_t _CNF = 0x00; //CNF condition
    uint8_t _adr; //I2C Address
    uint8_t firstFrame, secondFrame; // internal frame memory
};

#endif
