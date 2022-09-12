#ifndef DELTATIMEMANAGER_H
#define DELTATIMEMANAGER_H

namespace DeltaTime
{
	class DeltaTimeManager
	{
		private:
			int _initialTime;
			int _lastCall;
		public:
			DeltaTimeManager();
			int GetDeltaTimeSinceLastCall();
	};
}

#endif
