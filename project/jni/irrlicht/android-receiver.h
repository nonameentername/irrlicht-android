#ifndef __ANDROID_RECEIVER_H_INCLUDED__
#define __ANDROID_RECEIVER_H_INCLUDED__

#include <irrlicht.h>

using namespace irr;

using namespace gui;

enum
{
        GUI_ID_QUIT_BUTTON = 101,
        GUI_ID_NEW_WINDOW_BUTTON,
        GUI_ID_FILE_OPEN_BUTTON,
        GUI_ID_TRANSPARENCY_SCROLL_BAR
};


struct SAppContext
{
    IrrlichtDevice *device;
    s32          counter;
    IGUIListBox*    listbox;
};


class AndroidEventReceiver : public IEventReceiver
{
private:
    SAppContext & Context;
public:
    AndroidEventReceiver(SAppContext & context) : Context(context) { }

    virtual bool OnEvent(const SEvent& event);
};

#endif // __ANDROID_RECEIVER_H_INCLUDED__
