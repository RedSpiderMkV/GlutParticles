
#include "Particle.h"
#include "Position.h"

namespace Particles
{
    Particle::Particle(float size, int vSlices, int hSlices, Position position)
    {
        this->_size = size;
        this->_horizontalSlices = hSlices;
        this->_verticalSlices = vSlices;
        this->_position = position;
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
    
    Position Particle::GetPosition()
    {
		return _position;
	}
    
    void Particle::SetPosition(Position position)
    {
		this->_position = position;
	}
}
