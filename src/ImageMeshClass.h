#include "ofMain.h"

class ImageMeshClass {
public:
    void setup(string videoName);
    void draw();
    void update();
    
    ofParameterGroup noiseParameters1;
    ofParameterGroup noiseParameters2;
    ofParameterGroup positionParameters;
    ofParameterGroup rotationParameters;


    
    ofParameter<float> noiseAmp1;
    ofParameter<float> noiseAmp2;
    ofParameter<float> freqX1;
    ofParameter<float> freqX2;
    ofParameter<float> freqY1;
    ofParameter<float> freqY2;
    ofParameter<float> speed1;
    ofParameter<float> speed2;
    ofParameter<float> rX;
    ofParameter<float> rY;
    ofParameter<float> rZ;
    ofParameter<float> tX;
    ofParameter<float> tY;
    ofParameter<float> tZ;
    
private:
    
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
