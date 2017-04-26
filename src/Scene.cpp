#include "Scene.h"

void Scene::setup(int sceneNum, int meshSelect) {
	string sceneName = "scene_"+to_string(sceneNum);

	// set up mesh and mesh parameters for the scene
	for(int i=0; i<NMESH; i++){
		string iStr = to_string(i);
        if (i < 4) {
    		mesh[i].setup(i, sceneName, 10, 10, 60);
        } else if (i < 7) {
            mesh[i].setup(i, sceneName, 50, 50, 12);
        } else {
            mesh[i].setup(i, sceneName, 100, 100, 6);
        }
        
		noiseParameterGroup[i].add(mesh[i].noiseParameters1);
		noiseParameterGroup[i].add(mesh[i].noiseParameters2);
		noiseParameterGroup[i].setName(sceneName+"_noise_"+iStr);
		positionParameterGroup[i].add(mesh[i].positionParameters);
		positionParameterGroup[i].add(mesh[i].rotationParameters);
		positionParameterGroup[i].setName(sceneName+"_position_"+iStr);
	}
}

void Scene::update(){
	for(int i=0; i<NMESH; i++){
		mesh[i].update();
	}
}

void Scene::draw(){
    for(int i=0; i<NMESH; i++){
        mesh[i].draw();
    }
    
}
