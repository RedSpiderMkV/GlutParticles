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
		cout << "Update called: " << deltaTime << endl;
	}
}
