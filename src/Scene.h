#include "ofMain.h"
#include "ImageMeshClass.h"

class Scene {
public:
    int nMesh;
	vector<ofParameterGroup> noiseParameterGroups;
    vector<ofParameterGroup> positionParameterGroups;
    vector<ImageMeshClass> meshes;
    void meshSetup(ImageMeshClass *mesh, int meshNum, int sceneNum);
	void setup(int sceneNum, int meshSelect, int nMesh);
    void update(AudioData audioData);
    void draw();
    string sceneName;
};
