#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setDistance(0);
    mesh.setup();
    noiseParameterGroup.add(mesh.noiseParameters1);
    noiseParameterGroup.add(mesh.noiseParameters2);
    

    gui1.setup(noiseParameterGroup);
   	
	
}

//--------------------------------------------------------------
void ofApp::update(){
   	mesh.update();


}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofBackground(0);
	ofSetHexColor(0xffffff);
	mesh.draw();
    
    cam.end();
    gui1.draw();

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
