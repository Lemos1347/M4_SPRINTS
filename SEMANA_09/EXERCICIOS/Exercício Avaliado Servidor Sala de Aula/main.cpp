#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>

int button = 9;

void postDataToServer(String mensagem)
{
  Serial.println("Encriptando a mensagem...");

  // encoding the message
  int x;
  String encodedMessage;
  for (int i = 0; i < mensagem.length(); i++)
  {
    x = mensagem[i];
    x += 2;
    encodedMessage += char(x);
  }

  // tying to decode the message
  int y;
  String decodedMessage;
  for (int i = 0; i < mensagem.length(); i++)
  {
    y = encodedMessage[i];
    y -= 2;
    decodedMessage += char(y);
  }
  Serial.print("Mensagem descriptografada --> ");
  Serial.println(decodedMessage);

  Serial.println("Posting JSON data to server...");
  HTTPClient http;

  http.begin("https://ur524n-3000.preview.csb.app/teobaldo");
  http.addHeader("Content-Type", "application/json");

  StaticJsonDocument<200> doc;

  doc["Nome do Aluno"] = "Henrique Lemos Freire Matias";
  doc["Turma"] = "Turma 1";
  doc["Grupo"] = "Grupo 1";
  doc["Mensagem em texto"] = mensagem;
  doc["Mensagem criptografada"] = encodedMessage;

  String requestBody;
  serializeJson(doc, requestBody);

  int httpResponseCode = http.POST(requestBody);

  if (httpResponseCode > 0)
  {

    String response = http.getString();

    Serial.println(httpResponseCode);
    Serial.println(response);
  }
}

void setup()
{
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin("Cel's Galaxy A53 5G", "qhvz8247");
  delay(300);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  Serial.println("Rede conectada!");
}

void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin("Paulo", "pauleradixzz");
    Serial.println("Tentando se conectar...");
    delay(300);
  }
  if (digitalRead(button) == 0)
  {
    postDataToServer("Minha mensagem secreta");
  }
  delay(10);
}
