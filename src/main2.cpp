#include <cstdlib>
#include <math.h>
#include <GL/glut.h>
#include <vector>

#include "GlutInit/GlutInit.h"
#include "SceneBuilder/SceneBuilder.h"
#include "Particle/Particle.h"
#include "Particle/ThreeComponentVector.h"
#include "DeltaTime/DeltaTimeManager.h"

using namespace GlutInitialisation;
using namespace SceneGenerator;
using namespace DeltaTime;

GlutInit initialiser(800, 600);
DeltaTimeManager deltaTimeManager;
SceneBuilder sceneBuilder(deltaTimeManager);

vector<Particle> _particleCollection(10);

void InitialiseParticles()
{
	for(uint i = 0; i < _particleCollection.size(); i++)
	{
		ThreeComponentVector position(1.0, (float)i / (float)_particleCollection.size(), -5);
		ThreeComponentVector velocity(-0.01, -0.01, 0);
		
		Particle newParticle(position, velocity);
		_particleCollection[i] = newParticle;
	}
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

    sceneBuilder.BuildScene(_particleCollection);
	glutSwapBuffers();
}

void pressKey(int key, int xx, int yy)
{
	initialiser.PressKey(key);
}

int main(int argc, char **argv)
{
	InitialiseParticles();
	
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
