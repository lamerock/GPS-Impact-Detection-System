# GPS-Impact-Detection-System
The GPS Impact Detection System detects impacts using an FSR, sends SMS alerts with GPS coordinates. It utilizes Arduino, TinyGPS++, and SoftwareSerial libraries for real-time monitoring and communication with GPS and GSM modules.

## Step-by-step instructions

### Hardware Components Required:
1. Arduino board (e.g., Arduino Uno)
2. GPS module (e.g., NEO-6M GPS module)
3. GSM module (e.g., SIM800L GSM module)
4. Force-sensitive resistor (FSR)
5. Jumper wires
6. USB cable for Arduino board power

## Step-by-step instructions

### Hardware Components Required:
1. Arduino board (e.g., Arduino Uno)
2. GPS module (e.g., NEO-6M GPS module)
3. GSM module (e.g., SIM800L GSM module)
4. Force-sensitive resistor (FSR)
5. Jumper wires
6. USB cable for Arduino board power

### Connections:
1. Connect the Arduino board to your computer using the USB cable for power.
2. Connect the GPS module to the Arduino board:
   - GPS Module RX pin (receive) to Arduino digital pin 2 (TX)
   - GPS Module TX pin (transmit) to Arduino digital pin 3 (RX)
   - GPS Module VCC pin to Arduino 5V pin
   - GPS Module GND pin to Arduino GND pin
3. Connect the GSM module to the Arduino board:
   - GSM Module RX pin (receive) to Arduino digital pin 9 (TX)
   - GSM Module TX pin (transmit) to Arduino digital pin 10 (RX)
   - GSM Module VCC pin to Arduino 5V pin
   - GSM Module GND pin to Arduino GND pin
4. Connect the Force-Sensitive Resistor (FSR) to the Arduino board:
   - Connect one leg of the FSR to Arduino analog pin A0
   - Connect the other leg of the FSR to Arduino 5V pin
   - Connect a 10kΩ resistor from the FSR leg connected to A0 to Arduino GND pin
