/*
 *
 */
package org.tecunhuman.irrlicht;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.app.Activity;
import android.content.res.AssetManager;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.MotionEvent;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

/** */
public class IrrlichtTest extends Activity {

    private IrrlichtGLView mGLView;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        try {
        	CopyAssets();
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
    
    private void CopyAssets() {
        AssetManager assetManager = getAssets();
        String[] files = null;
        try {
            files = assetManager.list("");
        } catch (IOException e) {
            Log.e("tag", e.getMessage());
        }
        for(String filename : files) {
            InputStream in = null;
            OutputStream out = null;
            try {
              in = assetManager.open(filename);
              out = new FileOutputStream("/sdcard/Irrlicht/" + filename);
              copyFile(in, out);
              in.close();
              in = null;
              out.flush();
              out.close();
              out = null;
            } catch(Exception e) {
                Log.e("tag", e.getMessage());
            }       
        }
    }
    private void copyFile(InputStream in, OutputStream out) throws IOException {
        byte[] buffer = new byte[1024];
        int read;
        while((read = in.read(buffer)) != -1){
          out.write(buffer, 0, read);
        }
    }
}

