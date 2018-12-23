#include "Arduino.h"
#include "QmuTactile.h"

QmuTactile::QmuTactile(uint8_t pin) {
    _pin = pin;
}

void QmuTactile::loop(void) {

    uint8_t pinState = digitalRead(_pin);

    //Press moment
    if (pinState == LOW && _previousPinState == HIGH) {
        _pressMillis = millis();
    }

    //Release moment
    if (pinState == HIGH && _previousPinState == LOW) {
        const uint32_t buttonTime = abs(millis() - _pressMillis);

        if (buttonTime > TACTILE_LONG_PRESS_TIME) {
            _state = TACTILE_STATE_LONG_PRESS;
        } else if (buttonTime > TACTILE_MIN_PRESS_TIME) {
            _state = TACTILE_STATE_SHORT_PRESS;
        } else {
            _state = TACTILE_STATE_NONE;
        }

    } else {
        _state = TACTILE_STATE_NONE;
    }

    _previousPinState = pinState;
}

void QmuTactile::start(void) {
    pinMode(_pin, INPUT_PULLUP);
}

uint8_t QmuTactile::getState(void) {
    return _state;
}