// Copyright (C) 2002-2009 Laurent Mallet & Maxime Biais
// This file is part of the "Irrlicht Android Port".
// For conditions of distribution and use, see copyright notice in irrlicht.h
#include <jni.h>
#include <sys/time.h>
#include <time.h>
#include <android/log.h>
#include <stdint.h>
#include <android-receiver.h>
#include <android-logger.h>
#include <importgl.h>

#include <irrlicht.h>
#include <os.h>

using namespace irr;

using namespace os;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

extern IrrlichtDevice *device;
extern IVideoDriver* driver;
extern stringc gSdCardPath;

ISceneManager* smgr = NULL;
IGUIEnvironment* guienv = NULL;
IAnimatedMesh* mesh = NULL;
ISceneNode* node = NULL;
IAnimatedMeshSceneNode *nodeSydney = NULL;
ICameraSceneNode* camera = NULL;
IGUIStaticText* diagnostics = NULL;
SAppContext context;
AndroidEventReceiver *receiver;

static long _getTime(void)
{
    struct timeval  now;

    gettimeofday(&now, NULL);
    return (long)(now.tv_sec*1000 + now.tv_usec/1000);
}

void initSydney()
{
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();
 
    stringc myDir = gSdCardPath;
    myDir += "/Irrlicht";
    device->getFileSystem()->changeWorkingDirectoryTo(myDir.c_str());

   
    
    stringc sydneyFilename = "/Irrlicht/sydney.md2";
	mesh = smgr->getMesh( (gSdCardPath+sydneyFilename).c_str() );
	        if (!mesh)
	        {
	                device->drop();
					__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "cannot getMesh");
					return;
	        }
	nodeSydney = smgr->addAnimatedMeshSceneNode( mesh );
	
	if (nodeSydney)
	        {
	                nodeSydney->setMaterialFlag(EMF_LIGHTING, false);
	                //--// no animation
	                //--nodeSydney->setMD2Animation(scene::EMAT_STAND);
	                // with animation
                    nodeSydney->setMD2Animation(scene::EMAT_RUN);
                    stringc sydneyTextureFilename = "/Irrlicht/sydney.bmp";
	                nodeSydney->setMaterialTexture( 0, driver->getTexture((gSdCardPath+sydneyTextureFilename).c_str()) );
					__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "add texture");
	        }
	
	smgr->addCameraSceneNode(0, vector3df(0,10,-40), vector3df(0,5,0));
	
	// Then create the event receiver, giving it that context structure.
    receiver = new AndroidEventReceiver(context);

    // And tell the device to use our custom event receiver.
    device->setEventReceiver(receiver);
}

static int counter = 0;
/* Call to render the next GL frame */
void nativeDrawIterationSydney()
{	
    device->run();
    if (counter==0) {
        initSydney();
    }
	
	// SColor is the background color
	driver->beginScene(true, true, SColor(255,255,0,0));

	smgr->drawAll();
	guienv->drawAll();

	driver->endScene();

	counter ++ ;


	int fps = driver->getFPS();
    __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "Sydney fps=%d", fps);

}

void nativeDrawIteration()
{
    nativeDrawIterationSydney();
}
