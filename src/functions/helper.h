#ifndef __Funct_H__
#define __Funct_H__

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
#include <dht.h>



void setupWIFI();
void initMQTT();
void reconnetMQTT();
void publishMQTT(char *msg, int th);
void loopMQTT();
float readDHT(int h);

#endif