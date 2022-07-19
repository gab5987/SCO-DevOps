#include "helper.h"

const char* SSID = "GABRIEL_2G"; // WIFI SSID 
const char* PASSWORD = "b1e3l245"; // WIFI Password

// SETTING UP WIRELESS NETWORK
void setupWIFI() {
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}