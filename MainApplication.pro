QT += \
    quick \
    quickcontrols2 \
    qml \
    gui \
    widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp

RESOURCES += \
    qml.qrc

TRANSLATIONS += \
    HCI-Project2020_en_SE.ts


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD/src/

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    qtquickcontrols2.conf \
    src/main.qml \
    src/prototype_rasmus_qtquick.qml \
    src/test.qml

FORMS += \
    src/prototype.ui \
    src/prototype_daniel.ui

