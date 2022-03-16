#include "steppermotor.h"

Steppermotor::Steppermotor(PinName step, PinName dir) : stepPin(step), dirPin(dir) {}

void Steppermotor::setDirection(std::string direction) {
    if (direction == "clockwise") {
        dirPin = 1;
    }
    else {
        dirPin = 0;
    }
}

void Steppermotor::rotate(int steps) {
    for (int i=0; i<steps; i++) {
        stepPin = 1;
        ThisThread::sleep_for(chrono::milliseconds(2));
        stepPin = 0;
        ThisThread::sleep_for(chrono::milliseconds(2));
    }
}
