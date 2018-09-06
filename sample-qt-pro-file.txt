#-------------------------------------------------
#
# Project created by QtCreator 2018-08-31T16:23:35
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = sample-qt-opencv
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11 #console

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    imageviewer.cpp \
    testwindow.cpp \
    webcamwindow.cpp

HEADERS += \
        mainwindow.h \
    imageviewer.h \
    testwindow.h \
    webcamwindow.h

FORMS += \
        mainwindow.ui \
    testwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


# Please configure the paths for external libraries,
# depending on the development environment.

INCLUDEPATH += /usr/local/include

LIBS += /usr/local/lib/libopencv_contrib.so
LIBS += /usr/local/lib/libopencv_core.so
LIBS += /usr/local/lib/libopencv_features2d.so
LIBS += /usr/local/lib/libopencv_flann.so
LIBS += /usr/local/lib/libopencv_gpu.so
LIBS += /usr/local/lib/libopencv_highgui.so
LIBS += /usr/local/lib/libopencv_imgproc.so
LIBS += /usr/local/lib/libopencv_legacy.so
LIBS += /usr/local/lib/libopencv_ml.so
LIBS += /usr/local/lib/libopencv_nonfree.so
LIBS += /usr/local/lib/libopencv_objdetect.so
LIBS += /usr/local/lib/libopencv_ocl.so
LIBS += /usr/local/lib/libopencv_photo.so
LIBS += /usr/local/lib/libopencv_stitching.so
LIBS += /usr/local/lib/libopencv_superres.so
LIBS += /usr/local/lib/libopencv_ts.a
LIBS += /usr/local/lib/libopencv_video.so
LIBS += /usr/local/lib/libopencv_videostab.so



#INCLUDEPATH += C:\opencv2x\build\include
#LIBS += C:\opencv2x\build\x64\vc14\lib\opencv_contrib2413.lib
#LIBS += C:\opencv2x\build\x64\vc14\lib\opencv_core2413.lib
#LIBS += C:\opencv2x\build\x64\vc14\lib\opencv_features2d2413.lib
#LIBS += C:\opencv2x\build\x64\vc14\lib\opencv_flann2413.lib
#LIBS += C:\opencv2x\build\x64\vc14\lib\opencv_gpu2413.lib
#LIBS += C:\opencv2x\build\x64\vc14\lib\opencv_highgui2413.lib
#LIBS += C:\opencv2x\build\x64\vc14\lib\opencv_imgproc2413.lib



#INCLUDEPATH += C:\opencv3x\build\include
#LIBS += C:\opencv3x\build\x64\vc14\lib\opencv_world320.lib
#LIBS += C:\opencv3x\build\x64\vc14\lib\opencv_world320d.lib
