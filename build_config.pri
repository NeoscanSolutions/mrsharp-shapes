############################################## GLOBAL FUNCTIONS ###############################################
#Define minQtVersion Test
defineTest(minQtVersion) {
    maj = $$1
    min = $$2
    patch = $$3
    isEqual(QT_MAJOR_VERSION, $$maj) {
        isEqual(QT_MINOR_VERSION, $$min) {
            isEqual(QT_PATCH_VERSION, $$patch) {
                return(true)
            }
            greaterThan(QT_PATCH_VERSION, $$patch) {
                return(true)
            }
        }
        greaterThan(QT_MINOR_VERSION, $$min) {
            return(true)
        }
    }
    greaterThan(QT_MAJOR_VERSION, $$maj) {
        return(true)
    }
    return(false)
}

############################################### GLOBAL DEFINES ################################################

NEOSCAN_VERSION = 1.0.0

QMAKE_TARGET_PRODUCT = neoscan
QMAKE_TARGET_DESCRIPTION = Neoscan Qt 5 based C++ library.
QMAKE_TARGET_COPYRIGHT = Copyright (C) 2020, Neoscan Solutions GmbH. All rights reserved.

########################################### DIRECTORY DEFINITIONS #############################################

# setup
NEOSCAN_SETUP_DIR = $$NEOSCAN_SETUP_DIR
isEmpty( NEOSCAN_SETUP_DIR ) {
    NEOSCAN_SETUP_DIR = D:\Users\Christoph\Git\neoscan#<path_to_setup_dir>/neoscan #adjust path to your setup directory
}

# include
NEOSCAN_INCLUDE_DIR = $$NEOSCAN_INCLUDE_DIR
isEmpty( NEOSCAN_INCLUDE_DIR ) {
    NEOSCAN_INCLUDE_DIR = $${NEOSCAN_SETUP_DIR}/include/core_libraries
    message($$NEOSCAN_INCLUDE_DIR)
}

# lib
NEOSCAN_LIBRARY_DIR = $$NEOSCAN_LIBRARY_DIR
isEmpty( NEOSCAN_LIBRARY_DIR ) {
    NEOSCAN_LIBRARY_DIR = $${NEOSCAN_SETUP_DIR}/lib
}

# bin
NEOSCAN_BINARY_DIR = $$NEOSCAN_BINARY_DIR
isEmpty( NEOSCAN_BINARY_DIR ) {
    NEOSCAN_BINARY_DIR = $${NEOSCAN_SETUP_DIR}/bin
}

########################################### PROJECT DEFINITIONS #############################################

# add suffix "d" to debug output
CONFIG(debug, debug|release) {
    TARGET = $$join(TARGET,,,d)
}
