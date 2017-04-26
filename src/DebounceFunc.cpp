#include <DebounceFunc.h>

static const int DEB_DEFAULT = 30;

DebounceFunc::DebounceFunc(int initVal,long deb):debounce(deb)
                                                , updatedVal(initVal) {
  updatedTime = millis();
  debouncedState = (boolean)updatedVal;
}
boolean DebounceFunc::getDebouncedState(int newVal){
  const long now = millis();
  if (newVal != updatedVal) {
    updatedVal = newVal;
    updatedTime = now;
  }
  if (debouncedState) {
    if (updatedVal)                     return true;
    if (now - updatedTime > debounce ) {debouncedState = false;
                                        return false;
                                       }
    else                                return true;
  }
  if (!updatedVal)                    return false;
  if (now - updatedTime > debounce ) {debouncedState = true;
                                      return true;
                                     }
  else                                return false;
}


IsFALLING::IsFALLING():debounceFunc(1,DEB_DEFAULT){
  recentState = debounceFunc.updatedVal;
}
IsFALLING::IsFALLING(int initVal):debounceFunc(initVal,DEB_DEFAULT){
  recentState = debounceFunc.updatedVal;
}
IsFALLING::IsFALLING(int initVal,long deb):debounceFunc(initVal,deb){
  recentState = debounceFunc.updatedVal;
}
boolean IsFALLING::operator()(int newVal){
  const boolean newState = debounceFunc.getDebouncedState(newVal);
  const boolean ANSWER = recentState && !newState;
  recentState = newState;
  return ANSWER;
}


IsRISING::IsRISING():debounceFunc(1,DEB_DEFAULT){
  recentState = debounceFunc.updatedVal;
}
IsRISING::IsRISING(int initVal):debounceFunc(initVal,DEB_DEFAULT){
  recentState = debounceFunc.updatedVal;
}
IsRISING::IsRISING(int initVal,long deb):debounceFunc(initVal,deb){
  recentState = debounceFunc.updatedVal;
}
boolean IsRISING::operator()(int newVal){
  const boolean newState = debounceFunc.getDebouncedState(newVal);
  const boolean ANSWER = !recentState && newState;
  recentState = newState;
  return ANSWER;
}

IsCHANGE::IsCHANGE():debounceFunc(1,DEB_DEFAULT){
  recentState = debounceFunc.updatedVal;
}
IsCHANGE::IsCHANGE(int initVal):debounceFunc(initVal,DEB_DEFAULT){
  recentState = debounceFunc.updatedVal;
}
IsCHANGE::IsCHANGE(int initVal,long deb):debounceFunc(initVal,deb){
  recentState = debounceFunc.updatedVal;
}
boolean IsCHANGE::operator()(int newVal){
  const boolean newState = debounceFunc.getDebouncedState(newVal);
  const boolean ANSWER = recentState != newState;
  recentState = newState;
  return ANSWER;
}

IsLOW::IsLOW():debounceFunc(1,DEB_DEFAULT){}
IsLOW::IsLOW(int initVal):debounceFunc(initVal,DEB_DEFAULT){}
IsLOW::IsLOW(int initVal,long deb):debounceFunc(initVal,deb){}

boolean IsLOW::operator()(int newVal){
  return !debounceFunc.getDebouncedState(newVal);
}

IsHIGH::IsHIGH():debounceFunc(1,DEB_DEFAULT){}
IsHIGH::IsHIGH(int initVal):debounceFunc(initVal,DEB_DEFAULT){}
IsHIGH::IsHIGH(int initVal,long deb):debounceFunc(initVal,deb){}

boolean IsHIGH::operator()(int newVal){
  return debounceFunc.getDebouncedState(newVal);
}
