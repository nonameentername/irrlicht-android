
#ifndef __CANDROID_LOGGER_H_INCLUDED__
#define __CANDROID_LOGGER_H_INCLUDED__

#include <android/log.h>

#include <irrlicht.h>

using namespace irr;


class CAndroidLogger : public ILogger {
private:
	ELOG_LEVEL level;

public:
	CAndroidLogger() {}

	virtual ~CAndroidLogger() {}

	//! Returns the current set log level.
	virtual ELOG_LEVEL getLogLevel() const {
	
	}

	virtual void setLogLevel(ELOG_LEVEL ll) {
		level = ll;
	}

	virtual void log(const c8* text, ELOG_LEVEL ll=ELL_INFORMATION) {
		__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "log: %s", text);   
	}
	
	virtual void log(const c8* text, const c8* hint, ELOG_LEVEL ll=ELL_INFORMATION) {
		__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "log: %s", text);   
	}

	virtual void log(const c8* text, const wchar_t* hint, ELOG_LEVEL ll=ELL_INFORMATION) {
		__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "log: %s", text);   
	}
	
	virtual void log(const wchar_t* text, const wchar_t* hint, ELOG_LEVEL ll=ELL_INFORMATION) {
		__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "log: %s", text);   
	}

	virtual void log(const wchar_t* text, ELOG_LEVEL ll=ELL_INFORMATION) {
		__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "log: %s", text);   
	}


};

#endif // __CANDROID_LOGGER_H_INCLUDED__
