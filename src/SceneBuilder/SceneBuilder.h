
#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "../Particle/Particle.h"
#include "../DeltaTime/DeltaTimeManager.h"
#include <vector>

using namespace Particles;
using namespace DeltaTime;
using namespace std;

namespace SceneGenerator
{
    class SceneBuilder
    {
        private:
			const float SIZE = 0.025;
			const int VERTICAL_SLICES = 30;
			const int HORIZONTAL_SLICES = 30;
			DeltaTimeManager _deltaTimeManager;
            
            void DrawRedParticle(Particle particle);
            void DrawBounds();
        public:
			SceneBuilder(DeltaTimeManager& deltaTimeManager);
            void BuildScene(vector<Particle>& particleCollection);
    };
}

#endif
