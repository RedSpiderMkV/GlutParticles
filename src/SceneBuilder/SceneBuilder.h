
#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "../Particle/Particle.h"

using namespace Particles;

namespace SceneGenerator
{
    class SceneBuilder
    {
        private:
            void DrawRedParticle(Particle particle);
            void DrawBounds();
        public:
            void BuildScene(Particle& particle);
    };
}

#endif
