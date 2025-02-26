#include "ThreeComponentVector.h"

namespace SceneComponent
{	
    ThreeComponentVector::ThreeComponentVector(float vectorX, float vectorY, float vectorZ)
    {
        this->_vectorX = vectorX;
        this->_vectorY = vectorY;
        this->_vectorZ = vectorZ;
    }
    
    void ThreeComponentVector::Add(ThreeComponentVector additionalVector)
    {
		this->_vectorX += additionalVector.GetX();
        this->_vectorY += additionalVector.GetY();
        this->_vectorZ += additionalVector.GetZ();
	}
    
    float ThreeComponentVector::GetX()
    {
		return this->_vectorX;
	}
	
	float ThreeComponentVector::GetY()
    {
		return this->_vectorY;
	}
    
    float ThreeComponentVector::GetZ()
    {
		return this->_vectorZ;
	}

    void ThreeComponentVector::SetX(float xValue)
    {
        this->_vectorX = xValue;
    }

    void ThreeComponentVector::SetY(float yValue)
    {
        this->_vectorY = yValue;
    }
}
