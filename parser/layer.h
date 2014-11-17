/**********************************************************************
 * $Id$
 *
 * Project: QMapfileEditor
 * Purpose: 
 * Author: Pierre Mauduit
 *
 **********************************************************************
 * Copyright (c) 2014, Pierre Mauduit
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies of this Software or works derived from this Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 ****************************************************************************/

#ifndef LAYER_H
#define LAYER_H

#include <QHash>
#include <QModelIndex>
#include <QString>
#include <QStringList>

/**
 * This class shall be considered as an interface
 * between the mapfile and the layers model to fit
 * in the GUI.
 */

class Layer {
  public:
    Layer(QString const & name, struct mapObj *);

    QString const & getName();
    void setName(QString const &);

    // static variables (from mapserver.h)
    static QStringList layerType;

  private:
    // Note: in Mapserver, name is used as a primary key
    // Hence, this member variable has a specific role.
    QString name;

    // Since modifications of layers could have an impact on the in-memory
    // objects (e.g. deletion), we prefer keeping a reference the the map
    // object, instead of the layerObj ones.
    struct mapObj * map;

    int getInternalIndex();
    struct layerObj * getInternalLayerObj();

    // Significant member variables for the model

    /** General tab  */
    bool status;
    // TODO: there may be some types (enums ?) more appropriate
    // For now, getting what @yjacolin put in the interface
    QString type;
    QString geomType;
    int opacity;
    QString mask;
    QString group;
    QString requires;

    QString plugin;
    // TODO These could probably be merged
    QString projType;
    QString projString;

    double minx, miny, maxx, maxy;

    QString filter;

    // minscale / maxscale onto layerObj (mapserver side)
    double minScale, maxScale;


    /** Advanced tab */
    QString geomTransformation;
    double tolerance;
    QString toleranceUnit;
    QString processing;

    bool transform;
    int maxfeatures;
    double mingeowidth, maxgeowidth;

    // TODO: cluster ??


    QString layerTemplate;
    QString header, footer;

    /** classes tab */
    // TODO: needs a LayerClass class definition

    /** label tab  */
    QString labelItem;
    double minScaleDenomLabel, maxScaleDenomLabel;
    int labelAngleItem;
    bool labelCache;
    bool postLabelCache;
    int labelSizeItem;
    QString labelRequires;

    /** web services tab */

    /** validation tab */
    QString validation;

    /** debug tab */
    int debugLevel;

};


#endif // LAYER_H

