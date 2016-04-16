#ifndef DEBOUNCE_FUNC_H
#define DEBOUNCE_FUNC_H
#include <Arduino.h>

class DebounceFunc{
  public:
    const int pin;
    const long debounce;
    int updatedVal;
    long updatedTime;
    boolean buttonState;
    boolean getButtonState();
    DebounceFunc(int inPin);
    DebounceFunc(int inPin,int deb);
};

class IsFALLING{
  private:
    DebounceFunc debounceFunc;
    boolean recentButtonState;
  public:
    IsFALLING(int inPin);
    IsFALLING(int inPin,int deb);
    boolean operator()();
};
class IsRISING{
  private:
    DebounceFunc debounceFunc;
    boolean recentButtonState;
  public:
    IsRISING(int inPin);
    IsRISING(int inPin,int deb);
    boolean operator()();
};
class IsCHANGE{
  private:
    DebounceFunc debounceFunc;
    boolean recentButtonState;
  public:
    IsCHANGE(int inPin);
    IsCHANGE(int inPin,int deb);
    boolean operator()();
};
class IsLOW{
  private:
    DebounceFunc debounceFunc;
    boolean recentButtonState;
  public:
    IsLOW(int inPin);
    IsLOW(int inPin,int deb);
    boolean operator()();
};
class IsHIGH{
  private:
    DebounceFunc debounceFunc;
    boolean recentButtonState;
  public:
    IsHIGH(int inPin);
    IsHIGH(int inPin,int deb);
    boolean operator()();
};

#endif
