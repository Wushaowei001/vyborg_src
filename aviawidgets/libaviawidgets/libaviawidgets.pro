QT       += widgets sql
QT       -= gui

TARGET = aviawidgets
TEMPLATE = lib

DEFINES += LIBAVIAWIDGETS_LIBRARY

include(src/files.pri)

unix {
    DIR_PREFIX = /usr/local

    HEADERS_INSTALL_DIR = $$DIR_PREFIX/include/$$TARGET
    headers.extra = mkdir -p $$HEADERS_INSTALL_DIR
    headers.files = $$HEADERS
    headers.path = $$HEADERS_INSTALL_DIR
    INSTALLS += headers

#    features.extra = echo $$QMAKESPEC
    features.files = aviawidgets.prf
    features.path = $$QMAKESPEC/../features/unix
    INSTALLS += features

    target.path = /usr/local/lib/aviawidgets
    INSTALLS += target
}

#DISTFILES += \
#    ../gis/ad/src/rwwidget/files.pri

DISTFILES += \
    aviawidgets.prf