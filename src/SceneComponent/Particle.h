
#ifndef PARTICLE_H
#define PARTICLE_H

#include "ThreeComponentVector.h"

namespace Particles
{
    class Particle
    {
        private:
            ThreeComponentVector _position;
			ThreeComponentVector _velocity;
        public:
			Particle();
            Particle(ThreeComponentVector position, ThreeComponentVector velocity);
            
            ThreeComponentVector& GetPosition();
            void SetPosition(ThreeComponentVector position);

			ThreeComponentVector& GetVelocity();
			void SetVelocity(ThreeComponentVector velocity);
			
			void Update(int deltaTime);
    };
}

#endif
