
namespace GlutInitialisation
{
    class GlutInit
    {
        private:
            bool _use3d;
        public:
            GlutInit(int width, int height, bool use3d=true);
            void ChangeSize(int w, int h);
            void PressKey(int key);
    };
}
