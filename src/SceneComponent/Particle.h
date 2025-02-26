
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
            
            ThreeComponentVector GetPosition() const;   // basically a get without the ability to modify
            void SetPosition(ThreeComponentVector position);

			ThreeComponentVector GetVelocity() const;
			void SetVelocity(ThreeComponentVector velocity);

            void InvertVerticalVelocity();
            void InvertHorizontalVelocity();
			
			void Update(int deltaTime);
    };
}

#endif
