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
using SceneComponent::Particle;
using SceneComponent::ThreeComponentVector;

namespace SceneGenerator
{
	ParticleSceneBuilder::ParticleSceneBuilder(DeltaTimeManager& deltaTimeManager, int sceneHeight, int sceneWidth)
	{
		this->_deltaTimeManager = deltaTimeManager;
        this->_sceneHeight = sceneHeight;
        this->_sceneWidth = sceneWidth;
        this->_scaleFactor = static_cast<float>(this->_sceneWidth) / static_cast<float>(this->_sceneHeight);

        _leftBoundary = -1.0f + (10.0f / this->_sceneWidth);
        _rightBoundary = 1.0f - (10.0f / this->_sceneWidth);
        _topBoundary = 1.0f - (10.0f / this->_sceneHeight);
        _bottomBoundary = -1.0f + (10.0f / this->_sceneHeight);
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
        glColor3f(1.0, 1.0, 1.0);
        glPushMatrix();
            glBegin(GL_LINES);
            
            // Top line
            glVertex2f(this->_leftBoundary, this->_topBoundary);
            glVertex2f(this->_rightBoundary, this->_topBoundary);

            // Bottom line
            glVertex2f(this->_leftBoundary, this->_bottomBoundary);
            glVertex2f(this->_rightBoundary, this->_bottomBoundary);

            // Right line
            glVertex2f(this->_rightBoundary, this->_topBoundary);
            glVertex2f(this->_rightBoundary, this->_bottomBoundary);

            // Left line
            glVertex2f(this->_leftBoundary, this->_topBoundary);
            glVertex2f(this->_leftBoundary, this->_bottomBoundary);

            glEnd();
        glPopMatrix();
    }
    
    void ParticleSceneBuilder::BuildScene(vector<Particle>& particleCollection)
    {
		for(uint i = 0; i < particleCollection.size(); i++)
		{
			Particle& particle = particleCollection.at(i);
			
			int deltaTime = this->_deltaTimeManager.GetDeltaTimeSinceLastCall();
            ThreeComponentVector particlePosition = particle.GetPosition();
            float xPosition = particlePosition.GetX();
			float yPosition = particlePosition.GetY();

            if(yPosition >= this->_topBoundary || yPosition <= this->_bottomBoundary)
            {
                particle.InvertVerticalVelocity();
            }

            if (xPosition <= this->_leftBoundary || xPosition >= this->_rightBoundary)
            {
                particle.InvertHorizontalVelocity();
            }

			particle.Update(deltaTime);
			this->DrawRedParticle(particle);
			
			break;
		}
    }
}
