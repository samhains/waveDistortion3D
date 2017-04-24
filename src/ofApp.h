#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{


public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofVideoPlayer video;
    ofImage image;
    ofPixels fboPixels;
    ofFbo fbo;
    ofMesh mesh;
    ofxFloatSlider noiseAmp1, freqYe, freqX1, speed1, speed2r noiseAmp freqY2, freqX2;
    ofxPanel gui;
	
private:
    int width;
    int height;
    int W = 100; //Grid size
    int H = 100;
    int meshSize = 6;

		
};
