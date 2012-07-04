/*
 *
 */
package org.tecunhuman.irrlicht;

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
        AndroidJNI.irrlicht.setPath(Environment.getExternalStorageDirectory().getAbsolutePath());
        mGLView = new IrrlichtGLView(this);
        setContentView(mGLView);
        
        AndroidJNI.irrlicht.init();
        AndroidJNI.irrlicht.onCreate();
    }

    @Override
    protected void onPause() {
        super.onPause();
        mGLView.onPause();
        AndroidJNI.irrlicht.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mGLView.onResume();
        AndroidJNI.irrlicht.onResume();
    }

    @Override    
    public void onDestroy() {
        AndroidJNI.irrlicht.onDestroy();
        super.onDestroy();
    }

    static {
        System.loadLibrary("irrlicht");
        System.loadLibrary("nativeirrlicht");
    }    
}

