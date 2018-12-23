# QmuTactile

QmuTactile is a simple button support library for all Arduino compatible boards. Main target is so called `debounce` but also `SHORT PRESS` `LONG PRESS` and `PRESSING` support

## Example usage

```
#include "QmuTactile.h"

#define PIN_BUTTON 9 //Button connected to pin 9 

QmuTactile button0(PIN_BUTTON);

void setup() {
    button0.start();
}

void loop() {
    button0.loop(); // Call as often as possible

    if (button0.getState() == TACTILE_STATE_LONG_PRESS) {
        // Do something when long press is detected
    } else if (button0.getState() == TACTILE_STATE_SHORT_PRESS) {
        // Do something when short press is detected
    }
}

```

## Remarks

* Short press time is 50ms
* Long press time is 1000ms