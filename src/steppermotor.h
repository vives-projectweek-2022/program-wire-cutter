#pragma once
#include "mbed.h"

class Steppermotor {

    public:
        Steppermotor(PinName step, PinName dir);

    public:
        void setDirection(std::string direction);
        void rotate(int steps);

    private:
        DigitalOut stepPin;
        DigitalOut dirPin;
};
