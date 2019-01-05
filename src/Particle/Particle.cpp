
#include "Particle.h"

namespace Particles
{
    Particle::Particle(float size, int vSlices, int hSlices)
    {
        this->_size = size;
        this->_horizontalSlices = hSlices;
        this->_verticalSlices = vSlices;
    }
    
    float Particle::GetSize()
    {
        return this->_size;
    }
    
    int Particle::GetVerticalSlices()
    {
        return this->_verticalSlices;
    }
    
    int Particle::GetHorizontalSlices()
    {
        return this->_horizontalSlices;
    }
}
