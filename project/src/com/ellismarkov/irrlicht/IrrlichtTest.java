/*
 *
 */
package com.ellismarkov.irrlicht;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.MotionEvent;

import java.io.IOException;

/** */
public class IrrlichtTest extends Activity {

    private IrrlichtGLView mGLView;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        try {
            Utils.unpackOnSdCard(getAssets());
        } catch (IOException e) {
            Log.i("Irrlicht", "Error in unpack");
        }
        nativeEnvJ2C(Environment.getExternalStorageDirectory().getAbsolutePath());
        mGLView = new IrrlichtGLView(this);
        setContentView(mGLView);
        nativeOnCreate();
    }

    @Override
    protected void onPause() {
        super.onPause();
        mGLView.onPause();
        nativeOnPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mGLView.onResume();
        nativeOnResume();
    }

    @Override    
    public void onDestroy() {
        nativeOnDestroy();
        super.onDestroy();
    }

    /** load irrlicht.so */
    static {
        System.loadLibrary("irrlicht");
    }

    public native void nativeOnCreate();
    public native void nativeOnPause();
    public native void nativeOnResume();
    public native void nativeOnDestroy();

    public native void nativeInitGL();
    public native void nativeResize(int w, int h);

    public native void nativeGetStatus(IrrlichtStatus status);
    public native void nativeSendEvent(IrrlichtEvent event);
    public native void nativeEnvJ2C(String sdcardPath);

    public static native void nativeDrawIteration();
    
}

