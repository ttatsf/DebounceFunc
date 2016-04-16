#ifndef DEBOUNCE_FUNC_H
#define DEBOUNCE_FUNC_H
#include <Arduino.h>

class DebounceFunc{
  public:
    const long debounce;
    int updatedVal;
    long updatedTime;
    boolean debouncedState;
    boolean getDebouncedState(int newVal);
    DebounceFunc(int initVal,long deb);
};

class IsFALLING{
  private:
    DebounceFunc debounceFunc;
    boolean recentState;
  public:
    IsFALLING();
    IsFALLING(int initVal);
    IsFALLING(int initVal,long deb);
    boolean operator()(int newVal);
};
class IsRISING{
  private:
    DebounceFunc debounceFunc;
    boolean recentState;
  public:
    IsRISING();
    IsRISING(int initVal);
    IsRISING(int initVal,long deb);
    boolean operator()(int newVal);
};
class IsCHANGE{
  private:
    DebounceFunc debounceFunc;
    boolean recentState;
  public:
    IsCHANGE();
    IsCHANGE(int initVal);
    IsCHANGE(int initVal,long deb);
    boolean operator()(int newVal);
};
class IsLOW{
  private:
    DebounceFunc debounceFunc;
    boolean recentState;
  public:
    IsLOW();
    IsLOW(int initVal);
    IsLOW(int initVal,long deb);
    boolean operator()(int newVal);
};
class IsHIGH{
  private:
    DebounceFunc debounceFunc;
    boolean recentState;
  public:
    IsHIGH();
    IsHIGH(int initVal);
    IsHIGH(int initVal,long deb);
    boolean operator()(int newVal);
};

#endif
