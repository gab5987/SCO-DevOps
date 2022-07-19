#include "helper.h"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

void setupTimeClient() {
    timeClient.begin();
    timeClient.update();
}

unsigned long getTime() {
    timeClient.update();
    return timeClient.getEpochTime();
}