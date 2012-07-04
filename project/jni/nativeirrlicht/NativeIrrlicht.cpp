#include <jni.h>
#include <android/log.h>
#include <irrlicht.h>
#include "NativeIrrlicht.h"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int importGLInit();
void importGLDeinit();
void initSydney();
void nativeDrawIteration();

// global variables
int  gWindowWidth  = 320;
int  gWindowHeight = 480;
int  gAppAlive   = 1;
stringc gSdCardPath = "/sdcard/";


IrrlichtDevice *device = NULL;
IVideoDriver* driver = NULL;


NativeIrrlicht::NativeIrrlicht() {
}

NativeIrrlicht::~NativeIrrlicht() {
}

void NativeIrrlicht::onCreate() {
}

void NativeIrrlicht::onPause() {
}

void NativeIrrlicht::onResume() {
}

void NativeIrrlicht::onDestroy() {
    importGLDeinit();
}

void NativeIrrlicht::init() {
}

void NativeIrrlicht::initGL(int w, int h) {
    importGLInit();
    device = createDevice( video::EDT_OGLES1, dimension2d<u32>(w, h), 16, false, false, false, 0);
    driver = device->getVideoDriver();
    
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "createDevice r=%d w=%d h=%d", device, gWindowWidth, gWindowHeight);
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "getVideoDriver r=%d", driver);

    if (!device)
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "No device");
    if (!driver)
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "No driver");

    initSydney();
}

void NativeIrrlicht::onResize(int w, int h) {
    __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "resize w=%d h=%d", w, h);
    gWindowWidth  = w;
    gWindowHeight = h;
    irr::core::dimension2d<unsigned int> size;
    size.Width = w;
    size.Height = h; 
    device->getVideoDriver()->OnResize(size);
}

void NativeIrrlicht::sendEvent(int action, float x, float y) {
    SEvent irrevent;
    irrevent.MouseInput.ButtonStates = 0xffffffff;
    irrevent.EventType = irr::EET_MOUSE_INPUT_EVENT;
    irrevent.MouseInput.Event = irr::EMIE_COUNT;
	irrevent.MouseInput.X = x;
	irrevent.MouseInput.Y = y;
    if (action==0) {
        irrevent.MouseInput.ButtonStates = 0;
	    irrevent.MouseInput.ButtonStates = irr::EMBSM_LEFT;
        irrevent.MouseInput.Event = irr::EMIE_LMOUSE_PRESSED_DOWN; 
		irrevent.MouseInput.ButtonStates ^= irr::EMBSM_LEFT;   
	    device->postEventFromUser(irrevent);
	    __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "left click received %d %f %f", action, x, y);
    } else if (action==1){
        irrevent.MouseInput.ButtonStates = 0;
        irrevent.MouseInput.ButtonStates = irr::EMBSM_LEFT;
        irrevent.MouseInput.Event = irr::EMIE_LMOUSE_LEFT_UP;
		irrevent.MouseInput.ButtonStates ^= irr::EMBSM_LEFT;  
        device->postEventFromUser(irrevent);
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "left click release %d %f %f", action, x, y);
    } else {
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "not handled %d", action);   
    }    
}

bool NativeIrrlicht::getStatus() {
    if (gAppAlive==0) {
        return true;
    } else {
        return false;
    }
}

void NativeIrrlicht::setPath(std::string path) {
    gSdCardPath = path.c_str();
    __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "not handled %s", gSdCardPath.c_str());
}

void NativeIrrlicht::drawIteration() {
    nativeDrawIteration();   
}
