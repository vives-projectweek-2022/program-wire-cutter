//mbed compile -f --sterm --baudrate 115200

#include "mbed.h"
#include "wirecutter.h"

using namespace std;

DigitalOut enable(D8);

int main(void) {

    enable = 0;

    Wirecutter wirecutter;

    while(true) {
        wirecutter.feedCable(500);
        ThisThread::sleep_for(chrono::milliseconds(1000));
        wirecutter.stripCable();
        ThisThread::sleep_for(chrono::milliseconds(1000));
        wirecutter.feedCable(2000);
        ThisThread::sleep_for(chrono::milliseconds(1000));
        wirecutter.stripCable();
        ThisThread::sleep_for(chrono::milliseconds(1000));
        wirecutter.feedCable(500);
        ThisThread::sleep_for(chrono::milliseconds(1000));
        wirecutter.cutCable();
        ThisThread::sleep_for(chrono::milliseconds(1000));
    }
}
