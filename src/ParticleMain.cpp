#include <cstdlib>
#include <math.h>
#include <GL/glut.h>
#include <vector>

#include "GlutInit/GlutInit.h"
#include "SceneBuilder/ParticleSceneBuilder.h"
#include "SceneComponent/Particle.h"
#include "SceneComponent/ThreeComponentVector.h"
#include "DeltaTime/DeltaTimeManager.h"

using namespace GlutInitialisation;
using namespace SceneGenerator;
using namespace DeltaTime;

const int SCENE_WIDTH = 800;
const int SCENE_HEIGHT = 600;

GlutInit initialiser(SCENE_WIDTH, SCENE_HEIGHT, false);
DeltaTimeManager deltaTimeManager;
ParticleSceneBuilder sceneBuilder(deltaTimeManager, SCENE_HEIGHT, SCENE_WIDTH);

vector<Particle> _particleCollection(1);

void InitialiseParticles()
{
	for(uint i = 0; i < _particleCollection.size(); i++)
	{
		ThreeComponentVector position(1.0, (float)i / (float)_particleCollection.size(), -5);
		ThreeComponentVector velocity(-0.0002, -0.0002, 0);
		
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
	sceneBuilder.DrawBounds();
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
