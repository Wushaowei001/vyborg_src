QT       += core gui sql widgets
TARGET   =  statistics_month
TEMPLATE =  app
DESTDIR = /home/debian/bin

OBJECTS_DIR = tmp
MOC_DIR = tmp

DEPENDPATH += .

include(src/files.pri)

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg

DISTFILES += \
    src/files.pri
