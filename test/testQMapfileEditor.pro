######################################################################
# Automatically generated by qmake (2.01a) Mon Sep 29 21:08:50 2014
######################################################################

CONFIG += qtestlib \
          testcase \
          create_prl \
          link_prl

QT += testlib
TEMPLATE = app
TARGET = test
DEPENDPATH += -L/usr/lib/x86_64-linux-gnu  \
              ../   \
              ./
INCLUDEPATH += ../  \
              ./

POST_TARGETDEPS += 


LIBS += ../debug/mapfileparser.o \
      -L/usr/lib/x86_64-linux-gnu/ -lmapserver -lgdal -lgcov



# Input
HEADERS += testmapfileparser.h
SOURCES += testmapfileparser.cpp

