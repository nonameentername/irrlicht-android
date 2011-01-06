#include <jni.h>
#include <android/log.h>
#include <irrlicht.h>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int importGLInit();
void importGLDeinit();
void nativeDrawIteration();

// global variables
int  gWindowWidth  = 320;
int  gWindowHeight = 480;
int  gAppAlive   = 1;
stringc gSdCardPath = "/sdcard/";


IrrlichtDevice *device = NULL;
IVideoDriver* driver = NULL;




/* For JNI: C++ compiler need this */
extern "C" {

/** Activity onCreate */
void Java_com_ellismarkov_irrlicht_IrrlichtTest_nativeOnCreate( JNIEnv*  env )
{
    
}

/** Activity onPause */
void Java_com_ellismarkov_irrlicht_IrrlichtTest_nativeOnPause( JNIEnv*  env )
{

}

/** Activity onResume */
void Java_com_ellismarkov_irrlicht_IrrlichtTest_nativeOnResume( JNIEnv*  env )
{
    
}

/** Activity onDestroy */
void Java_com_ellismarkov_irrlicht_IrrlichtTest_nativeOnDestroy( JNIEnv*  env )
{
    importGLDeinit();
}

void Java_com_ellismarkov_irrlicht_IrrlichtTest_nativeInitGL( JNIEnv*  env )
{
    importGLInit();
    device = createDevice( video::EDT_OGLES2, dimension2d<u32>(gWindowWidth, gWindowHeight), 16, false, false, false, 0);
    driver = device->getVideoDriver();
    
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "createDevice r=%d w=%d h=%d", device, gWindowWidth, gWindowHeight);
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "getVideoDriver r=%d", driver);

    if (!device)
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "No device");
    if (!driver)
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "No driver");
}

void Java_com_ellismarkov_irrlicht_IrrlichtTest_nativeResize( JNIEnv*  env, jobject  thiz, jint w, jint h )
{
    __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "resize w=%d h=%d", w, h);
    gWindowWidth  = w;
    gWindowHeight = h;
    irr::core::dimension2d<unsigned int> size;
    size.Width = w;
    size.Height = h; 
    device->getVideoDriver()->OnResize(size);
}

void Java_com_ellismarkov_irrlicht_IrrlichtTest_nativeSendEvent( JNIEnv*  env, jobject defaultObj, jobject event) 
{
    jclass classEvent = env->GetObjectClass(event);
    jfieldID fieldAction = env->GetFieldID(classEvent, "mAction", "I");
    jfieldID fieldX = env->GetFieldID(classEvent, "mX", "F");
    jfieldID fieldY = env->GetFieldID(classEvent, "mY", "F");
    int action = env->GetIntField(event, fieldAction);
    // convert Android coord to OpenGL coords
    float x = env->GetFloatField(event, fieldX);
    float y = env->GetFloatField(event, fieldY);
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

void Java_com_ellismarkov_irrlicht_IrrlichtTest_nativeGetStatus(JNIEnv*  env, jobject defaultObj, jobject status) 
{
    if (gAppAlive==0) {
        jclass classStatus = env->GetObjectClass(status);
        jfieldID fieldStatus = env->GetFieldID(classStatus, "mQuit", "Z");
        env->SetBooleanField(status, fieldStatus, true);
    }    
}


void Java_com_ellismarkov_irrlicht_IrrlichtTest_nativeEnvJ2C(JNIEnv*  env, jobject defaultObj, jstring jsdcardPath) 
{
    char ligne[1024+1];
    const char *msg = env->GetStringUTFChars(jsdcardPath,0);
    gSdCardPath = msg;
    __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "not handled %s", gSdCardPath.c_str());
    env->ReleaseStringUTFChars(jsdcardPath,msg);
}

void Java_com_ellismarkov_irrlicht_IrrlichtTest_nativeDrawIteration( JNIEnv*  env ) 
{
    nativeDrawIteration();   
}

}
