#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>


const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";

const char* API_URL = "http://andre-savedra-turmab-iiot-app.azurewebsites.net/data";
const char* WRITE_API_KEY = "4247cca7-12cd-47d0-9ba8-a9a248a7003d";
const char* SENSOR_ID = "9a99028c-adda-49ee-9630-ee7370129154";

unsigned long timer;


void setup() {
  Serial.begin(115200);  
  Serial.println("Connecting to wifi...");
  wifiConnect();
  
  Serial.println("IIOT application started!");
}

void loop() {
  if(timeout(5)){
    readDataAndSend();
    timer = millis();
  }
}

void readDataAndSend(){
  Serial.println("Start Reading data...");
  float temp = readTemperature();
  float hum = readHumidity();
  
  Serial.println("Start Sending data...");
  sendData(temp, hum);
}

//IMPLEMENTAR
float readTemperature(){
  float temp = random(20,50);
  Serial.printf("Temp: %.2f \n", temp);
  return temp;
}

//IMPLEMENTAR
float readHumidity(){
  float hum = random(0,100);
  Serial.printf("hum: %.2f \n", hum);
  return hum;
}

void sendData(float temp, float hum){
  StaticJsonDocument<128> payload;
  payload["sensorId"] = SENSOR_ID;
  payload["jsonValue"] = "{\"temperature\":" + String(temp) 
  + ",\"humidity\":" + String(hum) + "}";

  char bodyJsonString[255];
  serializeJson(payload, bodyJsonString);
  Serial.printf("Data to be sent: %s \n", bodyJsonString);

  WiFiClient wifiClient;
  HTTPClient http;
  http.begin(wifiClient,API_URL);
  http.addHeader("Content-Type","application/json");
  http.addHeader("X-API-KEY",WRITE_API_KEY);

  int httpResponse = http.POST(bodyJsonString);
  if(httpResponse > 0){
    Serial.printf("Response received: %d \n", httpResponse);
    if(httpResponse == 201){
      Serial.println("Data was successfully sent!!!");
    }
  }
  else{
    Serial.println("Data wasn't sent, internal error!");
  }
  http.end();
}

void wifiConnect(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, 6);
  int tries = 0;

  while(WiFi.status() != WL_CONNECTED && tries < 5){
    delay(500);
    Serial.println("...");
    tries++;
  }

  if(WiFi.status() == WL_CONNECTED){
    Serial.println("Wifi successfully connected!");
    Serial.println(WiFi.localIP().toString());
  }
  else{
    Serial.println("IIOT board wasn't able to connect to wifi!");
  }

}

boolean timeout(int timing_sec){
    return (millis()-timer)>= (timing_sec * 1000);
}