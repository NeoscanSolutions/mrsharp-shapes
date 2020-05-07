//=============================================================================================================
/**
* @file     grshapeconstant.h
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
* @brief    Contains the declaration of the GRShapeConstant class.
*
*/

#ifndef GRSHAPECONSTANT_H
#define GRSHAPECONSTANT_H

//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "grshapeconstant_global.h"
#include <sqncs/shapes/INonWarpShape.h>


//*************************************************************************************************************
//=============================================================================================================
// Eigen INCLUDES
//=============================================================================================================

#include <Eigen/Core>


//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE SQNCSLIB
//=============================================================================================================

namespace SQNCSLIB
{

//=============================================================================================================
/**
* Linear series definition, which can also be used as a constant series
*
* @author   Christoph Dinh
* @date     December, 2017
*/
class GRSHAPECONSTANTSHARED_EXPORT GRShapeConstant : public INonWarpShape
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "sqncslib/1.0" FILE "grshapeconstant.json") //New Qt5 Plugin system replaces Q_EXPORT_PLUGIN2 macro
    // Use the Q_INTERFACES() macro to tell Qt's meta-object system about the interfaces
    Q_INTERFACES(SQNCSLIB::IGradientShape)

public:
    typedef QSharedPointer<GRShapeConstant> SPtr;              /**< Shared pointer type. */
    typedef QSharedPointer<const GRShapeConstant> ConstSPtr;   /**< Const shared pointer type. */

    GRShapeConstant(QObject *parent = Q_NULLPTR);

    /**
    * Destructor
    */
    virtual ~GRShapeConstant() = default;

    virtual QSharedPointer<IShape> create() const override;

    virtual QString info() const override;

    virtual QString type() const override;

    virtual int gradientValues( double duration, double &beginValue, double &endValue ) override;

    virtual Eigen::MatrixXf sample(double T, double dT) override;

    void sample( unsigned long n, float *arr ) override;
};

} // NAMESPACE

#endif // GRSHAPECONSTANT_H
