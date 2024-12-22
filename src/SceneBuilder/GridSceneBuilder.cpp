#include <GL/glut.h>
#include <iostream>

#include "GridSceneBuilder.h"
#include "../DeltaTime/DeltaTimeManager.h"

using namespace DeltaTime;
using namespace SceneGenerator;
using std::cout;

namespace SceneGenerator
{
    GridSceneBuilder::GridSceneBuilder(DeltaTimeManager& deltaTimeManager, int height, int width)
	{
		this->_deltaTimeManager = deltaTimeManager;
        this->_sceneHeight = height;
        this->_sceneWidth = width;
	}

    void GridSceneBuilder::DrawBounds()
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

    void GridSceneBuilder::BuildScene()
    {
        float gridWidth = ((this->_sceneWidth - 10.0f) / 10.0f) / this->_sceneWidth;    // We want a grid with 20 boxes across
        float gridHeight = ((this->_sceneHeight - 10.0f) / 15.0f) / this->_sceneHeight;    // We want a grid with 20 boxes across

        float left = -1.0f + (10.0f / this->_sceneWidth);
        float right = 1.0f - (10.0f / this->_sceneWidth);

        float top = 1.0f - (10.0f / this->_sceneHeight);
        float bottom = -1.0f + (10.0f / this->_sceneHeight);

        glColor3f(1.0f, 1.0f, 1.0f);

        float currentLeft = left + gridWidth;
        while (currentLeft < right)
        {
            glBegin(GL_LINES);
            glVertex2f(currentLeft, top);    // Top of the line
            glVertex2f(currentLeft, bottom); // Bottom of the line
            glEnd();

            currentLeft += gridWidth; // Move to the next grid line
        }

        while (top > bottom)
        {
            glBegin(GL_LINES);
            glVertex2f(left, top);    // Top of the line
            glVertex2f(right, top); // Bottom of the line
            glEnd();

            top -= gridHeight; // Move to the next grid line
        }
        
        this->DrawBounds();
    }
}