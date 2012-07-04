#ifndef __IRRLICHT_NATIVE_H__
#define __IRRLICHT_NATIVE_H__

#include <string>

class NativeIrrlicht {
    public:
        NativeIrrlicht();
        ~NativeIrrlicht();

        void onCreate();
        void onPause();
        void onResume();
        void onDestroy();
        void init();
        void initGL(int w, int h);
        void onResize(int w, int h);
        void sendEvent(int action, float x, float y);
        bool getStatus();
        void setPath(std::string path);
        void drawIteration();
};

#endif
