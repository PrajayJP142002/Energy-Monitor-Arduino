#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

float sensitivity = 0.100;
float zeropoint = 2.5;

void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop(){
  // Current Sensor (A0)
  int raw = analogRead(A0);
  float voltage = raw*(5.0/1023.0);
  float current = (voltage-zeropoint)/sensitivity;

  // Voltage Sensor (A1)
  int rawV = analogRead(A1);
  float sensorV = rawV*(5.0/1023.0);
  float Voltage = sensorV*5.0;

  // Power and Energy
  float power = Voltage*current;
  unsigned long time = millis();
  float energy = power*(time/3600000.0);
  float kwh = energy/1000.0;

  // LCD Display
  lcd.setCursor(0,0);
  lcd.print("I:");
  lcd.print(current,2);
  lcd.print("A V:");
  lcd.print(Voltage,2);
  lcd.print("V");

  lcd.setCursor(0,1);
  lcd.print("P:");
  lcd.print(power,1);
  lcd.print("W E:");
  lcd.print(energy,2);
  lcd.print("Wh");

  // Serial Monitor
  Serial.print("current:");
  Serial.print(current,2);
  Serial.println("A");
  Serial.print("Voltage:");
  Serial.print(Voltage,2);
  Serial.println("V");
  Serial.print("power:");
  Serial.print(power,2);
  Serial.println("W");
  Serial.print("energy:");
  Serial.print(energy,2);
  Serial.println("Wh");
  Serial.print("kwh:");
  Serial.print(kwh,2);
  Serial.println("kWh");

  delay(500);
}
