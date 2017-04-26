#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //cam.setDistance(0);
	scenes[0].setup(0, 0);
    gui2.setup();
    gui2.add(meshSelect.set("Mesh select", 0, 0, NMESH ));
    meshSelect.addListener(this, &ofApp::meshSelectChanged);

    gui1.setup(scenes[0].noiseParameterGroup[meshSelect]);
    gui3.setup(scenes[0].positionParameterGroup[meshSelect]);
   	
	
}

//--------------------------------------------------------------
void ofApp::meshSelectChanged(int & meshSelect){
    gui1.setup(scenes[0].noiseParameterGroup[meshSelect]);
    gui3.setup(scenes[0].positionParameterGroup[meshSelect]);

}
//--------------------------------------------------------------
void ofApp::update(){
	scenes[0].update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
		ofBackground(0);
		scenes[0].draw();
    cam.end();
    gui1.draw();
    gui2.draw();
    gui3.draw();


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
    //cam.toggleControl();

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
