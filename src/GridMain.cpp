#include <cstdlib>
#include <math.h>
#include <GL/glut.h>
#include <vector>

#include "GlutInit/GlutInit.h"
#include "Particle/Particle.h"
#include "Particle/ThreeComponentVector.h"
#include "DeltaTime/DeltaTimeManager.h"

using namespace GlutInitialisation;
using namespace DeltaTime;

GlutInit initialiser(800, 600);
DeltaTimeManager deltaTimeManager;

void InitialiseGrid()
{
	
}

void changeSize(int w, int h)
{
	initialiser.ChangeSize(w, h);
}

void renderScene(void)
{
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

    // Scene generation goes here

	glutSwapBuffers();
}

void pressKey(int key, int xx, int yy)
{
	initialiser.PressKey(key);
}

int main(int argc, char **argv)
{
	InitialiseGrid();
	
	// init GLUT and create window
	glutInit(&argc, argv);
	glutCreateWindow("Grid");
    glutSpecialFunc(pressKey);

    glClearColor(0.1, 0.1, 0.1, 1.0);
    // register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}
