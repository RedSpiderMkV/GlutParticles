
#ifndef PARTICLE_H
#define PARTICLE_H

#include "ThreeComponentVector.h"

namespace SceneComponent
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

            void InvertVerticalVelocity();
            void InvertHorizontalVelocity();
			
			void Update(int deltaTime);
    };
}

#endif
