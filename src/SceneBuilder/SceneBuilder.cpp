#include <math.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>

#include "SceneBuilder.h"
#include "../Particle/Particle.h"
#include "../Particle/ThreeComponentVector.h"

using namespace std;

namespace SceneGenerator
{
    void SceneBuilder::DrawRedParticle(Particle particle)
    {
        glColor3f(1.0, 0.0, 0.0);
        glPushMatrix();
			ThreeComponentVector position = particle.GetPosition();
			
			float xPosition = position.GetX() * 2.7;
			float yPosition = position.GetY() * 2.0;
			
            glTranslated(xPosition, yPosition, position.GetZ());
            glutSolidSphere(this->SIZE, this->VERTICAL_SLICES, this->HORIZONTAL_SLICES);
        glPopMatrix();
    }
    
    void SceneBuilder::DrawBounds()
    {
        glColor3f(0.0, 0.0, 0.0);
        glPushMatrix();
            glBegin(GL_LINES); //Begin quadrilateral coordinates
            //Trapezoid
            glVertex3f(-2.7f, -2.0f, -5.0f);
            glVertex3f(2.7f, -2.0f, -5.0f);
            
            glVertex3f(2.7f, -2.0f, -5.0f);
            glVertex3f(2.7f, 2.0f, -5.0f);
            
            glVertex3f(2.7f, 2.0f, -5.0f);
            glVertex3f(-2.7f, 2.0f, -5.0f);
            
            glVertex3f(-2.7f, 2.0f, -5.0f);
            glVertex3f(-2.7f, -2.0f, -5.0f);
            glEnd(); //End quadrilateral coordinates
        glPopMatrix();
    }
    
    void SceneBuilder::BuildScene(vector<Particle>& particleCollection)
    {
		for(uint i = 0; i < particleCollection.size(); i++)
		{
			Particle& particle = particleCollection.at(i);
			this->DrawRedParticle(particle);
			
			ThreeComponentVector& position = particle.GetPosition();
			ThreeComponentVector& velocity = particle.GetVelocity();
			
			position.Add(velocity);
			
			if(position.GetX() < -1.0 || position.GetX() > 1.0)
			{
				ThreeComponentVector newVelocity(velocity.GetX() * -1.0, velocity.GetY(), velocity.GetZ());
				particle.SetVelocity(newVelocity);
				position.Add(velocity);
			}
			
			if(position.GetY() < -1.0 || position.GetY() > 1.0)
			{
				ThreeComponentVector newVelocity(velocity.GetX(), velocity.GetY() * -1.0, velocity.GetZ());
				particle.SetVelocity(newVelocity);
				position.Add(velocity);
			}
			
			//particle.SetPosition(position);
		}
        
        this->DrawBounds();
    }
}
