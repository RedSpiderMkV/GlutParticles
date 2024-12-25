
#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "../SceneComponent/Particle.h"
#include "../DeltaTime/DeltaTimeManager.h"
#include <vector>

using SceneComponent::Particle;
using namespace DeltaTime;
using namespace std;

namespace SceneGenerator
{
    class ParticleSceneBuilder
    {
        private:
			const float SIZE = 0.0125;
			const int VERTICAL_SLICES = 30;
			const int HORIZONTAL_SLICES = 30;

            int _sceneWidth;
            int _sceneHeight;
            float _scaleFactor;
            
            float _leftBoundary;
            float _rightBoundary;

			DeltaTimeManager _deltaTimeManager;
            
            void DrawRedParticle(Particle particle);
        public:
			ParticleSceneBuilder(DeltaTimeManager& deltaTimeManager, int sceneHeight, int sceneWidth);
            void DrawBounds();
            void BuildScene(vector<Particle>& particleCollection);
    };
}

#endif
