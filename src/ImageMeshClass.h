#include "ofMain.h"

class ImageMeshClass {
public:
    void setup(string _videoName, int _tX, int _tY, int _tZ, int _rY, int _rX, int _rZ);
    void draw();
    void update();
    
    ofParameterGroup noiseParameters1;
    ofParameterGroup noiseParameters2;
    
    ofParameter<float> noiseAmp1;
    ofParameter<float> noiseAmp2;
    ofParameter<float> freqX1;
    ofParameter<float> freqX2;
    ofParameter<float> freqY1;
    ofParameter<float> freqY2;
    ofParameter<float> speed1;
    ofParameter<float> speed2;

    
private:
    int rX;
    int rY;
    int rZ;
    int tX;
    int tY;
    int tZ;
    string videoName;
    ofMesh mesh;
    ofVideoPlayer video;
    ofImage image;
    ofFbo fbo;
    ofPixels fboPixels;
    int width;
    int height;
    int H = 100;
    int W = 100;
    int meshSize = 6;
};
