#include "wirecutter.h"

Wirecutter::Wirecutter() : myservo(D15), cableFeeder(D2, D5), cableCutter(D3, D6) {
    cableFeeder.setDirection("clockwise");
    myservo.calibrate(0.02, 60.0);
    wait_us(500000);
    myservo.position(0.0);
}

void Wirecutter::feedCable(int length) {
    cableFeeder.rotate(length);
}

void Wirecutter::cutCable() {
    cableCutter.setDirection("clockwise");
    cableCutter.rotate(200);
    cableCutter.setDirection("counterclockwise");
    cableCutter.rotate(200);
}

void Wirecutter::stripCable() {
    myservo.position(1.0);
    ThisThread::sleep_for(chrono::milliseconds(2000));
    cutCable();
    ThisThread::sleep_for(chrono::milliseconds(2000));
    myservo.position(0.0);
}
