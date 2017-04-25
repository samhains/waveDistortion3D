#include "ImageMeshClass.h"

void ImageMeshClass::setup(string _videoName, int _tX, int _tY, int _tZ, int _rY, int _rX, int _rZ) {
    videoName = _videoName;
    
    tX = _tX;
    tY = _tY;
    tZ = _tZ;
    rX = _rX;
    rY = _rY;
    rZ = _rZ;
    
    
    noiseParameters1.add(noiseAmp1.set("noiseAmp1", 0, 0, 10));
    noiseParameters2.add(noiseAmp2.set("noiseAmp2", 0, 0, 10));
    noiseParameters1.add(freqX1.set("freqX1", 0, 0, 1));
    noiseParameters2.add(freqX2.set("freqX2", 0, 0, 1));
    noiseParameters1.add(freqY1.set("freqY1", 0, 0, 1));
    noiseParameters2.add(freqY2.set("freqY2", 0, 0, 1));
    noiseParameters1.add(speed1.set("speed1", 0, 0, 12));
    noiseParameters2.add(speed2.set("speed2", 0, 0, 12));

    
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
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    ofTranslate( tX, tY, tZ);
    image.bind();
    mesh.draw();
    image.unbind();
    ofPopMatrix();
}
