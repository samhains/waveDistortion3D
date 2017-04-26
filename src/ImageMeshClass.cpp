#include "ImageMeshClass.h"
#include <random>


void ImageMeshClass::setup(int videoNum, string sceneName) {
    
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0, 9);
    int num = dist(mt);
    
    videoName = to_string(num)+".mp4";
    cout << "num " << num << endl;
    if (settings.load("settings.xml")){
        cout << "success with xml load" << endl;
    } else {
        cout << "fail with xml load" << endl;
    }
    
    //float val = settings.getValue<float>("tX");
    settings.setToParent();
    string path = "//"+sceneName+"_noise_"+to_string(videoNum)+"/group";
    cout << "pth>>" << path << endl;
    settings.setTo(path);
    
    noiseParameters1.add(noiseAmp1.set("noiseAmp1", settings.getValue<float>("noiseAmp1"), 0, 7));
    noiseParameters2.add(noiseAmp2.set("noiseAmp2", settings.getValue<float>("noiseAmp2"), 0, 7));
    noiseParameters1.add(freqX1.set("freqX1", settings.getValue<float>("freqX1"), 0, 0.3));
    noiseParameters2.add(freqX2.set("freqX2", settings.getValue<float>("freqX2"), 0, 1));
    noiseParameters1.add(freqY1.set("freqY1", settings.getValue<float>("freqY1"), 0, 0.3));
    noiseParameters2.add(freqY2.set("freqY2", settings.getValue<float>("freqY2"), 0, 1));
    noiseParameters1.add(speed1.set("speed1", settings.getValue<float>("speed1"), 0, 6));
    noiseParameters2.add(speed2.set("speed2", settings.getValue<float>("speed2"), 0, 12));
    
    settings.setToParent();
    path = "//"+sceneName+"_position_"+to_string(videoNum)+"/group";
    settings.setTo(path);

    positionParameters.add(tX.set("tX", settings.getValue<float>("tX"), -10000, 10000));
    positionParameters.add(tY.set("tY", settings.getValue<float>("tY"), -10000, 10000));
    positionParameters.add(tZ.set("tZ", settings.getValue<float>("tZ"), -10000, 10000));
    rotationParameters.add(rX.set("rX", settings.getValue<float>("rX"), 0, 360));
    rotationParameters.add(rY.set("rY", settings.getValue<float>("rY"), 0, 360));
    rotationParameters.add(rZ.set("rZ", settings.getValue<float>("rZ"), 0, 360));


    
    video.load(videoName);
    video.play();
    height = ofGetWindowHeight();
    width = ofGetWindowWidth();
    fbo.allocate(width, height);
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    for (int y=0; y< H; y++) {
        for (int x=0; x<W; x++) {
            mesh.addVertex(ofPoint((x - W/2) * meshSize, (y - H/2) * meshSize, 0));
            mesh.addTexCoord(ofPoint(x * (width / W), y * (height / H)));
        }
    }
    
    for (int y=0; y < H-1; y++) {
        for (int x=0; x<W-1; x++) {
            int i1 = x + W * y;
            int i2 = x+1 + W * y;
            int i3 = x + W * (y+1);
            int i4 = x+1 + W * (y+1);
            mesh.addTriangle( i1, i2, i3 );
            mesh.addTriangle( i2, i4, i3 );
        }
    }
}

void ImageMeshClass::update(){
    video.update();
    fbo.readToPixels(fboPixels);
    image.setFromPixels(fboPixels);
    
    for (int y=0; y< H; y++){
        for (int x=0; x<W; x++){
            int i = x + W * y;
            ofPoint p = mesh.getVertex(i);
            
            float scaleX = width / W;
            float scaleY = height / H;
            
            int index = ((x * scaleX) + width * (y * scaleY)) * 4;
            int brightness = fboPixels[index] / 4;
            int noise1 = noiseAmp1 * ofNoise(x * freqX1, y * freqY1, ofGetElapsedTimef() * speed1);
            int noise2 = noiseAmp2 * ofNoise(x * freqX2, y * freqY2, ofGetElapsedTimef() * speed2);
            int noise =  noise1 - noise2;
            
            p.z  = brightness * noise;
            mesh.setVertex(i, p);
            
        }
    }
}

void ImageMeshClass::draw(){
    if (video.isFrameNew()) {
        fbo.begin();
        
        int alpha = 600;
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, alpha);
        video.draw(0, 0, width, height);
        ofDisableAlphaBlending();
        fbo.end();
    }

    ofPushMatrix();
    ofTranslate( tX, tY, tZ);

    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    image.bind();
    mesh.draw();
    image.unbind();
    
    ofPopMatrix();
}
