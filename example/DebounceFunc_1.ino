#include "DebounceFunc.h"

const int inPin[] = {11,12};
IsFALLING isFalling[2];
IsRISING isRising[2];
IsCHANGE isChange[2];
IsLOW isLow[2];
IsHIGH isHigh[2]; 
void setup() {
  for (int i; i < 2; i++) {
    pinMode(inPin[i],INPUT_PULLUP);
  }
  Serial.begin(115200);
}

void loop() {
  for (int i = 0;i < 2; i++) {
    const int rawData = digitalRead(inPin[i]);
    Serial.print("t:");
    Serial.print(millis());
    Serial.print(" raw");
    Serial.print(inPin[i]);
    Serial.print(":");
    Serial.print(rawData);
    Serial.print(" F?:");
    Serial.print(isFalling[i](rawData));
    Serial.print(" R?:");
    Serial.print(isRising[i](rawData));
   Serial.print(" C?:");
    Serial.print(isChange[i](rawData));
   Serial.print(" L?:");
    Serial.print(isLow[i](rawData));
   Serial.print(" H?:");
    Serial.print(isHigh[i](rawData));
    Serial.print("\t\t");
    delay(10);
  }
  Serial.print("\n");
}
