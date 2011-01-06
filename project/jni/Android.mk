# 
# COSOperator.cpp was removed from IRROTHEROBJ
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

IRRMESHLOADER = CBSPMeshFileLoader.cpp CMD2MeshFileLoader.cpp CMD3MeshFileLoader.cpp CMS3DMeshFileLoader.cpp CB3DMeshFileLoader.cpp C3DSMeshFileLoader.cpp COgreMeshFileLoader.cpp COBJMeshFileLoader.cpp CColladaFileLoader.cpp CCSMLoader.cpp CDMFLoader.cpp CLMTSMeshFileLoader.cpp CMY3DMeshFileLoader.cpp COCTLoader.cpp CXMeshFileLoader.cpp CIrrMeshFileLoader.cpp CSTLMeshFileLoader.cpp CLWOMeshFileLoader.cpp CPLYMeshFileLoader.cpp
IRRMESHWRITER = CColladaMeshWriter.cpp CIrrMeshWriter.cpp CSTLMeshWriter.cpp COBJMeshWriter.cpp CPLYMeshWriter.cpp
IRRMESHOBJ = $(IRRMESHLOADER) $(IRRMESHWRITER) CSkinnedMesh.cpp CBoneSceneNode.cpp CMeshSceneNode.cpp CAnimatedMeshSceneNode.cpp CAnimatedMeshMD2.cpp CAnimatedMeshMD3.cpp CQ3LevelMesh.cpp CQuake3ShaderSceneNode.cpp
IRROBJ = CBillboardSceneNode.cpp CCameraSceneNode.cpp CDummyTransformationSceneNode.cpp CEmptySceneNode.cpp CGeometryCreator.cpp CLightSceneNode.cpp CMeshManipulator.cpp CMetaTriangleSelector.cpp COctreeSceneNode.cpp COctreeTriangleSelector.cpp CSceneCollisionManager.cpp CSceneManager.cpp CShadowVolumeSceneNode.cpp CSkyBoxSceneNode.cpp CSkyDomeSceneNode.cpp CTerrainSceneNode.cpp CTerrainTriangleSelector.cpp CVolumeLightSceneNode.cpp CCubeSceneNode.cpp CSphereSceneNode.cpp CTextSceneNode.cpp CTriangleBBSelector.cpp CTriangleSelector.cpp CWaterSurfaceSceneNode.cpp CMeshCache.cpp CDefaultSceneNodeAnimatorFactory.cpp CDefaultSceneNodeFactory.cpp
IRRPARTICLEOBJ = CParticleAnimatedMeshSceneNodeEmitter.cpp CParticleBoxEmitter.cpp CParticleCylinderEmitter.cpp CParticleMeshEmitter.cpp CParticlePointEmitter.cpp CParticleRingEmitter.cpp CParticleSphereEmitter.cpp CParticleAttractionAffector.cpp CParticleFadeOutAffector.cpp CParticleGravityAffector.cpp CParticleRotationAffector.cpp CParticleSystemSceneNode.cpp CParticleScaleAffector.cpp
IRRANIMOBJ = CSceneNodeAnimatorCameraFPS.cpp CSceneNodeAnimatorCameraMaya.cpp CSceneNodeAnimatorCollisionResponse.cpp CSceneNodeAnimatorDelete.cpp CSceneNodeAnimatorFlyCircle.cpp CSceneNodeAnimatorFlyStraight.cpp CSceneNodeAnimatorFollowSpline.cpp CSceneNodeAnimatorRotation.cpp CSceneNodeAnimatorTexture.cpp
IRRDRVROBJ = CNullDriver.cpp COGLESDriver.cpp COGLESTexture.cpp COGLESExtensionHandler.cpp
IRRDRVOBJ2 = COGLES2Driver.cpp COGLES2FixedPipelineShader.cpp COGLES2ParallaxMapRenderer.cpp COGLES2SLMaterialRenderer.cpp COGLES2ExtensionHandler.cpp COGLES2NormalMapRenderer.cpp COGLES2Renderer2D.cpp COGLES2Texture.cpp

IRRIMAGEOBJ = CColorConverter.cpp CImage.cpp CImageLoaderBMP.cpp CImageLoaderJPG.cpp CImageLoaderPCX.cpp CImageLoaderPNG.cpp CImageLoaderPSD.cpp CImageLoaderTGA.cpp CImageLoaderPPM.cpp CImageLoaderWAL.cpp CImageLoaderRGB.cpp CImageWriterBMP.cpp CImageWriterJPG.cpp CImageWriterPCX.cpp CImageWriterPNG.cpp CImageWriterPPM.cpp CImageWriterPSD.cpp CImageWriterTGA.cpp
IRRVIDEOOBJ = CVideoModeList.cpp CFPSCounter.cpp $(IRRDRVROBJ) $(IRRIMAGEOBJ)
IRRSWRENDEROBJ = CSoftwareDriver.cpp CSoftwareTexture.cpp CTRFlat.cpp CTRFlatWire.cpp CTRGouraud.cpp CTRGouraudWire.cpp CTRTextureFlat.cpp CTRTextureFlatWire.cpp CTRTextureGouraud.cpp CTRTextureGouraudAdd.cpp CTRTextureGouraudNoZ.cpp CTRTextureGouraudWire.cpp CZBuffer.cpp CTRTextureGouraudVertexAlpha2.cpp CTRTextureGouraudNoZ2.cpp CTRTextureLightMap2_M2.cpp CTRTextureLightMap2_M4.cpp CTRTextureLightMap2_M1.cpp CSoftwareDriver2.cpp CSoftwareTexture2.cpp CTRTextureGouraud2.cpp CTRGouraud2.cpp CTRGouraudAlpha2.cpp CTRGouraudAlphaNoZ2.cpp CTRTextureDetailMap2.cpp CTRTextureGouraudAdd2.cpp CTRTextureGouraudAddNoZ2.cpp CTRTextureWire2.cpp CTRTextureLightMap2_Add.cpp CTRTextureLightMapGouraud2_M4.cpp IBurningShader.cpp CTRTextureBlend.cpp CTRTextureGouraudAlpha.cpp CTRTextureGouraudAlphaNoZ.cpp CDepthBuffer.cpp CBurningShader_Raster_Reference.cpp
IRRIOOBJ = CFileList.cpp CFileSystem.cpp CLimitReadFile.cpp CMemoryFile.cpp CReadFile.cpp CWriteFile.cpp CXMLReader.cpp CXMLWriter.cpp CZipReader.cpp CPakReader.cpp CNPKReader.cpp CTarReader.cpp CMountPointReader.cpp irrXML.cpp CAttributes.cpp lzma/LzmaDec.c
IRROTHEROBJ = CIrrDeviceConsole.cpp CIrrDeviceStub.cpp CLogger.cpp Irrlicht.cpp os.cpp
IRRGUIOBJ = CGUIButton.cpp CGUICheckBox.cpp CGUIComboBox.cpp CGUIContextMenu.cpp CGUIEditBox.cpp CGUIEnvironment.cpp CGUIFileOpenDialog.cpp CGUIFont.cpp CGUIImage.cpp CGUIInOutFader.cpp CGUIListBox.cpp CGUIMenu.cpp CGUIMeshViewer.cpp CGUIMessageBox.cpp CGUIModalScreen.cpp CGUIScrollBar.cpp CGUISpinBox.cpp CGUISkin.cpp CGUIStaticText.cpp CGUITabControl.cpp CGUITable.cpp CGUIToolBar.cpp CGUIWindow.cpp CGUIColorSelectDialog.cpp CDefaultGUIElementFactory.cpp CGUISpriteBank.cpp CGUIImageList.cpp CGUITreeView.cpp

ZLIBOBJ = zlib/adler32.c zlib/compress.c zlib/crc32.c zlib/deflate.c zlib/inffast.c zlib/inflate.c zlib/inftrees.c zlib/trees.c zlib/uncompr.c zlib/zutil.c
JPEGLIBOBJ = jpeglib/jcapimin.c jpeglib/jcapistd.c jpeglib/jccoefct.c jpeglib/jccolor.c jpeglib/jcdctmgr.c jpeglib/jchuff.c jpeglib/jcinit.c jpeglib/jcmainct.c jpeglib/jcmarker.c jpeglib/jcmaster.c jpeglib/jcomapi.c jpeglib/jcparam.c jpeglib/jcprepct.c jpeglib/jcsample.c jpeglib/jctrans.c jpeglib/jdapimin.c jpeglib/jdapistd.c jpeglib/jdatadst.c jpeglib/jdatasrc.c jpeglib/jdcoefct.c jpeglib/jdcolor.c jpeglib/jddctmgr.c jpeglib/jdhuff.c jpeglib/jdinput.c jpeglib/jdmainct.c jpeglib/jdmarker.c jpeglib/jdmaster.c jpeglib/jdmerge.c jpeglib/jdpostct.c jpeglib/jdsample.c jpeglib/jdtrans.c jpeglib/jerror.c jpeglib/jfdctflt.c jpeglib/jfdctfst.c jpeglib/jfdctint.c jpeglib/jidctflt.c jpeglib/jidctfst.c jpeglib/jidctint.c jpeglib/jmemmgr.c jpeglib/jmemnobs.c jpeglib/jquant1.c jpeglib/jquant2.c jpeglib/jutils.c jpeglib/jcarith.c jpeglib/jdarith.c jpeglib/jaricom.c
LIBPNGOBJ = libpng/png.c libpng/pngerror.c libpng/pngget.c libpng/pngmem.c libpng/pngpread.c libpng/pngread.c libpng/pngrio.c libpng/pngrtran.c libpng/pngrutil.c libpng/pngset.c libpng/pngtrans.c libpng/pngwio.c libpng/pngwrite.c libpng/pngwtran.c libpng/pngwutil.c
LIBAESGM = aesGladman/aescrypt.cpp aesGladman/aeskey.cpp aesGladman/aestab.cpp aesGladman/fileenc.cpp aesGladman/hmac.cpp aesGladman/prng.cpp aesGladman/pwd2key.cpp aesGladman/sha1.cpp aesGladman/sha2.cpp
BZIP2OBJ = bzip2/blocksort.c bzip2/huffman.c bzip2/crctable.c bzip2/randtable.c bzip2/bzcompress.c bzip2/decompress.c bzip2/bzlib.c
ANDROID = importgl.cpp app-android.cpp android-activity.cpp android-receiver.cpp CIrrDeviceAndroid.cpp
LOCAL_MODULE := irrlicht

LOCAL_ARM_MODE   := arm 
LOCAL_CFLAGS := -O3 -DANDROID_NDK -DDISABLE_IMPORTGL -I./../include/ -I./include/

LOCAL_SRC_FILES := \
     $(ANDROID) \
     $(IRRVIDEOOBJ) $(IRRDRVOBJ2) \
     $(IRRMESHOBJ) $(IRROBJ) $(IRRPARTICLEOBJ) $(IRRANIMOBJ) \
     $(IRRSWRENDEROBJ) $(IRRIOOBJ) $(IRROTHEROBJ) \
     $(IRRGUIOBJ) $(ZLIBOBJ) $(JPEGLIBOBJ) $(LIBPNGOBJ) $(LIBAESGM) \
     $(BZIP2OBJ)


LOCAL_LDLIBS := -lGLESv1_CM -ldl -llog -lGLESv2

include $(BUILD_SHARED_LIBRARY)
