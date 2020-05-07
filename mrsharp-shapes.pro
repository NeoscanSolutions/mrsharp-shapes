#--------------------------------------------------------------------------------------------------------------
#
# @file     mrsharp-shapes.pro
# @author   Christoph Dinh <dinh@neoscan-solutions.com>
# @version  1.0
# @date     May, 2020
#
# @section  LICENSE
#
# Copyright (C) 2020, Neoscan Solutions GmbH. All rights reserved.
#
# THIS DOCUMENT CONTAINS PROPRIETARY INFORMATION.
# IT IS THE EXCLUSIVE CONFIDENTIAL PROPERTY OF
# NEOSCAN SOLUTIONS GMBH AND IT'S AFFILIATES.
#
#
# @brief    This project file builds all mrsharp-shapes.
#
#--------------------------------------------------------------------------------------------------------------

include(build_config.pri)

TEMPLATE = subdirs

#At least version 5.14.2
!minQtVersion(5, 14, 2) {
    message("Cannot build MRsharp operators with Qt version $${QT_VERSION}.")
    error("Use at least Qt 5.14.2.")
}

SUBDIRS += \
    grshapeconstant \
    rfshaperect

CONFIG += ordered
