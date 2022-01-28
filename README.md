# LTC6904
An Arduino Library for LTC6904, 1kHz to 68MHz I2C Programmable Oscillator.

For more technical details, please refer to the [datasheet.](https://www.analog.com/media/en/technical-documentation/data-sheets/69034fe.pdf)

## How To Use The Library
Since LTC6904 only has two I2C addresses. To create an object, just use Boolean in the constructor method like this:
```C
LTC6904 clk(0); //0x16
LTC6904 clk2(1); //0x17
```

Then in the setup function of Arduino IDE:
```C
void setup(){
	clk.begin();
	clk2.begin();
	...
```

To use this library with other I2C ports, you can simply create a TwoWire object then parse it into the 'begin' function:
```C
// ESP32
#define I2C_SDA 33
#define I2C_SCL 32

TwoWire esp = TwoWire(0);
LTC6904 clk(0);

void setup(){
  esp.begin(I2C_SDA, I2C_SCL, 1000000);
  clk.begin(&esp);
}
```

## Methods
```C
void begin();
```
Initiate the LTC6904 library.

```C++
void setFreq(float freq, uint8_t power)
```
Set frequency rate of LTC6904.

**Where:**<br>
- freq: Your frequency value in decimal.
- power: Exponential of your frequency value (based off science notation).

Ex. 6.83 KHz -> setFreq(6.83,3);<br> **(6.83x10^3)**<br>
Ex. 12.54 MHz -> setFreq(12.54,6);<br> **(12.54x10^6)**

```C++
void setOct(uint8_t oct)
```
Set 'OCT' value of LTC6904.<br>
**^OCT should be in range of 0 to 15.**

```C++
void setDac(short dac)
```
Set 'DAC' value of LTC6904.<br>
**^DAC should be in range of 0 to 1023.**

```C++
void outputConfig(uint8_t _CNF)
```
Config outputs of LTC6904.

| _CNF value  | CLK | ~CLK |
| ------------- | ------------- | ------------- |
| 0x00  | CLK  | CLK + 180 |
| 0x01  | OFF  | ON |
| 0x02  | ON   | OFF |
| 0x03  | Powered-Down | Powered-Down |

***Beyond than 0x03 will set output back to 0x00**

```C++
uint8_t returnOct()
```
Return OCT value.<br>

```C++
unsigned short returnDac()
```
Return DAC value.<br>

```C++
uint8_t returnCNF()
```
Return CNF value.<br>
