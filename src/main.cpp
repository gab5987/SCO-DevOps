#include "functions/helper.h"

char message;
float rawValue = 0;

void setup(void){
  //Serial.begin(115200);
  setupWIFI();
  initMQTT();
}

void loop(void) {
  char *msg = &message;

  delay(3000);
  loopMQTT();

  rawValue = readDHT(0);
  snprintf (msg, 75, "%.2f", rawValue);
  publishMQTT(&message, 0);

  delay(3000);
  loopMQTT();

  rawValue = readDHT(1);
  snprintf (msg, 75, "%.2f", rawValue);
  publishMQTT(&message, 1);
}
