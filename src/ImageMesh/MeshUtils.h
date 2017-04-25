#include "ofMain.h"


class MeshUtils {
public:
    static void initializeMesh(int H, int W, int height, int width,  int meshSize, ofMesh* mesh) {
        
        for (int y=0; y< H; y++) {
            for (int x=0; x<W; x++) {
                mesh->addVertex(ofPoint((x - W/2) * meshSize, (y - H/2) * meshSize, 0));
                mesh->addTexCoord(ofPoint(x * (width / W), y * (height / H)));
            }
        }
        
        for (int y=0; y < H-1; y++) {
            for (int x=0; x<W-1; x++) {
                int i1 = x + W * y;
                int i2 = x+1 + W * y;
                int i3 = x + W * (y+1);
                int i4 = x+1 + W * (y+1);
                mesh->addTriangle( i1, i2, i3 );
                mesh->addTriangle( i2, i4, i3 );
            }
        }
    }

};
