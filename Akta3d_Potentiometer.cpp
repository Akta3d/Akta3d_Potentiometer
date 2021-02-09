#include "Arduino.h"
#include "Akta3d_Potentiometer.h"

Akta3d_Potentiometer::Akta3d_Potentiometer(int pin, int nbValues) {
  _pin = pin;
  _min = 0;
  _max = 1024;
  _nbValues = nbValues;

  _stepValue = (_max - _min) / _nbValues;
  _computeValue = 0;
  _lastComputeValue = 0;
}

void Akta3d_Potentiometer::update() {
  int realValue = analogRead(_pin);
  _lastComputeValue = realValue / _stepValue;
}

bool Akta3d_Potentiometer::changed() {
  bool changed = false;
  if (_lastComputeValue != _computeValue) {
    changed = true;
    _computeValue = _lastComputeValue;
  }
  return changed;
}

int Akta3d_Potentiometer::value() {
  return _computeValue;
}
