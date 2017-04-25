//
//  ImageMeshClass.h
//  waveDistortion3D
//
//  Created by Sam Hains on 25/4/17.
//
//
#include "ofMain.h"

class ImageMeshClass {
public:
    void setup();
    void draw();
    void update();
private:
    ofMesh mesh;
    ofVideoPlayer video;
    ofImage image;
    ofFbo fbo;
    ofPixels fboPixels;
    int width;
    int height;
    int W = 100; //Grid size
    int H = 100;
    int meshSize = 6;
};
