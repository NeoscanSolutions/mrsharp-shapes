//=============================================================================================================
/**
* @file     rfshaperect.h
* @author   Christoph Dinh <dinh@neoscan-solutions.com>
* @version  1.0
* @date     May, 2019
*
* @section  LICENSE
*
* Copyright (C) 2019, Neoscan Solutions GmbH. All rights reserved.
*
* THIS DOCUMENT CONTAINS PROPRIETARY INFORMATION.
* IT IS THE EXCLUSIVE CONFIDENTIAL PROPERTY OF
* NEOSCAN SOLUTIONS GMBH AND IT'S AFFILIATES.
*
*
* @brief    Contains the declaration of the RFShapeRect class.
*
*/

#ifndef RFSHAPERECT_H
#define RFSHAPERECT_H

//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "rfshaperect_global.h"
#include <sqncs/shapes/ITxShape.h>

//=============================================================================================================
// Eigen INCLUDES
//=============================================================================================================

#include <Eigen/Core>

//=============================================================================================================
// DEFINE NAMESPACE SQNCSLIB
//=============================================================================================================

namespace SQNCSLIB
{

//=============================================================================================================
/**
* Rect shape definition
*
* @author   Christoph Dinh
* @date     May, 2019
*/
class RFSHAPERECTSHARED_EXPORT RFShapeRect : public ITxShape
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "sqncslib/1.0" FILE "rfshaperect.json") //New Qt5 Plugin system replaces Q_EXPORT_PLUGIN2 macro
    // Use the Q_INTERFACES() macro to tell Qt's meta-object system about the interfaces
    Q_INTERFACES(SQNCSLIB::ITxShape)

public:
    typedef QSharedPointer<RFShapeRect> SPtr;              /**< Shared pointer type. */
    typedef QSharedPointer<const RFShapeRect> ConstSPtr;   /**< Const shared pointer type. */

    RFShapeRect(QObject *parent = Q_NULLPTR);

    /**
    * Destructor
    */
    virtual ~RFShapeRect() = default;

    virtual QSharedPointer<IShape> create() const override;

    virtual QString info() const override;

    virtual QString type() const override;

    virtual Eigen::MatrixXf sample(double T, double dT) override;

    virtual float sample( float t ) override;

};

} // NAMESPACE

#endif // RFSHAPERECT_H
