#ifndef __Funct_H__
#define __Funct_H__

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
#include <dht.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

void setupWIFI();
void initMQTT();
void reconnetMQTT();
void publishMQTT(String msg);
void loopMQTT();
String readDHT();
unsigned long getTime();
void setupTimeClient();
void feedbackMQTT(char *topic, byte *payload, unsigned int length);

#endif