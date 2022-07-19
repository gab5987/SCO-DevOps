#include "helper.h"

const char* MQTT_SERVER = "broker.hivemq.com";
const char* MQTT_SERVER2 = "maqiatto.com";
WiFiClient CLIENT;
PubSubClient MQTT(CLIENT);

String message;

void initMQTT(){
    MQTT.setServer(MQTT_SERVER, 1883);
    MQTT.setCallback(feedbackMQTT);
    MQTT.subscribe("JjQZFhodDDghISIALBYQNS8/feedback");
}

void reconnetMQTT() {
  while (!MQTT.connected()){

  if (MQTT.connect("ESP8266")){
  }else{
    delay(3000);
    }
  MQTT.setCallback(feedbackMQTT);
  MQTT.subscribe("JjQZFhodDDghISIALBYQNS8/feedback");
  }
}

void publishMQTT(String msg) {
  char buf[50];
  msg.toCharArray(buf, 50);
  MQTT.publish("JjQZFhodDDghISIALBYQNS8/SCO", buf);
}

void loopMQTT() {
    if (!MQTT.connected()){
        reconnetMQTT();
    }
    MQTT.loop();
}

void feedbackMQTT(char *topic, byte *payload, unsigned int length) { 
    for (int i = 0; i < length; i++) {
        message = message + (char) payload[i];  // convert *byte to string
    }
}