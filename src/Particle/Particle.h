
#ifndef PARTICLE_H
#define PARTICLE_H

#include "Position.h"

namespace Particles
{
    class Particle
    {
        private:
            float _size;
            int _horizontalSlices;
            int _verticalSlices;
            Position _position;
        public:
            Particle(float size, int vSlices, int hSlices, Position position);
            
            float GetSize();
            int GetVerticalSlices();
            int GetHorizontalSlices();
            
            Position GetPosition();
            void SetPosition(Position position);
    };
}

#endif
