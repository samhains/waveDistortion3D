#include "ofApp.h"
#

void AudioData::setup() {
    fftSmooth = new float [8192];

    for (int i=0; i < 8192; i++) {
        fftSmooth[i] = 0;
    }
}


void AudioData::update(){
    float * value = ofSoundGetSpectrum(bands);
    for (int i = 0; i < bands; i ++) {
        fftSmooth[i] *= 0.9f;
        if (fftSmooth[i] < value[i]) {
            fftSmooth[i] = value[i];
        }
    }
    ofSoundUpdate();
  
}
