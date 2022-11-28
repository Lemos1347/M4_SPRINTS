#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <iostream>
#include <ESPAsyncWebServer.h>
#include <vector>
#include "AsyncJson.h"
#include "ArduinoJson.h"

AsyncWebServer server(3001);

using namespace std;

const int greenLed = 11;
const int redLed = 10;
const int yellowLed = 9;
const int blueLed = 46;
const int waitingLed = 8;
const int playingLed = 18;
const int buzzer = 3;

void handleStartEnd(){
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(blueLed, LOW);
  digitalWrite(waitingLed, HIGH);
  digitalWrite(playingLed, LOW);
  tone(buzzer, 5000, 1000);
  delay(1000);
}

void setupRouting() {
   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    handleStartEnd();
    request->send(200);
  });

  server.on(
    "/post",
    HTTP_POST,
    [](AsyncWebServerRequest * request){},
    NULL,
    [](AsyncWebServerRequest * request, uint8_t *data, size_t len, size_t index, size_t total) {
 
      for (size_t i = 0; i < len; i++) {
        Serial.write(data[i]);
      }

      char* dataDecoded = reinterpret_cast<char*>(data); 

      vector<int> sequencia;

      for (size_t i = 1; i < len - 2; i++) {
        sequencia.push_back(int(dataDecoded[i]) - 48);
      }

      if (sequencia.size() == 0) {
        request->send(404);
      }

      digitalWrite(waitingLed, LOW);
      digitalWrite(playingLed, HIGH);

      for (int i = 0; i < sequencia.size(); i++) {
        switch (sequencia[i])
        {
        case 1:
          tone(buzzer, 500, 750);
          digitalWrite(greenLed, HIGH);
          delay(750);
          digitalWrite(greenLed, LOW);
          break;
        
        case 2:
          tone(buzzer, 1500, 750);
          digitalWrite(redLed, HIGH);
          delay(750);
          digitalWrite(redLed, LOW);
          break;

        case 3:
          tone(buzzer, 3000, 750);
          digitalWrite(yellowLed, HIGH);
          delay(750);
          digitalWrite(yellowLed, LOW);
          break;
        
        case 4:
          tone(buzzer, 4000, 750);
          digitalWrite(blueLed, HIGH);
          delay(750);
          digitalWrite(blueLed, LOW);
          break;

        default:
          break;
        }
      }

      digitalWrite(waitingLed, HIGH);
      digitalWrite(playingLed, LOW);

      request->send(200);
  });
}

void setup(void) {
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(waitingLed, OUTPUT);
  pinMode(playingLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("Cel's Galaxy A53 5G", "qhvz8247");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  digitalWrite(waitingLed, HIGH);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  setupRouting();
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Methods", "DELETE, POST, GET, OPTIONS");
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Headers", "content-type");
  server.begin();
  }
void loop(void) {
  delay(2);//allow the cpu to switch to other tasks
}