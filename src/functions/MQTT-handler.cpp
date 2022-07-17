#include "helper.h"

const char* MQTT_SERVER = "broker.hivemq.com"; //"test.mosquitto.org";
const char* MQTT_SERVER2 = "maqiatto.com";
WiFiClient CLIENT;
PubSubClient MQTT(CLIENT);

void initMQTT(){
    MQTT.setServer(MQTT_SERVER, 1883);
}

void reconnetMQTT() {
  while (!MQTT.connected()){
//  Serial.println("Connecting to the MQTT broker...");

  if (MQTT.connect("ESP8266")){
    // Serial.println("Connected successfully");
  }else{
    // Serial.print("Connection failed, rc=");
    // Serial.print(MQTT.state());
    // Serial.println(" ...trying to reconnect...");
    delay(3000);
    }
  }
}

void publishMQTT(char *msg, int th) {
    // Serial.print("Using JjQZFhodDDghISIALBYQNS8 topic. Delivering message: ");
    // Serial.println(*msg);
    if (th == 0) {
      MQTT.publish("JjQZFhodDDghISIALBYQNS8/temperature", msg);
    } else {
      MQTT.publish("JjQZFhodDDghISIALBYQNS8/humidity", msg);
    }
}

void loopMQTT() {
    if (!MQTT.connected()){
        reconnetMQTT();
    }
    MQTT.loop();
}