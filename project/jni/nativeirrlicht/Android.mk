LOCAL_PATH := $(call my-dir)

PACKAGE_NAME := org.tecunhuman.irrlicht.jni

JAVA_DIR := $(LOCAL_PATH)/../../src/$(shell echo $(PACKAGE_NAME) | sed 's/\./\//g')
NDK_DIR := $(LOCAL_PATH)/gen

$(shell mkdir -p $(JAVA_DIR))
$(shell mkdir -p $(NDK_DIR))

$(shell \
	swig -c++ -java -package $(PACKAGE_NAME) \
	-outdir $(JAVA_DIR) \
	-o $(NDK_DIR)/wrapper_wrap.cpp \
	$(LOCAL_PATH)/wrapper.i \
)

include $(CLEAR_VARS)

LOCAL_MODULE := nativeirrlicht

LOCAL_CFLAGS := -g -O0 -fno-inline -DANDROID_NDK -DDISABLE_IMPORTGL

LOCAL_SRC_FILES := \
	NativeIrrlicht.cpp \
	android-receiver.cpp \
	app-android.cpp \
	gen/wrapper_wrap.cpp

LOCAL_SHARED_LIBRARIES := irrlicht

LOCAL_LDLIBS := -lGLESv1_CM -ldl -llog

include $(BUILD_SHARED_LIBRARY)
