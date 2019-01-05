
#ifndef PARTICLE_H
#define PARTICLE_H

namespace Particles
{
    class Particle
    {
        private:
            float _size;
            int _horizontalSlices;
            int _verticalSlices;
        public:
            Particle(float size, int vSlices, int hSlices);
            
            float GetSize();
            int GetVerticalSlices();
            int GetHorizontalSlices();
    };
}

#endif
