TEMPLATE     = vcapp
TARGET       = graphicus03
CONFIG      += warn_on qt debug windows console
HEADERS     += graphicus_Interface.h
SOURCES     += graphicus-03.cpp graphicus_Interface.cpp
INCLUDEPATH += GraphicusGUI
LIBS        += ./QTLIB/graphicusGUI.lib
QT          += widgets
