#include <iostream>
#include "Particle.h"
#include "ThreeComponentVector.h"

using std::cout;
using std::endl;

namespace Particles
{
	Particle::Particle()
	{

	}
	
    Particle::Particle(ThreeComponentVector position, ThreeComponentVector velocity)
    {
		this->_velocity = velocity;
        this->_position = position;
    }
    
    ThreeComponentVector& Particle::GetPosition()
    {
		return _position;
	}
    
    void Particle::SetPosition(ThreeComponentVector position)
    {
		this->_position = position;
	}
	
	ThreeComponentVector& Particle::GetVelocity()
	{
		return this->_velocity;
	}
	
	void Particle::SetVelocity(ThreeComponentVector velocity)
	{
		this->_velocity = velocity;
	}
	
	void Particle::Update(int deltaTime)
	{
		float timeFactoredXMovement = this->_velocity.GetX() * deltaTime;
		float timeFactoredYMovement = this->_velocity.GetY() * deltaTime;
		float timeFactoredZMovement = this->_velocity.GetZ() * deltaTime;

		if(timeFactoredYMovement + this->_position.GetY() < -1.0f)
		{
			this->_position.SetY(1.0f);
		}

		if(timeFactoredYMovement + this->_position.GetY() > 1.0f)
		{
			this->_position.SetY(-1.0f);
		}

		if(timeFactoredXMovement + this->_position.GetX() < -1.0f)
		{
			this->_position.SetX(1.0f);
		}

		if(timeFactoredXMovement + this->_position.GetX() > 1.0f)
		{
			this->_position.SetX(-1.0f);
		}

		//cout << "Current X, Y position " << this->_position.GetX() << " " << this->_position.GetY() << endl;

		this->_position.Add(ThreeComponentVector(timeFactoredXMovement, timeFactoredYMovement, timeFactoredZMovement));
	}
}
