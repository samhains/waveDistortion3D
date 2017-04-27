#include "ofMain.h"

class AudioData {
public:
    float * fftSmooth;
    int bands = 4;
    void setup();
    void update();
};
