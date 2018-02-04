#-------------------------------------------------
#
# Project created by QtCreator 2017-05-31T19:54:21
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = oykinect2_gui
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    thread.cpp \
    myKinect.cpp \
    packet.cpp

HEADERS  += mainwindow.h \
    thread.h\
    inc/Kinect.Face.h \
    inc/Kinect.h \
    inc/Kinect.INPC.h \
    inc/Kinect.VisualGestureBuilder.h \
    inc/NuiKinectFusionApi.h \
    inc/NuiKinectFusionBase.h \
    inc/NuiKinectFusionCameraPoseFinder.h \
    inc/NuiKinectFusionColorVolume.h \
    inc/NuiKinectFusionDepthProcessor.h \
    inc/NuiKinectFusionVolume.h \
    myKinect.h \
    global.h \
    com.h \
    ihandle.h \
    packet.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$quote(C://Program Files//Microsoft SDKs//Kinect//v2.0_1409//inc)
LIBS += -L$$quote(C://Program Files//Microsoft SDKs//Kinect//v2.0_1409//Lib//x86) \
    -lKinect20

INCLUDEPATH += $$quote(C://Program Files//opencv//include//)
INCLUDEPATH += $$quote(C://Program Files//opencv//include//opencv)
INCLUDEPATH += $$quote(C://Program Files//opencv//include//opencv2)

LIBS += -L$$quote(C://Program Files//opencv//x86//vc12//lib) \
    -lopencv_core249 \
    -lopencv_highgui249 \
    -lopencv_imgproc249 \
    -lopencv_features2d249 \
    -lopencv_calib3d249 \
    -lopencv_nonfree249 \
    -lopencv_legacy249 \

RESOURCES += \
    rc.qrc
