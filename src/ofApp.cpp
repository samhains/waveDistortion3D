#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    video.load("1.mp4");
    video.play();
    gui.setup();
    gui.add(noiseAmp1.setup("noiseAmp1", 0, 0, 10));
    gui.add(noiseAmp2.setup("noiseAmp2", 0, 0, 10));
    gui.add(freqX1.setup("freqX1", 0, 0, 1));
    gui.add(freqX2.setup("freqX2", 0, 0, 1));
    gui.add(freqY1.setup("freqY1", 0, 0, 1));
    gui.add(freqY2.setup("freqY2", 0, 0, 1));
    gui.add(speed1.setup("speed1", 0, 0, 12));
    gui.add(speed2.setup("speed2", 0, 0, 12));
    height = ofGetWindowHeight();
    width = ofGetWindowWidth();

    fbo.allocate(width, height);
    // clear fbo
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

//--------------------------------------------------------------
void ofApp::update(){
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
            //int noise2 = 0 * ofNoise(x, y, ofGetElapsedTimef() * 0.2 );
            int noise =  noise1 + noise2;
            


            p.z  = brightness * noise; //brightness
            mesh.setVertex(i, p);
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
	ofSetHexColor(0xffffff);
    if (video.isFrameNew()) {
        fbo.begin();

        int alpha = 600;
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, alpha);
        video.draw(0, 0, width, height);
        ofDisableAlphaBlending();
        fbo.end();
    }
 
    //fbo.draw(0, 0);
    ofPushMatrix();
    ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0);
    image.bind();
    mesh.draw();
    image.unbind();
    ofPopMatrix();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
