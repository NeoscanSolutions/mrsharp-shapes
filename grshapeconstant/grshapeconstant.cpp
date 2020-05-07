//=============================================================================================================
/**
* @file     grshapeconstant.cpp
* @author   Christoph Dinh <dinh@neoscan-solutions.com>
* @version  1.0
* @date     December, 2017
*
* @section  LICENSE
*
* Copyright (C) 2017, Neoscan Solutions GmbH. All rights reserved.
*
* THIS DOCUMENT CONTAINS PROPRIETARY INFORMATION.
* IT IS THE EXCLUSIVE CONFIDENTIAL PROPERTY OF
* NEOSCAN SOLUTIONS GMBH AND IT'S AFFILIATES.
*
*
* @brief    Contains the implementation of the Constant Gradient Shape class.
*
*/

//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "grshapeconstant.h"
#include <dvc/device.h>
#include <math.h>

//=============================================================================================================
// Qt INCLUDES
//=============================================================================================================

#include <QDebug>

//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace SQNCSLIB;
using namespace DVCLIB;
using namespace Eigen;

//=============================================================================================================
// DEFINE MEMBER METHODS
//=============================================================================================================

//=============================================================================================================
/**
* Constructor
*/
GRShapeConstant::GRShapeConstant(QObject *parent)
: INonWarpShape(parent)
{
    addOptionalParameterSlot("Gradient");
}

//=============================================================================================================
/**
* Creates an instance of the shape
* @return the new shape
*/
QSharedPointer<IShape> GRShapeConstant::create() const
{
    GRShapeConstant::SPtr pGRShapeConstant(new GRShapeConstant);
    return pGRShapeConstant;
}

//=============================================================================================================
/**
* Returns the detailed shape information
* @return the shape information
*/
QString GRShapeConstant::info() const
{
    return QString("GR shape constant info");
}

//=============================================================================================================
/**
* This pure virtual method returns the function type
*
* @return the function type
*/
QString GRShapeConstant::type() const
{
    return QString("GRShapeConstant");
}

//=============================================================================================================
/**
* TBD
*
* @return TBD
*/
int GRShapeConstant::gradientValues( double duration, double &beginValue, double &endValue )
{
    beginValue = 0;
    endValue = 0;
    if( hasParameter( "Gradient" ) ){
        double g=0;
        if( (g=fabs( parameter("Gradient")->value() )) > m_dGMax ){
            return SQNCS_SHAPE_ERROR;
        }
        else{
            beginValue = g;
            endValue = g;
        }
    }
    return SQNCS_NO_ERROR;
}


//=============================================================================================================
/**
* Samples the shape and returns the function values
* @param[in] T      total shape duration
* @param[in] dT     raster time
* @return the sampled function values
*/
MatrixXf GRShapeConstant::sample(double T, double dT)
{
    size_t rows = 1;
    size_t cols = (size_t)ceil(T / dT);
    MatrixXf samples = MatrixXf::Constant(rows, cols, parameter("Gradient")->value());
    return samples;
}

void GRShapeConstant::sample( unsigned long n, float *arr )
{
    double beginValue, endValue;
    gradientValues( -1., beginValue, endValue );
    float x = (float) beginValue;
    memset( arr, x, n*sizeof(float) );
}
