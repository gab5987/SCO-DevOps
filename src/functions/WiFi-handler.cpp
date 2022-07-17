#include "helper.h"

const char* SSID = "#######"; // WIFI SSID 
const char* PASSWORD = "#######"; // WIFI Password

// SETTING UP WIRELESS NETWORK
void setupWIFI() {
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}