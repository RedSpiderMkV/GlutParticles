
#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "../Particle/Particle.h"

using namespace Particles;

namespace SceneGenerator
{
    class SceneBuilder
    {
        private:
            void DrawRedParticle(float posX, float posY, float posZ, Particle* particle);
            void DrawBounds();
        public:
            void BuildScene(Particle* particle);
    };
}

#endif
