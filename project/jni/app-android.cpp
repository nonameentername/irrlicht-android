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



void initQuake()
{
    //appInit();
    
    smgr = device->getSceneManager();

	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "getSceneManager r=%d", smgr);

    guienv = device->getGUIEnvironment();

	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "getGUIEnvironment r=%d", guienv);
    
    stringc quakeMapFilename = "/Irrlicht/map-20kdm2.pk3";
    device->getFileSystem()->addZipFileArchive((gSdCardPath+quakeMapFilename).c_str());
    
    mesh = smgr->getMesh("20kdm2.bsp");

    if (mesh) {
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "mesh available");
        node = smgr->addOctreeSceneNode(mesh->getMesh(0), 0, -1, 1024);
    } else {
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "mesh not available");        
    }
        
    if (node) {
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "node available");
        node->setPosition(core::vector3df(-1300,-144,-1249));
    } else {
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "node not available");
    }
        
    camera = smgr->addCameraSceneNodeFPS();
    
    stringc logoFilename = "/Irrlicht/irrlichtlogoalpha2.tga";
    guienv->addImage(driver->getTexture((gSdCardPath+logoFilename).c_str()),core::position2d<s32>(10,40));
    diagnostics = guienv->addStaticText(L"Ceci est un text", core::rect<s32>(10, 100, 10+400, 100+20));
    diagnostics->setOverrideColor(video::SColor(255, 255, 255, 0));
    
    guienv->addButton(rect<s32>(10,10,110,10 + 32), 0, GUI_ID_QUIT_BUTTON,
                            L"Quit", L"Exits Program");
                            
    
    context.device = device;
    context.counter = 0;
    context.listbox = 0;

    // Then create the event receiver, giving it that context structure.
    receiver = new AndroidEventReceiver(context);

    // And tell the device to use our custom event receiver.
    device->setEventReceiver(receiver);                        
    
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


void initIrr() {
    
    Printer::Logger = new CAndroidLogger();
    
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();
    stringc _3dsFilename = "/Irrlicht/room.3ds";    
    mesh = smgr->getMesh( (gSdCardPath+_3dsFilename).c_str() );
    __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "mesh: %d", mesh);
	
    //smgr->getMeshManipulator()->makePlanarTextureMapping(mesh->getMesh(0), 0.004f);

    node = smgr->addAnimatedMeshSceneNode(mesh);
    stringc _3dsTextureFilename = "/Irrlicht/wall.jpg";
    node->setMaterialTexture(0, driver->getTexture( (gSdCardPath+_3dsTextureFilename).c_str() ));
    node->getMaterial(0).SpecularColor.set(0,0,0,0);
    
    /*
    mesh = smgr->addHillPlaneMesh( "myHill",
            core::dimension2d<f32>(20,20),
            core::dimension2d<u32>(40,40), 0, 0,
            core::dimension2d<f32>(0,0),
            core::dimension2d<f32>(10,10));

    node = smgr->addWaterSurfaceSceneNode(mesh->getMesh(0), 3.0f, 300.0f, 30.0f);
    node->setPosition(core::vector3df(0,7,0));

    stringc stonesFilename = "/Irrlicht/stones.jpg";
    node->setMaterialTexture(0, driver->getTexture( (gSdCardPath+stonesFilename).c_str() ));
    stringc waterFilename = "/Irrlicht/water.jpg";
    node->setMaterialTexture(1, driver->getTexture( (gSdCardPath+waterFilename).c_str() ));

    node->setMaterialType(video::EMT_REFLECTION_2_LAYER);
    
    // create light

    node = smgr->addLightSceneNode(0, core::vector3df(0,0,0),
                video::SColorf(1.0f, 0.6f, 0.7f, 1.0f), 800.0f);
    scene::ISceneNodeAnimator* anim = 0;
    anim = smgr->createFlyCircleAnimator (core::vector3df(0,150,0),250.0f);
    node->addAnimator(anim);
    anim->drop();
    */
    
    camera = smgr->addCameraSceneNodeFPS();
    camera->setPosition(core::vector3df(-50,50,-150));
    
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

/* Call to render the next GL frame */
void nativeDrawIterationQuake()
{	
    device->run();
    if (counter==0) {
        initQuake();
    }
	
	if (node) {
		node->setPosition(core::vector3df(-1300,-144,-1249));
        camera->setRotation(core::vector3df(0, counter, 0));	
	}

	driver->beginScene(true, true, SColor(255,0,0,0));

	smgr->drawAll();
	guienv->drawAll();
	driver->endScene();

	counter ++ ;


	int fps = driver->getFPS();
    __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "fps=%d", fps);

}

void nativeDrawIterationIrr()
{	
    device->run();	
    if (counter==0) {
        initIrr();
    }
	
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "Load irr scene");
    
	driver->beginScene(true, true, SColor(255,255,0,0));

	smgr->drawAll();
	guienv->drawAll();
	driver->endScene();

	counter ++ ;


	int fps = driver->getFPS();
    __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "fps=%d", fps);

} 

void nativeDrawIteration()
{
    nativeDrawIterationSydney();
}

