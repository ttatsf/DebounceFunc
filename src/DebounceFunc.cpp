#include "DebounceFunc.h"
boolean DebounceFunc::getButtonState(){
  int reading = digitalRead(pin);
  long now = millis();
  if (reading != updatedVal) {
    updatedVal = reading;
    updatedTime = now;
  } 
  if (buttonState) {
    if (updatedVal) return true;
    if (now - updatedTime > debounce ) {
      buttonState = false;
      return false;
    }
    return true;     
  }
  if (!updatedVal) return false;
  if (now - updatedTime > debounce ) {
    buttonState = true;
    return true;
  }
  return false;
}
DebounceFunc::DebounceFunc(int inPin):pin(inPin)
                                     ,debounce(30){
  updatedVal = 1;
  updatedTime = millis();
  buttonState = true;
}
DebounceFunc::DebounceFunc(int inPin,int deb):pin(inPin)
                                             ,debounce(deb){
  updatedVal = 1;
  updatedTime = millis();
  buttonState = true;
}

IsFALLING::IsFALLING(int inPin):debounceFunc(inPin){
  recentButtonState = true;
}
IsFALLING::IsFALLING(int inPin,int deb):debounceFunc(inPin,deb){
  recentButtonState = true;
}
boolean IsFALLING::operator()(){
  const boolean newState = debounceFunc.getButtonState();
  const boolean ANSWER = recentButtonState && !newState;
  recentButtonState = newState;
  return ANSWER;
}

IsRISING::IsRISING(int inPin):debounceFunc(inPin){
  recentButtonState = true;
}
IsRISING::IsRISING(int inPin,int deb):debounceFunc(inPin,deb){
  recentButtonState = true;
}
boolean IsRISING::operator()(){
  const boolean newState = debounceFunc.getButtonState();
  const boolean ANSWER = !recentButtonState && newState;
  recentButtonState = newState;
  return ANSWER;
}

IsCHANGE::IsCHANGE(int inPin):debounceFunc(inPin){
  recentButtonState = true;
}
IsCHANGE::IsCHANGE(int inPin,int deb):debounceFunc(inPin,deb){
  recentButtonState = true;
}
boolean IsCHANGE::operator()(){
  const boolean newState = debounceFunc.getButtonState();
  const boolean ANSWER = recentButtonState != newState;
  recentButtonState = newState;
  return ANSWER;
}

IsLOW::IsLOW(int inPin):debounceFunc(inPin){
}
IsLOW::IsLOW(int inPin,int deb):debounceFunc(inPin,deb){
}
boolean IsLOW::operator()(){
  return !debounceFunc.getButtonState();
}

IsHIGH::IsHIGH(int inPin):debounceFunc(inPin){
}
IsHIGH::IsHIGH(int inPin,int deb):debounceFunc(inPin,deb){
}
boolean IsHIGH::operator()(){
  return debounceFunc.getButtonState();
}

