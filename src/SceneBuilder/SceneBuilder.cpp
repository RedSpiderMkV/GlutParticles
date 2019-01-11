#include <math.h>
#include <GL/glut.h>
#include <iostream>

#include "SceneBuilder.h"
#include "../Particle/Particle.h"
#include "../Particle/Position.h"

using namespace std;

namespace SceneGenerator
{
    void SceneBuilder::DrawRedParticle(Particle particle)
    {
        glColor3f(1.0, 0.0, 0.0);
        glPushMatrix();
			Position position = particle.GetPosition();
            glTranslated(position.GetPositionX(), position.GetPositionY(), position.GetPositionZ());
            glutSolidSphere(particle.GetSize(), particle.GetVerticalSlices(), particle.GetHorizontalSlices());
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
    
    void SceneBuilder::BuildScene(Particle& particle)
    {
        this->DrawRedParticle(particle);
        this->DrawBounds();
        
        Position position = particle.GetPosition();
        position.SetPositionY(position.GetPositionY() - 0.01);
        particle.SetPosition(position);
        //cout << "X: " << particle.GetPositionX() << " Y: " << particle.GetPositionY() << endl;
    }
}
