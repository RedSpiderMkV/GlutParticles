#include <math.h>
#include <GL/glut.h>

#include "SceneBuilder.h"
#include "../Particle/Particle.h"

namespace SceneGenerator
{
    void SceneBuilder::DrawRedParticle(float posX, float posY, float posZ, Particle *particle)
    {
        glColor3f(1.0, 0.0, 0.0);
        glPushMatrix();
            glTranslated(posX, posY, posZ);
            glutSolidSphere(particle->GetSize(), particle->GetVerticalSlices(), particle->GetHorizontalSlices());
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
    
    void SceneBuilder::BuildScene(Particle* particle)
    {
        static float posY = 0;
        
        this->DrawRedParticle(0.6, posY, -5, particle);
        this->DrawRedParticle(-0.6, posY * -1.0, -5, particle);
        this->DrawBounds();
        
        posY += 0.01;
    }
}
