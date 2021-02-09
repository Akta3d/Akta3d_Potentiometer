#ifndef Akta3d_Potentiometer_h
#define Akta3d_Potentiometer_h

#include "Arduino.h"

class Akta3d_Potentiometer
{
  public:
    Akta3d_Potentiometer(int pin, int nbValue);
    void update();
    bool changed();
    int value();
    
  private:
    int _pin;
    int _min;
    int _max;
    int _nbValues;
    
    int _stepValue;
    int _computeValue;
    int _lastComputeValue;
};

#endif
