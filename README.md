## LTC6904
An Arduino Library for LTC6904, 1kHz to 68MHz I2C Programmable Oscillator.

For more technical details, please refer to the [datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/69034fe.pdf)

## How To Use The Library
Since LTC6904 only has two I2C addresses. To create an object, just use Boolean in the constructor like this:
```C
LTC6904 clk(0); //0x16
LTC6904 clk(1); //0x17
```

### Necessary Function
```C
setFreq(float freq, byte power)
```
Set frequency rate for LTC6904.

Where:
freq - Your frequency value in decimal.
power - Exponential of your frequency value (based off science notation).
Ex. 6.83 KHz -> setFreq(6.83,3); **(6.83x10^3)**
Ex. 12.54 MHz -> setFreq(12.54,6); **(12.54x10^6)**

```C
setOct(byte oct)
```
Set 'OCT' value for LTC6904.
*OCT should be in range of 0 to 15.

```C
setDac(short dac)
```
Set 'DAC' value for LTC6904.
*DAC should be in range of 0 to 2048.

```C
outputConfig(byte _CNF)
```
Config output of LTC6904.

| _CNF value  | CLK | ~CLK|
| ------------- | ------------- | ------------- |
| 0x00  | CLK  | CLK + 180 |
| 0x01  | OFF  | ON |
| 0x02  | ON   | OFF |
| 0x03  | Powered-Down | Powered-Down |

*Beyond than 0x03 will set output back to 0x00