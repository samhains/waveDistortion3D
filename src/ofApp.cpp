#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup(){
    for (int i = 0; i != NSCENE; i++) {
        if (i <= 1) {
        	scenes[i].setup(i, 0, 7);
        }
        else if (i > 1) {
        	scenes[i].setup(i, 0, 3);
        }
    }
    
    meshSelect = 0;
    gui2.setup();
    gui2.add(meshSelect.set("Mesh select", 0, 0, scenes[0].nMesh -1));
    meshSelect.addListener(this, &ofApp::meshSelectChanged);


    audioData.setup();
    
    beat.load("1_cropped.mp3");
    
    beat.setLoop(true);
    beat.play();
    setSceneParams();
    setGuiPosition();
   	
}

void ofApp::setSceneParams(){
    gui1.setup(scenes[sceneNum].noiseParameterGroups[meshSelect]);
    gui3.setup(scenes[sceneNum].positionParameterGroups[meshSelect]);
}

void ofApp::setGuiPosition(){
    gui1.setPosition(0, ofGetWindowHeight()-230);
    gui2.setPosition(0, ofGetWindowHeight()-290);
    gui3.setPosition(0, 0);
}

//--------------------------------------------------------------
void ofApp::meshSelectChanged(int & _meshSelect){
    meshSelect = _meshSelect;
    setSceneParams();
    setGuiPosition();
}

//--------------------------------------------------------------
void ofApp::update(){
    audioData.update();
	scenes[sceneNum].update(audioData);
  
}

//--------------------------------------------------------------
void ofApp::draw(){
    
	ofBackground(0);
    cam.begin();
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
        setSceneParams();
        setGuiPosition();
        meshSelect.set("Mesh select", 0, 0, scenes[sceneNum].nMesh -1);
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
