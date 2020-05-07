//=============================================================================================================
/**
* @file     rfshaperect.cpp
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
* @brief    Contains the implementation of the RFShapeRect class.
*
*/

//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "rfshaperect.h"

#define _USE_MATH_DEFINES
#include <math.h>

//=============================================================================================================
// Qt INCLUDES
//=============================================================================================================

#include <QDebug>

//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace SQNCSLIB;
using namespace Eigen;

//=============================================================================================================
// DEFINE MEMBER METHODS
//=============================================================================================================

//=============================================================================================================
/**
* Constructor
*/
RFShapeRect::RFShapeRect(QObject *parent)
: ITxShape(parent)
{
    //addRequiredParameterSlot("Amplitude");
    //addRequiredParameterSlot("FlipAngle");// Missused as flip angle
    //addRequiredParameterSlot("Duration");

    m_amplitude_integral = 1.;
    m_bwtp = 1.; // tbd not calibrated!
}

//=============================================================================================================
/**
* Creates an instance of the shape
*
* @return the new shape
*/
QSharedPointer<IShape> RFShapeRect::create() const
{
    RFShapeRect::SPtr pRFShapeRect(new RFShapeRect);
    return pRFShapeRect;
}

//=============================================================================================================
/**
* Returns the detailed shape information
* @return the shape information
*/
QString RFShapeRect::info() const
{
    return QString("RF Shape Rect info");
}

//=============================================================================================================
/**
* This pure virtual method returns the function type
*
* @return the function type
*/
QString RFShapeRect::type() const
{
    return QString("RFShapeRect");
}

//=============================================================================================================
/**
* Samples the shape and returns the function values
* @param[in] T      total shape duration
* @param[in] dT     raster time
* @return the sampled function values
*/
MatrixXf RFShapeRect::sample(double T, double dT)
{
    float U0 = parameter("Amplitude")->value();

    float phase = parameter("FlipAngle")->value();

    float real = U0 * cos(phase * M_PI / 180.), imag = U0 * sin(phase * M_PI / 180.);

    size_t rows = 2;
    size_t cols = (size_t)ceil(T / dT);
    MatrixXf samples = MatrixXf::Zero(rows,cols);

    size_t preSamples = 0.0001 / dT;    // Give Marcus some pre ramping time. i.e., pre samples -> 100 us
    size_t postSamples = 0.0001 / dT;   // Give Marcus some post ramping time. i.e., post samples -> 100 us


    for(size_t i = 0; i < cols; ++i ) {

        if(i < preSamples || i > cols-postSamples) { // Give Marcus some ramping time. i.e., pre post samples -> 100 us
            samples(0,i) = 0;
            samples(1,i) = 0;
        }
        else {
            samples(0,i) = real;
            samples(1,i) = imag;
        }
    }

    return samples;
}

//=============================================================================================================
/**
 * @brief RFShapeRect::sample
 * @param t
 * @return
 */
float RFShapeRect::sample( float t )
{
    t += 0;
    return (float)1.;
}
