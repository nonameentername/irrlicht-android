// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Copyright (C) 2008 Redshift Software, Inc.
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#include "CIrrDeviceAndroid.h"

#ifdef _IRR_COMPILE_WITH_ANDROID_DEVICE_

#include "os.h"
	
#include <android/log.h>

namespace irr
{
	namespace video
	{
		IVideoDriver* createOGLES1Driver(const SIrrlichtCreationParameters& params,
			video::SExposedVideoData& data, io::IFileSystem* io);
		IVideoDriver* createOGLES2Driver(const SIrrlichtCreationParameters& params,
			video::SExposedVideoData& data, io::IFileSystem* io);
	}
}

namespace irr
{

//! constructor
CIrrDeviceAndroid::CIrrDeviceAndroid(const SIrrlichtCreationParameters& params)
	: CIrrDeviceStub(params)
{
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "CIrrDeviceAndroid::CIrrDeviceAndroid");
	
	createDriver();

	if (VideoDriver)
		createGUIAndScene();
	
}

//! destructor
CIrrDeviceAndroid::~CIrrDeviceAndroid()
{
}

//! create the driver
void CIrrDeviceAndroid::createDriver()
{
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "CIrrDeviceAndroid::createDriver");
	switch(CreationParams.DriverType)
	{
	case video::EDT_OGLES1:
		#ifdef _IRR_COMPILE_WITH_OGLES1_
			{
				video::SExposedVideoData data;
				VideoDriver = video::createOGLES1Driver(
					CreationParams, data, FileSystem);
			}
		#else
			__android_log_print(ANDROID_LOG_INFO,"Irrlicht","No OpenGL-ES1 support compiled in.");
		#endif
			break;
    case video::EDT_OGLES2:
        #ifdef _IRR_COMPILE_WITH_OGLES2_
            {
                video::SExposedVideoData data;
                VideoDriver = video::createOGLES2Driver(
                    CreationParams, data, FileSystem);
            }
		#else
            __android_log_print(ANDROID_LOG_INFO,"Irrlicht","No OpenGL-ES2 support compiled in.");
		#endif
			break;
	case video::EDT_NULL:
		// create null driver
		VideoDriver = video::createNullDriver(FileSystem, CreationParams.WindowSize);
		break;

	default:
		__android_log_print(ANDROID_LOG_INFO,"Irrlicht","Unable to create video driver of unknown type.");
		break;
	}
}


bool CIrrDeviceAndroid::run()
{
    os::Timer::tick();
	return true;
}

//! Pause the current process for the minimum time allowed only to allow other processes to execute
void CIrrDeviceAndroid::yield()
{

}

//! Pause execution and let other processes to run for a specified amount of time.
void CIrrDeviceAndroid::sleep(u32 timeMs, bool pauseTimer=false)
{
}

//! sets the caption of the window
void CIrrDeviceAndroid::setWindowCaption(const wchar_t* text)
{
}

//! presents a surface in the client area
bool CIrrDeviceAndroid::present(video::IImage* surface, void* windowId, core::rect<s32>* srcClip)
{
	return true;
}

//! notifies the device that it should close itself
void CIrrDeviceAndroid::closeDevice()
{
}

//! \return Pointer to a list with all video modes supported
video::IVideoModeList* CIrrDeviceAndroid::getVideoModeList()
{
	return NULL;
}

//! returns if window is active. if not, nothing need to be drawn
bool CIrrDeviceAndroid::isWindowActive() const
{
	return true;
}


bool CIrrDeviceAndroid::isWindowFocused() const
{
	return isWindowActive();
}


bool CIrrDeviceAndroid::isWindowMinimized() const
{
	return !isWindowActive();
}

//! Set the current Gamma Value for the Display
bool CIrrDeviceAndroid::setGammaRamp( f32 red, f32 green, f32 blue, f32 brightness, f32 contrast )
{
	return false;
}

//! Get the current Gamma Value for the Display
bool CIrrDeviceAndroid::getGammaRamp( f32 &red, f32 &green, f32 &blue, f32 &brightness, f32 &contrast )
{
	return false;
}

//! returns color format of the window.
video::ECOLOR_FORMAT CIrrDeviceAndroid::getColorFormat() const
{
		return CIrrDeviceStub::getColorFormat();
}

//! Sets if the window should be resizeable in windowed mode.
void CIrrDeviceAndroid::setResizable(bool resize)
{
}


//! Minimizes the window
void CIrrDeviceAndroid::minimizeWindow()
{
}


//! Maximizes the window if possible.
void CIrrDeviceAndroid::maximizeWindow()
{
}


//! Restore the window to normal size if possible.
void CIrrDeviceAndroid::restoreWindow()
{
}

//! Activate any joysticks, and generate events for them.
bool CIrrDeviceAndroid::activateJoysticks(core::array<SJoystickInfo> & joystickInfo)
{
	return false;
}

}

#endif // _IRR_COMPILE_WITH_ANDROID_DEVICE_
