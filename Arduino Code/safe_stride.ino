#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ESP8266-AP";
const char* password = "12345678";

#define IR_PIN     D5
#define TRIG_PIN   D6
#define ECHO_PIN   D7
#define BUZZER_PIN D3

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(IR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  WiFi.softAP(ssid, password);
  Serial.println("Access Point started");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());  // Default: 192.168.4.1

  server.on("/data", []() {
    String response = "";

    if (digitalRead(IR_PIN) == LOW) {
      
      digitalWrite(BUZZER_PIN, HIGH);
    } else {
      digitalWrite(BUZZER_PIN, LOW);
    }

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH, 20000);
    long distance = duration * 0.034 / 2;

    if (distance > 0 && distance < 100) {
      response = "Obstacle within " + String(distance) + " cm";
    }

    Serial.println(response);
    server.send(200, "text/plain", response);
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}