package org.tecunhuman.irrlicht;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.util.Log;
import android.view.MotionEvent;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;



/**  IrrlichtGLView */
class IrrlichtGLView extends GLSurfaceView {
    private IrrlichtTest mActivity;
    private IrrlichtRenderer mRenderer;

    public IrrlichtGLView(IrrlichtTest activity) {
        super(activity);
        mActivity = activity;
        mRenderer = new IrrlichtRenderer(activity);
        setRenderer(mRenderer);
    }

    public boolean onTouchEvent(final MotionEvent event) {
        if (mRenderer!=null) {
            AndroidJNI.irrlicht.sendEvent(event.getAction(), event.getX(), event.getY());
        }
        return true;
    }
}

class IrrlichtRenderer implements GLSurfaceView.Renderer {
    private IrrlichtTest mActivity;

    public IrrlichtRenderer(IrrlichtTest activity) {
        mActivity = activity;
    }

    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
    }

    public void onSurfaceChanged(GL10 gl, int width, int height) {
        //AndroidJNI.irrlicht.onResize(width, height);
        AndroidJNI.irrlicht.initGL(width, height);
    }

    public void onDrawFrame(GL10 gl) {
        // render a frame
        AndroidJNI.irrlicht.drawIteration();

        // get status
        boolean status = AndroidJNI.irrlicht.getStatus();
        if (status) {
            Log.e("MESSAGE", "QUIT");
            mActivity.finish();
        }
    }
}