#include "ofApp.h"
#include "Mesh/MeshUtils.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setDistance(0);
    video.load("1.mp4");
    video.play();
    gui1.setup();
    gui2.setup();
    gui1.add(noiseAmp1.setup("noiseAmp1", 0, 0, 10));
    gui2.add(noiseAmp2.setup("noiseAmp2", 0, 0, 10));
    gui1.add(freqX1.setup("freqX1", 0, 0, 1));
    gui2.add(freqX2.setup("freqX2", 0, 0, 1));
    gui1.add(freqY1.setup("freqY1", 0, 0, 1));
    gui2.add(freqY2.setup("freqY2", 0, 0, 1));
    gui1.add(speed1.setup("speed1", 0, 0, 12));
    gui2.add(speed2.setup("speed2", 0, 0, 12));
    height = ofGetWindowHeight();
    width = ofGetWindowWidth();

    fbo.allocate(width, height);
    // clear fbo
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    
    MeshUtils::initializeMesh(H, W, height, width, meshSize, &mesh);
	
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
            int noise =  noise1 - noise2;
            


            p.z  = brightness * noise; //brightness
            mesh.setVertex(i, p);
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
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
    //tiltCurrent = ofLerp(tiltCurrent, tiltTarget, 0.1);
    //turnCurrent = ofLerp(turnCurrent, turnTarget, 0.1);
    ofRotateX(45);
    ofRotateZ(0);
    // ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0);
    ofTranslate( 0, 0, -1000);
    image.bind();
    mesh.draw();
    image.unbind();
    ofPopMatrix();
    
    cam.end();
    gui1.draw();
    gui2.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    if (key == OF_KEY_DOWN){
//        tiltTarget -= 5;
//    } else if (key == OF_KEY_UP){
//        tiltTarget += 5;
//    } else if (key == OF_KEY_LEFT){
//        turnTarget -= 5;
//    } else if (key == OF_KEY_RIGHT){
//        turnTarget += 5;
//    }
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
