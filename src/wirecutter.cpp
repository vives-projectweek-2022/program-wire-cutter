#include "wirecutter.h"

Wirecutter::Wirecutter() : myservo(D15), cableFeeder(D2, D5), cableCutter(D3, D6) {
    cableFeeder.setDirection("counterclockwise");
    myservo.calibrate(0.02, 60.0);
    wait_us(500000);
    myservo.position(0.0);
}

void Wirecutter::feedCable(int length) {
    cableFeeder.rotate(length);
}

void Wirecutter::cutCable() {
    cableCutter.setDirection("clockwise");
    cableCutter.rotate(820);
    cableCutter.setDirection("counterclockwise");
    cableCutter.rotate(820);
}

void Wirecutter::stripCable() {
    cableCutter.setDirection("clockwise");
    cableCutter.rotate(765);
    cableCutter.setDirection("counterclockwise");
    cableCutter.rotate(765);
    
}
