#include "Arduino.h"
#include "Akta3d_Potentiometer.h"

Akta3d_Potentiometer::Akta3d_Potentiometer(uint16_t pin, int minValue, int maxValue, int minA /*= 0*/, int maxA /*= 1024*/, float lowPassBCoeff /*= 0.2*/) {
  _pin = pin;
  _minValue = minValue;
  _maxValue = maxValue;
  _minA = minA;
  _maxA = maxA;
  _bCoeff = lowPassBCoeff;
  if(_bCoeff < 0) _bCoeff = 0;
  if(_bCoeff > 1) _bCoeff = 1;

  _lastAnalogValue = _minA;
  _newComputedValue = _minValue;
  _lastComputedValue = _minValue;
}

void Akta3d_Potentiometer::update() {
  int newAnalogValue = analogRead(_pin);
  newAnalogValue = (1 - _bCoeff) * _lastAnalogValue + _bCoeff * newAnalogValue;
  _lastAnalogValue = newAnalogValue;

  _lastComputedValue = map(newAnalogValue, _minA, _maxA, _minValue, _maxValue);
}

bool Akta3d_Potentiometer::changed() {
  bool changed = false;
  if (_lastComputedValue != _newComputedValue) {
    changed = true;
    _newComputedValue = _lastComputedValue;
  }
  return changed;
}

int Akta3d_Potentiometer::value() {
  return _newComputedValue;
}
