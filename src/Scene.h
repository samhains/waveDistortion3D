#include "ofMain.h"
#include "ImageMeshClass.h"
#define NMESH 5

class Scene {
public:
	ofParameterGroup noiseParameterGroup[NMESH];
    ofParameterGroup positionParameterGroup[NMESH];
    ImageMeshClass mesh[NMESH];
	void setup(int sceneNum, int meshSelect);
    void update();
    void draw();
};
