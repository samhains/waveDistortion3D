#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //cam.setDistance(0);
    gui2.setup();
    gui2.add(meshSelect.set("Mesh select", 0, 0, NMESH ));
    meshSelect.addListener(this, &ofApp::meshSelectChanged);
    
    for(int i=0; i<NMESH; i++){
        mesh[i].setup(i);
        noiseParameterGroup[i].add(mesh[i].noiseParameters1);
        noiseParameterGroup[i].add(mesh[i].noiseParameters2);
        noiseParameterGroup[i].setName("noise_"+to_string(i));
        positionParameterGroup[i].add(mesh[i].positionParameters);
        positionParameterGroup[i].add(mesh[i].rotationParameters);
        positionParameterGroup[i].setName("position_"+to_string(i));
    }
    
    

    gui1.setup(noiseParameterGroup[meshSelect]);
    gui3.setup(positionParameterGroup[meshSelect]);
   	
	
}

//--------------------------------------------------------------
void ofApp::meshSelectChanged(int & meshSelect){
    gui1.setup(noiseParameterGroup[meshSelect]);
    gui3.setup(positionParameterGroup[meshSelect]);

}
//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<NMESH; i++){
        mesh[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofBackground(0);
    for(int i=0; i<NMESH; i++){
        mesh[i].draw();
    }
    
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
