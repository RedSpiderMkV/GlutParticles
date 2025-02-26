
#ifndef THREECOMPONENTVECTOR_H
#define THREECOMPONENTVECTOR_H

namespace SceneComponent
{
    class ThreeComponentVector
    {
        private:
            float _vectorX;
            float _vectorY;
            float _vectorZ;
        public:
            ThreeComponentVector(float vectorX, float vectorY, float vectorZ);

            void Add(ThreeComponentVector additionalVector);
            
            void SetX(float xValue);
            void SetY(float yValue);

            float GetX() const;
            float GetY() const;
            float GetZ() const;
    };
}

#endif
