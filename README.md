# Arduino Gilson Micropulse Control

This platformio project allows you to control a DC motor using simple single-character commands sent over the serial monitor. The code provides control over:

1. **Direction** (clockwise or counterclockwise)  
2. **Run/Stop** (motor on or off)  
3. **Speed** (via PWM)

## Hardware

Note, the PWM output must be fed through a simple low pass filter (4-5hz), something like a 150Ohm resistor in series with the port, then a 220uF cap in parralell with ground

```
            150Ohm
Arduino >---/\/\/\--------------> Gilson analog in
                        |
                      __|__ 
                      _____ 220uF
                        |
                        |
Arduino GND >-------------------> Gilson GND                      
```
---

## Software Setup

1. **VSCODE IDE**  
   - Open the project VScode Platformio IDE.  
   - Config the platformio 

2. **Serial Baud Rate**  
   - Ensure your platformio Monitor is also set to **9600 baud**.

---

## Usage

1. **Open a Serial Monitor**.
2. **Set the baud rate** to **9600**.
3. **Enter single-character commands** to control the motor:

   - **L**: Set direction to **Clockwise**  
   - **R**: Set direction to **Counterclockwise**  
   - **S**: Run (enable) the motor  
   - **O**: Stop (disable) the motor  
   - **0**: Set PWM speed to **25**  
   - **1**: Set PWM speed to **50**  
   - **2**: Set PWM speed to **75**  
   - **3**: Set PWM speed to **100**  
   - **4**: Set PWM speed to **125**  
   - **5**: Set PWM speed to **150**  
   - **6**: Set PWM speed to **175**  
   - **7**: Set PWM speed to **200**  
   - **8**: Set PWM speed to **225**  
   - **9**: Set PWM speed to **255**  
   - **?**: Returns motor status EG  e.g. **RUNNING, CW, 125**
