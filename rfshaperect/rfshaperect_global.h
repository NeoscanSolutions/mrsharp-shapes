//=============================================================================================================
/**
* @file     rectshape_global.h
* @author   Christoph Dinh <dinh@neoscan-solutions.com>
* @version  1.0
* @date     January, 2018
*
* @section  LICENSE
*
* Copyright (C) 2018, Neoscan Solutions GmbH. All rights reserved.
*
* THIS DOCUMENT CONTAINS PROPRIETARY INFORMATION.
* IT IS THE EXCLUSIVE CONFIDENTIAL PROPERTY OF
* NEOSCAN SOLUTIONS GMBH AND IT'S AFFILIATES.
*
*
* @brief    Contains the RectShape library export/import macros.
*
*/

#ifndef RFSHAPERECT_GLOBAL_H
#define RFSHAPERECT_GLOBAL_H


//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QtCore/qglobal.h>


//*************************************************************************************************************
//=============================================================================================================
// PREPROCESSOR DEFINES
//=============================================================================================================

#if defined(RFSHAPE_RECT)
#  define RFSHAPERECTSHARED_EXPORT Q_DECL_EXPORT   /**< Q_DECL_EXPORT must be added to the declarations of symbols used when compiling a shared library. */
#else
#  define RFSHAPERECTSHARED_EXPORT Q_DECL_IMPORT   /**< Q_DECL_IMPORT must be added to the declarations of symbols used when compiling a client that uses the shared library. */
#endif

#endif // RFSHAPERECT_GLOBAL_H
