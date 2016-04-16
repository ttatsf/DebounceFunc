# DebounceFunc for Arduino
Functions for debouncing data, especially good for digitalRead().
##Description
DebounceFunc has 5 simple function objects.

+ "IsFALLING" : calculate debounced data from incoming data, then return whether previous debounced data is HIGH and new debounced data is LOW.
+ "IsRISING" : calculate debounced data from incoming data, then return whether previous debounced data is LOW and new debounced data is HIGH.
+ "IsCHANGE" : calculate debounced data from incoming data, then return whether previous debounced data is not equal to  new debounced data.
+ "IsLOW" : calculate debounced data from incoming data, then return whether the data is LOW.
+ "IsHIGH" : calculate debounced data from incoming data, then return whether the data is HIGH.

##Typical usage
As these are "function" object, you can(and have to) use each instance as  "function" directly.


```
#include "DebounceFunc.h"

//Instantiate function objects.
// By default,the debounce time is 30[ms].
IsFALLING isFalling0;  //or: IsFALLING isFalling0(10);  //you can set debounce time:

//Instantiate array:
IsFALLING isFalling[4]; //or: IsFALLING isFalling[4]={10,10,10,10};    //You can also set array's element's debounce time.This sets each to 10.

const int PIN_0 = 2;
const int PIN[4]={3,4,5,6};

void setup(){
  pinMode(PIN_0,INPUT_PULLUP);
  for (int i = 0; i < 4; i++) {
    pinMode(PIN[i],INPUT_PULLUP);
  }
//...//
}
void loop(){
  // regular pattern :
  const int rawData = digitalRead(PIN_0);
  if (isFalling0(rawData)) {
    //Do anything you want only when the debounced data is falling.
  }

  //regular pattern for array :
  for (int i=0; i < 4; i++) {
    const int rawData = digitalRead(PIN[i]);
    if (isFalling[i](rawData)) {
      //Do anything you want only when the debounced data is falling.
    }
  }
  delay(10);
}
```
You can also use other function objects in the same way.

#License
This code is available under the [MIT License](http://opensource.org/licenses/mit-license.php).
