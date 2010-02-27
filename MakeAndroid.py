#!/usr/bin/env python

import os

objs = "CBSPMeshFileLoader.o CMD2MeshFileLoader.o CMD3MeshFileLoader.o CMS3DMeshFileLoader.o CB3DMeshFileLoader.o C3DSMeshFileLoader.o COgreMeshFileLoader.o COBJMeshFileLoader.o CColladaFileLoader.o CCSMLoader.o CDMFLoader.o CLMTSMeshFileLoader.o CMY3DMeshFileLoader.o COCTLoader.o CXMeshFileLoader.o CIrrMeshFileLoader.o CSTLMeshFileLoader.o CLWOMeshFileLoader.o CPLYMeshFileLoader.o"

objList = objs.split(" ")
objname = []
for obj in objList:
    filename = obj.split(".o")[0]
    objname.append(filename)

for filename in objname:
    os.system("find . -name " + filename + ".cpp -exec cp {} project/jni \;")
    os.system("find . -name " + filename + ".h -exec cp {} project/jni \;")

result = ""
for filename in objname:
    result +=  filename + ".cpp "

print result
