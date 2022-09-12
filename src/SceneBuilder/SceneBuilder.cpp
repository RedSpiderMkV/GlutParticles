#include <math.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>

#include "SceneBuilder.h"
#include "../Particle/Particle.h"
#include "../Particle/ThreeComponentVector.h"
#include "../DeltaTime/DeltaTimeManager.h"

using namespace std;
using namespace DeltaTime;

namespace SceneGenerator
{
	SceneBuilder::SceneBuilder(DeltaTimeManager& deltaTimeManager)
	{
		this->_deltaTimeManager = deltaTimeManager;
	}
	
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
			
			int deltaTime = this->_deltaTimeManager.GetDeltaTimeSinceLastCall();
			particle.Update(deltaTime);
			this->DrawRedParticle(particle);
			
			break;
		}
        
        this->DrawBounds();
    }
}
