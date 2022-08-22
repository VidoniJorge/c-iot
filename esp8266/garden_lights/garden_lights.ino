#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
//#include <aREST.h>
#include <stdlib.h>
#include <string.h>
#include <EEPROM.h>


#define LISTEN_PORT 80


struct ConfigValue{
  int timeOn;
  int timeOff;
  int umbral;
};

struct ValidationStatus {
  String lastStatus;
  int valor;
  int difTime;
};

ConfigValue configValue;

static const uint8_t D0 = 16; //GPIO
int PIN_LED = D0;
int SENSOR_LIGHT = A0;
int UMBRAL_LIGHT = 500;
int DELAY_MIL = 500;
int TIME_ON = 14400; // in seconds --> 3600 x hora --> 4 horas --> 14400
int TIME_OFF = 28800; // in seconds
int valor;
String lastStatus = "nill";
int countSeconds = 0;


String statusLed = "on";

const char* homePage PROGMEM = "<style> #on { background-color: darkcyan; } #off { background-color: crimson; } </style> <html> <header> </header> <body> <form method=\"POST\" action=\"/\"> <button id=\"on\" name=\"led\" value=\"on\">ON</button> <button id=\"off\" name=\"led\" value=\"off\">OFF</button> </form> </body> </html>";
const char* configPage PROGMEM = "<html><head></head><body><form method=\"POST\" action=\"/config\"><br>Time on <input id=\"timeOn\" name=\"timeOn\" /><br>Time out<input id=\"timeOff\" name=\"timeOff\" /><br>umbral<input id=\"umbral\" name=\"umbral\" /><br><button id=\"accept\">accept</button></form></body></html>";


//WiFi
const char* ssid = "Home 7 2.4GHz";
const char* password = "QuenQuenTreu";

//Create instance of server
ESP8266WebServer server(LISTEN_PORT);


int ledControl(String command);

void hableRoot();
void hableConfig();
void viewData();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println( "Read from EEPROM: " );
  
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

  
  config_WiFi_STA();

  //Start Server
  server.on("/", hableRoot);
  server.on("/config", hableConfig);
  server.on("/view",viewData);
  server.begin();
  Serial.println("Server started!");
  
}

void config_WiFi_STA() {
  //Connect to WiFi
  Serial.println("Config Connecting...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println(time(0));
  }

  Serial.println('\n');
  Serial.println("WiFi connected!");
  Serial.println(WiFi.localIP());
}

double diffTime() {
  return countSeconds / 2;
}


void loop() {
  countSeconds++;
  valor =  analogRead(SENSOR_LIGHT);

  if (validateStatusOn()) {
    setStatusOn();
  }

  if (validateStatusOff()) {
    setStatusOff();
  }
  server.handleClient();
  delay(DELAY_MIL);
}

void hableRoot() {
  String ledStatus = server.arg("led");

  if (ledStatus == "on") {
    setStatusOn();
  } else {
    setStatusOff();
  }

  server.send(200, "text/html", homePage);

}

void hableConfig() {
  
  String timeOn = server.arg("timeOn");
  if (timeOn!=""){
    TIME_ON = atoi(timeOn.c_str());
  }
  
  String turnOff = server.arg("timeOff");
  if(turnOff!=""){
    TIME_OFF = atoi(turnOff.c_str());
  }
 
  String umbral = server.arg("umbral");
  if(umbral!=""){
    UMBRAL_LIGHT = atoi(umbral.c_str());
  }
 
  server.send(200, "text/html", configPage);
}

void viewData(){
  
  Serial.print("current value: ");
  Serial.println(valor);
  Serial.print("last value: ");
  Serial.println(lastStatus);
  Serial.print("dif time:");
  Serial.println(diffTime());
}

void setStatusOn() {
  countSeconds = 0;
  lastStatus = "on";
  digitalWrite(PIN_LED, HIGH);
}



boolean validateStatusOn() {
  return valor < UMBRAL_LIGHT &&
         ( (lastStatus == "off" && diffTime() > TIME_OFF ) || lastStatus == "nill");
}

void setStatusOff() {
  countSeconds = 0;
  lastStatus = "off";
  digitalWrite(PIN_LED, LOW);
}

boolean validateStatusOff() {
  return (valor > UMBRAL_LIGHT && diffTime() > TIME_ON && lastStatus == "on") ||
          (lastStatus == "on" && diffTime() > TIME_ON );
}
