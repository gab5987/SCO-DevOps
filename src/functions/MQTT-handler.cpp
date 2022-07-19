#include "helper.h"

const char* MQTT_SERVER = "broker.hivemq.com";
const char* MQTT_SERVER2 = "maqiatto.com";
WiFiClient CLIENT;
PubSubClient MQTT(CLIENT);

void initMQTT(){
    MQTT.setServer(MQTT_SERVER, 1883);
}

void reconnetMQTT() {
  while (!MQTT.connected()){

  if (MQTT.connect("ESP8266")){
  }else{
    delay(3000);
    }
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