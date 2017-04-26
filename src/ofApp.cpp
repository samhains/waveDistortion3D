#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup(){
    //cam.setDistance(0);
    for (int i = 0; i != NSCENE; i++) {
    	scenes[i].setup(i, 0);
    }
    gui2.setup();
    gui2.add(meshSelect.set("Mesh select", 0, 0, 9 ));
    meshSelect.addListener(this, &ofApp::meshSelectChanged);

    setSceneParams(meshSelect);
    setGuiPosition();
   	
}

void ofApp::setSceneParams(int meshSelect){
    cout << "meshSelect_" << meshSelect << endl;
    gui1.setup(scenes[sceneNum].noiseParameterGroup[meshSelect]);
    gui3.setup(scenes[sceneNum].positionParameterGroup[meshSelect]);
}

void ofApp::setGuiPosition(){
    gui1.setPosition(0, ofGetWindowHeight()-230);
    gui2.setPosition(0, ofGetWindowHeight()-290);
    gui3.setPosition(0, 0);
}

//--------------------------------------------------------------
void ofApp::meshSelectChanged(int & _meshSelect){
    setSceneParams(meshSelect);
    setGuiPosition();
}

//--------------------------------------------------------------
void ofApp::update(){
	scenes[sceneNum].update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
		ofBackground(0);
		scenes[sceneNum].draw();
    cam.end();
    gui1.draw();
    gui2.draw();
    gui3.draw();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        sceneNum += 1;
        if (sceneNum == NSCENE) {
            sceneNum = 0;
        }
        setSceneParams(meshSelect);
        setGuiPosition();
    }
    if (key == OF_KEY_SHIFT) {
        cam.toggleControl();
    }

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
