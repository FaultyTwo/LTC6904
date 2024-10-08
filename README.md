# LTC6904
Arduino Library for LTC6904, 1kHz to 68MHz I2C Programmable Oscillator.

For more technical details, please refer to the [datasheet.](https://www.analog.com/media/en/technical-documentation/data-sheets/69034fe.pdf)

## How To Use The Library
Include the library, then simply create an object according to each device address, like this:
```C
#include <LTC6904.h>
LTC6904 clk(0x16);
LTC6904 clk2(0x17);
```

To use this library with other I2C ports, you can simply create a TwoWire object then parse it into the 'begin' function:
```C
// ESP32
#define I2C_SDA 33
#define I2C_SCL 32

TwoWire esp = TwoWire(0);
LTC6904 clk(0x16);

void setup(){
  esp.begin(I2C_SDA, I2C_SCL, 1000000);
  clk.begin(&esp);
}
```

## Methods
```C
void begin(TwoWire &wire = Wire);
```
Initiate the LTC6904 library.

Can be configured to use other I2C ports from a 'TwoWire' object.<br>
For default I2C port, just leave the parameter blank.

```C
void setFreq(float freq, uint8_t power)
```
Set frequency value of LTC6904. 
- 'freq': The frequency value in decimal.
- 'power': The exponential value by the power of 10.

**Ex.** 6.83 KHz -> setFreq(6.83,3);<br> **(6.83x10^3)**<br>
**Ex.** 12.54 MHz -> setFreq(12.54,6);<br> **(12.54x10^6)**

**^If the value is lower than 1kHz, the value will be set back to 1kHz instead.**<br>
**^If the value is higher than 68MHz, the value will be set back to 68MHz instead.**

```C
void setOct(uint8_t oct)
```
Set the 'OCT' parameter.<br>
**^'OCT' shouldn't exceed 15, otherwise will be set back to 15.**

```C
void setDac(unsigned short dac)
```
Set the 'DAC' parameter.<br>
**^'DAC' shouldn't exceed 1023, otherwise will be set back to 1023.**

```C
void outputConfig(uint8_t _CNF)
```
Configure outputs of LTC6904.

| _CNF value  | CLK | ~CLK |
| ------------- | ------------- | ------------- |
| 0x00  | CLK  | CLK + 180 |
| 0x01  | OFF  | ON |
| 0x02  | ON   | OFF |
| 0x03  | Powered-down | Powered-down |

**^Beyond than 0x03 will set output back to 0x00**

```C
uint8_t getOct()
```
Get the 'OCT' value

```C
unsigned short getDac()
```
Get the 'DAC' value

```C
uint8_t getCNF()
```
Get the 'CNF' value