#include <iostream>
#include "Particle.h"
#include "ThreeComponentVector.h"

using std::cout;
using std::endl;

namespace SceneComponent
{
	Particle::Particle() : _position(0, 0, 0), _velocity(0, 0, 0)
	{
		
	}
	
    Particle::Particle(ThreeComponentVector position, ThreeComponentVector velocity)
		: _position(position), _velocity(velocity)
    {
		
    }
    
    ThreeComponentVector Particle::GetPosition() const
    {
		return _position;
	}
    
    void Particle::SetPosition(ThreeComponentVector position)
    {
		_position = position;
	}
	
	ThreeComponentVector Particle::GetVelocity() const
	{
		return _velocity;
	}
	
	void Particle::SetVelocity(ThreeComponentVector velocity)
	{
		_velocity = velocity;
	}
	
	void Particle::Update(int deltaTime)
	{
		float timeFactoredXMovement = _velocity.GetX() * deltaTime;
		float timeFactoredYMovement = _velocity.GetY() * deltaTime;
		float timeFactoredZMovement = _velocity.GetZ() * deltaTime;

		//cout << "Current X, Y position " << this->_position.GetX() << " " << this->_position.GetY() << endl;

		_position.Add(ThreeComponentVector(timeFactoredXMovement, timeFactoredYMovement, timeFactoredZMovement));
	}

	void Particle::InvertVerticalVelocity()
	{
		float currentVerticalVelocity = _velocity.GetY();
		_velocity.SetY(currentVerticalVelocity * -1);
	}

	void Particle::InvertHorizontalVelocity()
	{
		float currentHorizontalVelocity = _velocity.GetX();
		_velocity.SetX(currentHorizontalVelocity * -1);
	}
}
