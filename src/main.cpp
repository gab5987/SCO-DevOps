#include "functions/helper.h"

String rawValue;

char bufEpoch[20];
unsigned long lastMessage;

void setup(void){
  Serial.begin(115200);
  setupWIFI();
  initMQTT();
  setupTimeClient();
}

void loop(void) {  
  unsigned long epochTime = getTime();

  snprintf(bufEpoch, 20, "%lu", epochTime);
  rawValue = readDHT() + "$" + String(bufEpoch);

  loopMQTT();
  publishMQTT(rawValue);

  delay(10000);
}
