
#ifndef GRIDSCENEBUILDER_H
#define GRIDSCENEBUILDER_H

#include "../DeltaTime/DeltaTimeManager.h"
#include <vector>

using namespace DeltaTime;
using namespace std;

namespace SceneGenerator
{
    class GridSceneBuilder
    {
        private:
			const float SIZE = 0.025;
			const int VERTICAL_SLICES = 30;
			const int HORIZONTAL_SLICES = 30;
			DeltaTimeManager _deltaTimeManager;

            int _sceneHeight;
            int _sceneWidth;
            
            void DrawBounds();
        public:
			GridSceneBuilder(DeltaTimeManager& deltaTimeManager, int height, int width);
            void BuildScene();
    };
}

#endif
