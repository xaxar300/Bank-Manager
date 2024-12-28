#include "Utils.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void fordelay(int j) {
    this_thread::sleep_for(chrono::milliseconds(j));
}

void close() {
    cout << "\n\n\n\nThis Program is Closed... Thank You" << endl;
}
float inter(float t, float amount, int rate)
{
    float SI;
    SI = (rate * t * amount) / 100.0;
    return (SI);
}
