
#ifndef THREECOMPONENTVECTOR_H
#define THREECOMPONENTVECTOR_H

namespace Particles
{
    class ThreeComponentVector
    {
        private:
            float _vectorX;
            float _vectorY;
            float _vectorZ;
        public:
			ThreeComponentVector();
            ThreeComponentVector(float vectorX, float vectorY, float vectorZ);

            void Add(ThreeComponentVector additionalVector);

            float GetX();
            float GetY();
            float GetZ();
    };
}

#endif
