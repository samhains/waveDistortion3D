#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ImageMeshClass.h"

class ofApp : public ofBaseApp{


public:
    void setup();
    void update();
    void draw();
    void initializeMesh(int H, int W, int height, int width,  int meshSize, ofMesh *mesh);

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
    ofxFloatSlider noiseAmp1, freqY1, freqX1, speed1, speed2, noiseAmp2, freqY2, freqX2;
    ofxPanel gui1;
    ofxPanel gui2;
    ofEasyCam cam;

    private:
    int width;
    int height;
    int W = 100; //Grid size
    int H = 100;
    int meshSize = 6;
    float tiltCurrent = 0;
    float tiltTarget = 0;
    float turnCurrent = 1;
    float turnTarget = 1;
    
    ImageMeshClass mesh1;


		
};
