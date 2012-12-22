/* Webcamod, webcam capture plasmoid.
 * Copyright (C) 2011-2012  Gonzalo Exequiel Pedone
 *
 * Webcamod is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamod is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamod. If not, see <http://www.gnu.org/licenses/>.
 *
 * Email     : hipersayan DOT x AT gmail DOT com
 * Web-Site 1: http://github.com/hipersayanX/Webcamoid
 * Web-Site 2: http://kde-apps.org/content/show.php/Webcamoid?content=144796
 */

#ifndef WEBCAMSRCELEMENT_H
#define WEBCAMSRCELEMENT_H

#include <QtGui>
#include <gst/gst.h>

#include "element.h"

class WebcamSrcElement: public Element
{
    Q_OBJECT

    Q_PROPERTY(QString device READ device
                              WRITE setDevice
                              RESET resetDevice)

    Q_PROPERTY(QSize size READ size
                          WRITE setSize
                          RESET resetSize)

    public:
        explicit WebcamSrcElement();
        ~WebcamSrcElement();

        Q_INVOKABLE QString device();
        Q_INVOKABLE QSize size();

        Q_INVOKABLE ElementState state();

    private:
        QString m_device;
        QSize m_size;
        ElementState m_state;

        QMutex m_mutex;
        int m_callBack;
        GstElement *m_pipeline;
        QImage m_oFrame;

        static void newBuffer(GstElement *appsink, gpointer self);

    public slots:
        void setDevice(QString device);
        void setSize(QSize size);
        void resetDevice();
        void resetSize();

        void iStream(const void *data, int datalen, QString dataType);
        void setState(ElementState state);
        void resetState();
};

#endif // WEBCAMSRCELEMENT_H
