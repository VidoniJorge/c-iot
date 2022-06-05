#include <OneWire.h> 
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

int tempC;
const int sensorTemp = A0;
const int pinTemp = 2;
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS pinTemp 

// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup() {
  // start serial port 
  Serial.begin(9600); 
  Serial.println("Dallas Temperature IC Control Library Demo"); 
  // Start up the library 
  sensors.begin(); 
  lcd.begin(16,2);
}

void loop() { 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus 
  /********************************************************************/
  Serial.print(" Requesting temperatures..."); 
  sensors.requestTemperatures(); // Send the command to get temperature readings 
  Serial.println("DONE"); 
  /********************************************************************/
  Serial.print("Temperature is: "); 
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?  
  // You can have more than one DS18B20 on the same bus.  
  // 0 refers to the first IC on the wire 

  lcd.setCursor(0,0);
  lcd.write("Temporatura:") ;
  lcd.setCursor(0,1);
  lcd.print(sensors.getTempCByIndex(0));
  
  delay(1000); 
  
} 
