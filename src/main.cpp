#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <../include/pubsubclient-master/src/PubSubClient.h>
#include <../include/DHT_sensor_library_for_ESPx-1.18.0/DHTesp.h>

const char* SSID = "#########"; // SSID da Rede WIFI
const char* PASSWORD = "#########"; // Senha da Rede WIFI
const char* MQTT_SERVER = "test.mosquitto.org"; //Broker do Mosquitto.org
const char* MQTT_SERVER2 = "maqiatto.com";
int value = 0;
long lastMsg = 0;
char msg[50];
WiFiClient CLIENT;
PubSubClient MQTT(CLIENT);

// SETTING UP WIRELESS NETWORK
void setupWIFI(){
  WiFi.begin(SSID, PASSWORD);
  Serial.print("Connecting to: "); Serial.println(SSID);

  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
}

void setup(void){
  Serial.begin(115200);
  setupWIFI();
  MQTT.setServer(MQTT_SERVER, 1883);
}

void reconnet(){
  while (!MQTT.connected()){
  Serial.println("Connecting to the MQTT broker...");

  if (MQTT.connect("ESP8266")){
    Serial.println("Connected successfully");
  }else{
    Serial.print("Connection failed, rc=");
    Serial.print(MQTT.state());
    Serial.println(" ...trying to reconnect...");
    delay(3000);
    }
  }
}

void loop(void) {
  if (!MQTT.connected()){
    reconnet();
  }

MQTT.loop();
long now = millis();

if (now - lastMsg > 2000){
  lastMsg = now;
  value++;
  if(value >=50) value = -20;
  snprintf (msg, 75, "%ld", value);
  Serial.print("Using temp/random topic. Delivering message: ");
  Serial.println(msg);
  MQTT.publish("temp/random", msg);
  }
}
