#include "helper.h"

dht DHT;
const int dataPin = 5; // GPIO 5 -> pin D1

float readDHT(int h) {
    int chk = DHT.read11(dataPin);
    return h ? DHT.humidity : DHT.temperature;
}