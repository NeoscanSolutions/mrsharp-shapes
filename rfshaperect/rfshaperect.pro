#--------------------------------------------------------------------------------------------------------------
#
# @file     rectshape.pro
# @author   Christoph Dinh <dinh@neoscan-solutions.com>
# @version  1.0
# @date     May, 2019
#
# @section  LICENSE
#
# Copyright (C) 2019, Neoscan Solutions GmbH. All rights reserved.
#
# THIS DOCUMENT CONTAINS PROPRIETARY INFORMATION.
# IT IS THE EXCLUSIVE CONFIDENTIAL PROPERTY OF
# NEOSCAN SOLUTIONS GMBH AND IT'S AFFILIATES.
#
#
# @brief    This project file generates the makefile for the rect shape.
#
#--------------------------------------------------------------------------------------------------------------

TEMPLATE = lib

CONFIG += plugin

DEFINES += RFSHAPE_RECT

QT += core

TARGET = rfshaperect

include(../build_config.pri)

LIBS += -L$${NEOSCAN_LIBRARY_DIR}
CONFIG(debug, debug|release) {
    LIBS += \
        -lneo_mathd \
        -lneo_dispd \
        -lneo_dvcd \
        -lneo_sqncsd
}
else {
    LIBS += \
        -lneo_math \
        -lneo_disp \
        -lneo_dvc \
        -lneo_sqncs
}

DESTDIR = $${NEOSCAN_BINARY_DIR}/shapes

SOURCES += \
    rfshaperect.cpp

HEADERS += \
    rfshaperect.h \
    rfshaperect_global.h

INCLUDEPATH += $${NEOSCAN_INCLUDE_DIR}

DISTFILES += \
    rfshaperect.json
