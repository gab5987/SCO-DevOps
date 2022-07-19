#include "helper.h"

dht DHT;
const int dataPin = 5; // GPIO 5 -> pin D1

String readDHT() {
    int chk = DHT.read11(dataPin);
    return String(DHT.humidity, 0) + "$" + String(DHT.temperature, 0);
}