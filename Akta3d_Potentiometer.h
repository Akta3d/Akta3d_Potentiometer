#ifndef Akta3d_Potentiometer_h
#define Akta3d_Potentiometer_h

#include "Arduino.h"

class Akta3d_Potentiometer
{
  public:
    /*
      Initialize a potentiometer return a value between minValue and maxValue
      @param pin: Anolog pin
      @param minValue: minimal value returned
      @param maxValue: maximal value returned
      @param minA: minimal value returned by the analog pin
      @param maxA: maximal value returned by the analog pin
      @param lowPassBCoeff: [0,1] 
        new_value = lowPassACoeff*old_value + lowPassBCoeff*new_value
        where lowPassACoeff+lowPassBCoeff=1, and the smaller the lowPassBCoeff (ie. lowPassBCoeff=0.2) the bigger the filtering effect.
    */
    Akta3d_Potentiometer(uint16_t pin, int minValue, int maxValue, int minA = 0, int maxA = 1024, float lowPassBCoeff = 0.05);
    void update();
    bool changed();
    int value();
    
  private:
    uint16_t _pin;
    int _minA;
    int _maxA;
    int _minValue;
    int _maxValue;
    float _bCoeff;
    
    int _newComputedValue;
    int _lastComputedValue;
    int _lastAnalogValue;
};

#endif
