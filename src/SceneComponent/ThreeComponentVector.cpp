#include "ThreeComponentVector.h"

namespace SceneComponent
{	
    ThreeComponentVector::ThreeComponentVector(float vectorX, float vectorY, float vectorZ)
    {
        _vectorX = vectorX;
        _vectorY = vectorY;
        _vectorZ = vectorZ;
    }
    
    void ThreeComponentVector::Add(ThreeComponentVector additionalVector)
    {
		_vectorX += additionalVector.GetX();
        _vectorY += additionalVector.GetY();
        _vectorZ += additionalVector.GetZ();
	}
    
    float ThreeComponentVector::GetX() const
    {
		return _vectorX;
	}
	
	float ThreeComponentVector::GetY() const
    {
		return _vectorY;
	}
    
    float ThreeComponentVector::GetZ() const
    {
		return _vectorZ;
	}

    void ThreeComponentVector::SetX(float xValue)
    {
        _vectorX = xValue;
    }

    void ThreeComponentVector::SetY(float yValue)
    {
        _vectorY = yValue;
    }
}
