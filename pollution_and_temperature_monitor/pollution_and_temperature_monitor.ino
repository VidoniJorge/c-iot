//Lib
#include "ESP8266WiFi.h"
#include <aREST.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

//Def
static const uint8_t D5   = 14;
#define DHTPIN D5
#define DHTTYPE DHT22
#define MQ A0

//Init
DHT dht(DHTPIN, DHTTYPE);

//aRest
aREST rest = aREST();

//WiFi
const char* ssid = "Home 7 2.4GHz";
const char* password = "QuenQuenTreu";

//Port
#define LISTEN_PORT 80

//Create instance of server
WiFiServer server(LISTEN_PORT);

//Variables API
float mq, humidity, temperature;

void setup() {
  Serial.begin(9600);
  dht.begin();

  config_Rest();
  
  config_WiFi_STA();

}

void config_Rest() {
  //Init Variables API
  rest.variable("temperature", &temperature);
  rest.variable("humidity", &humidity);
  rest.variable("contaminacion", &mq);

  //Name Id
  rest.set_id("1");
  rest.set_name("sensor_wemos");
}

void config_WiFi_STA() {
  //Connect to WiFi
  Serial.println("Config Connecting...");
  //WiFi.mode(WIFI_AP);
  WiFi.mode(WIFI_STA);
  
  WiFi.begin("Home 7 2.4GHz", "QuenQuenTreu");
  Serial.println("Connecting...");
  int i = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(++i); 
    Serial.print(".");
  }

  Serial.println('\n');
  Serial.println("WiFi connected!");
  Serial.println(WiFi.localIP());

  //Start Server
  server.begin();
  Serial.println("Server started!");
}

void loop() {
  //Wait 1s
  delay(1000);
  Serial.println("WiFi connected!");
  Serial.println(WiFi.localIP());

  mq = analogRead(MQ); //MQ135
  humidity = dht.readHumidity(); //RH %0 - 100 (punto de rocio)
  temperature = dht.readTemperature(); //0 - 100 ºC

  Serial.print("mq: "); 
  Serial.println(mq); 
  Serial.print("humidity: ");
  Serial.println(humidity); 
  Serial.print("temperature: ");
  Serial.println(temperature);
  
  //Rest Call
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while (!client.available()) {
    delay(1);
  }
  rest.handle(client);
}
