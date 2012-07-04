#include <android-receiver.h>
#include <android/log.h>


extern int gAppAlive;

bool AndroidEventReceiver::OnEvent(const SEvent& event)
{
    __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "Lolo");
    
    if (event.EventType == EET_GUI_EVENT)
    {
        s32 id = event.GUIEvent.Caller->getID();
        IGUIEnvironment* env = Context.device->getGUIEnvironment();

        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "Lolo 2: %d %d %d %d", event.GUIEvent.EventType, EGET_BUTTON_CLICKED, id , GUI_ID_QUIT_BUTTON);
        switch(event.GUIEvent.EventType)
        {
            case EGET_BUTTON_CLICKED:
                __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "Lolo 3");
                switch(id)
                {
                    case GUI_ID_QUIT_BUTTON:
                        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "Lolo 4");
                        gAppAlive = 0;
                        return true;

                    default:
                        break;
                }
        }
    }
    return false;
}
