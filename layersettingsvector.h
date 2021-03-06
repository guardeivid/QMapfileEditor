/**********************************************************************
 * $Id$
 *
 * Project: QMapfileEditor
 * Purpose: Settings of Vector Layer Window Object
 * Author: Pierre Mauduit / Yves Jacolin
 *
 **********************************************************************
 * Copyright (c) 2014, Yves Jacolin
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

#ifndef LAYERSETTINGSVECTOR_H
#define LAYERSETTINGSVECTOR_H

#include "layersettings.h"

namespace Ui {
  class LayerSettingsVector;
}

class LayerSettingsVector : public LayerSettings
{
  Q_OBJECT ;

 public:
      explicit LayerSettingsVector(QWidget * parent, MapfileParser *m, Layer *l);
      ~LayerSettingsVector();
      QString getLayerName() const;
      int     getLayerStatus() const;
      QString getLayerRequires() const;
      QString getLayerMask() const;
      int     getLayerOpacity() const;
      QString getLayerGroup() const;
      int     getLayerDebugLevel() const;
      double  getLayerMinScaleDenom() const;
      double  getLayerMaxScaleDenom() const;
      QString getLayerTemplate() const;
      QString getLayerHeader() const;
      QString getLayerFooter() const;

 public slots:
      void accept();
      void reject();

 private:
      Ui::LayerSettingsVector * ui;
};

#endif // LAYERSETTINGSVECTOR_H

