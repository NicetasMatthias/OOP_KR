QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    application.cpp \
    car.cpp \
    gas.cpp \
    interface.cpp \
    main.cpp \
    model.cpp \
    parking.cpp \
    window_control.cpp \
    window_info.cpp \
    window_log.cpp

HEADERS += \
    application.h \
    car.h \
    events.h \
    gas.h \
    interface.h \
    model.h \
    parking.h \
    state.h \
    window_control.h \
    window_info.h \
    window_log.h

FORMS += \
    interface.ui \
    window_control.ui \
    window_info.ui \
    window_log.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
