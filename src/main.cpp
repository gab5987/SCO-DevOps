#include "functions/helper.h"

char message;
int rawValue = 0;

void setup(void){
  //Serial.begin(115200);
  setupWIFI();
  initMQTT();
}

void loop(void) {
  char *msg = &message;

  loopMQTT();

  rawValue = readDHT(0);
  snprintf (msg, 75, "%.2f", rawValue);
  publishMQTT(&message, 0);

  rawValue = readDHT(1);
  snprintf (msg, 75, "%.2f", rawValue);
  publishMQTT(&message, 1);

  delay(1000);
}
