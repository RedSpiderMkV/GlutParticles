
#include "Position.h"

namespace Particles
{
	Position::Position()
	{
		this->_positionX = 0;
        this->_positionY = 0;
        this->_positionZ = 0;
	}
	
    Position::Position(float positionX, float positionY, float positionZ)
    {
        this->_positionX = positionX;
        this->_positionY = positionY;
        this->_positionZ = positionZ;
    }
    
    float Position::GetPositionX()
    {
		return this->_positionX;
	}
	
	float Position::GetPositionY()
    {
		return this->_positionY;
	}
    
    float Position::GetPositionZ()
    {
		return this->_positionZ;
	}
	
	void Position::SetPositionX(float x)
	{
		this->_positionX = x;
	}
	
	void Position::SetPositionY(float y)
	{
		this->_positionY = y;
	}
	
	void Position::SetPositionZ(float z)
	{
		this->_positionZ = z;
	}
}
