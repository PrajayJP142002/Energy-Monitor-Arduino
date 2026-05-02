# Energy Monitor — Arduino

## What it does
Measures real-time current, voltage, power 
and energy consumption using ACS712 current 
sensor and voltage sensor, displayed on I2C 
LCD screen.

## Formulas used
- Current: I = (V - 2.5) / 0.1
- Power:   P = V × I  
- Energy:  E = P × T
- kWh:     E / 1000

## Hardware
- Arduino Uno
- ACS712 20A Current Sensor
- 25V Voltage Sensor Module
- 16x2 I2C LCD Display

## Simulation
[Click here to view Wokwi simulation](https://wokwi.com/projects/462812267097192449)

## Status
- Simulation complete ✅
- Hardware testing in progress 🔄
