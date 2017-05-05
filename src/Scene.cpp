#include "Scene.h"

void Scene::setup(int sceneNum, int meshSelect, int _nMesh) {
	sceneName = "scene_"+to_string(sceneNum);
	nMesh = _nMesh;
    cout << sceneName << " n mesh " << nMesh << endl;

	// set up mesh and mesh parameters for the scene
	for(int i=0; i<nMesh; i++){
        
		ImageMeshClass mesh;
		ofParameterGroup noiseParameterGroup;
		ofParameterGroup positionParameterGroup;

		string iStr = to_string(i);
        meshSetup(&mesh, i, sceneNum);
        
		noiseParameterGroup.setName(sceneName+"_noise_"+iStr);
		noiseParameterGroup.add(mesh.noiseParameters1);
		noiseParameterGroup.add(mesh.noiseParameters2);

		positionParameterGroup.setName(sceneName+"_position_"+iStr);
		positionParameterGroup.add(mesh.positionParameters);
		positionParameterGroup.add(mesh.rotationParameters);
	
		meshes.push_back(mesh);
		positionParameterGroups.push_back(positionParameterGroup);
		noiseParameterGroups.push_back(noiseParameterGroup);
	}
}

void Scene::meshSetup(ImageMeshClass *mesh, int meshNum, int sceneNum){
        if(sceneNum < 2){
                if (meshNum < 3) {
            		mesh->setup(meshNum, sceneName, 10, 10, 60);
                } else if (meshNum < 4) {
                    mesh->setup(meshNum, sceneName, 50, 50, 12);
                }
                else {
                    mesh->setup(meshNum, sceneName, 100, 100, 6);
                }
        } else if (sceneNum == 3 ) {
            if (meshNum < 12) {
        		mesh->setup(meshNum, sceneName, 10, 10, 60);
            } else {
        		mesh->setup(meshNum, sceneName, 100, 100, 6);
            }
        }
        else {
            mesh->setup(meshNum, sceneName, 100, 100, 6);
        }
}

void Scene::update(AudioData audioData){
	for(int i=0; i<nMesh; i++){
		meshes[i].update(audioData);
	}
}

void Scene::draw(){
    for(int i=0; i<nMesh; i++){
        meshes[i].draw();
    }
    
}
