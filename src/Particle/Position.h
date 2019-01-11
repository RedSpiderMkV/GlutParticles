
#ifndef POSITION_H
#define POSITION_H

namespace Particles
{
    class Position
    {
        private:
            float _positionX;
            float _positionY;
            float _positionZ;
        public:
			Position();
            Position(float positionX, float positionY, float positionZ);
            
            float GetPositionX();
            float GetPositionY();
            float GetPositionZ();
            
            void SetPositionX(float x);
            void SetPositionY(float y);
            void SetPositionZ(float z);
    };
}

#endif
