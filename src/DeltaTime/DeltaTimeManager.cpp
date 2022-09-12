#include <GL/glut.h>
#include "DeltaTimeManager.h"

namespace DeltaTime
{
	DeltaTimeManager::DeltaTimeManager()
	{
		this->_initialTime = glutGet(GLUT_ELAPSED_TIME);
		this->_lastCall = glutGet(GLUT_ELAPSED_TIME) - this->_initialTime;
	}
	
	int DeltaTimeManager::GetDeltaTimeSinceLastCall()
	{
		int currentElapsedTime = glutGet(GLUT_ELAPSED_TIME);
		int deltaSinceLastCall = currentElapsedTime - this->_lastCall;
		this->_lastCall = currentElapsedTime;
		
		return deltaSinceLastCall;
	}
}
