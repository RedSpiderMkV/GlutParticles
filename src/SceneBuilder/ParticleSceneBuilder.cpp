#include <math.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>

#include "ParticleSceneBuilder.h"
#include "../SceneComponent/Particle.h"
#include "../SceneComponent/ThreeComponentVector.h"
#include "../DeltaTime/DeltaTimeManager.h"

using namespace std;
using namespace DeltaTime;

namespace SceneGenerator
{
	ParticleSceneBuilder::ParticleSceneBuilder(DeltaTimeManager& deltaTimeManager, int sceneHeight, int sceneWidth)
	{
		this->_deltaTimeManager = deltaTimeManager;
        this->_sceneHeight = sceneHeight;
        this->_sceneWidth = sceneWidth;
        this->_scaleFactor = static_cast<float>(this->_sceneWidth) / static_cast<float>(this->_sceneHeight);
	}
	
    void ParticleSceneBuilder::DrawRedParticle(Particle particle)
    {
        glColor3f(1.0, 0.0, 0.0);
        glPushMatrix();
			ThreeComponentVector position = particle.GetPosition();
			
			float xPosition = position.GetX();
			float yPosition = position.GetY();
			
            glTranslated(xPosition, yPosition, 0);
            glScalef(1.0f, this->_scaleFactor, 1.0f);
            glutSolidSphere(this->SIZE, this->VERTICAL_SLICES, this->HORIZONTAL_SLICES);
        glPopMatrix();
    }
    
    void ParticleSceneBuilder::DrawBounds()
    {
        float left = -1.0f + (10.0f / this->_sceneWidth);
        float right = 1.0f - (10.0f / this->_sceneWidth);

        float top = 1.0f - (10.0f / this->_sceneHeight);
        float bottom = -1.0f + (10.0f / this->_sceneHeight);

        glColor3f(1.0, 1.0, 1.0);
        glPushMatrix();
            glBegin(GL_LINES);
            
            // Top line
            glVertex2f(left, top);
            glVertex2f(right, top);

            // Bottom line
            glVertex2f(left, bottom);
            glVertex2f(right, bottom);

            // Right line
            glVertex2f(right, top);
            glVertex2f(right, bottom);

            // Left line
            glVertex2f(left, top);
            glVertex2f(left, bottom);

            glEnd();
        glPopMatrix();
    }
    
    void ParticleSceneBuilder::BuildScene(vector<Particle>& particleCollection)
    {
		for(uint i = 0; i < particleCollection.size(); i++)
		{
			Particle& particle = particleCollection.at(i);
			
			int deltaTime = this->_deltaTimeManager.GetDeltaTimeSinceLastCall();
			particle.Update(deltaTime);
			this->DrawRedParticle(particle);
			
			break;
		}
    }
}
