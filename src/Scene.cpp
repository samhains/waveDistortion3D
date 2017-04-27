#include "Scene.h"

void Scene::setup(int sceneNum, int meshSelect, int _nMesh) {
	string sceneName = "scene_"+to_string(sceneNum);
	nMesh = _nMesh;

	// set up mesh and mesh parameters for the scene
	for(int i=0; i<nMesh; i++){
        
		ImageMeshClass mesh;
		ofParameterGroup noiseParameterGroup;
		ofParameterGroup positionParameterGroup;

		string iStr = to_string(i);
        if (i < 3) {
    		mesh.setup(i, sceneName, 10, 10, 60);
        } else if (i < 4) {
            mesh.setup(i, sceneName, 50, 50, 12);
        } else {
            mesh.setup(i, sceneName, 100, 100, 6);
        }
        
		noiseParameterGroup.add(mesh.noiseParameters1);
		noiseParameterGroup.add(mesh.noiseParameters2);
		noiseParameterGroup.setName(sceneName+"_noise_"+iStr);

		positionParameterGroup.add(mesh.positionParameters);
		positionParameterGroup.add(mesh.rotationParameters);
		positionParameterGroup.setName(sceneName+"_position_"+iStr);
	
		meshes.push_back(mesh);
		positionParameterGroups.push_back(positionParameterGroup);
		noiseParameterGroups.push_back(noiseParameterGroup);
	}
}

void Scene::update(){
	for(int i=0; i<nMesh; i++){
		meshes[i].update();
	}
}

void Scene::draw(){
    for(int i=0; i<nMesh; i++){
        meshes[i].draw();
    }
    
}
