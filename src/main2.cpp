#include <cstdlib>
#include <math.h>
#include <GL/glut.h>
#include <vector>

#include "GlutInit/GlutInit.h"
#include "SceneBuilder/SceneBuilder.h"
#include "Particle/Particle.h"
#include "Particle/Position.h"

using namespace GlutInitialisation;
using namespace SceneGenerator;

GlutInit initialiser(800, 600);
SceneBuilder sceneBuilder;
Position p1Position(0.6, 0, -5);
Particle p1(0.025, 30, 30, p1Position);

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

    sceneBuilder.BuildScene(p1);
	glutSwapBuffers();
}

void pressKey(int key, int xx, int yy)
{
	initialiser.PressKey(key);
}

int main(int argc, char **argv)
{
	// init GLUT and create window
	glutInit(&argc, argv);
	glutCreateWindow("Particles");
    glutSpecialFunc(pressKey);

    glClearColor(0.4, 0.4, 0.6, 1.0);
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
