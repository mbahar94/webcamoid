/* Webcamoid, webcam capture application.
 * Copyright (C) 2011-2015  Gonzalo Exequiel Pedone
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
 * Email   : hipersayan DOT x AT gmail DOT com
 * Web-Site: http://github.com/hipersayanX/webcamoid
 */

#ifndef FACEDETECTELEMENT_H
#define FACEDETECTELEMENT_H

#include <QQmlComponent>
#include <QQmlContext>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsBlurEffect>
#include <opencv2/opencv.hpp>
#include <qb.h>
#include <qbutils.h>

class FaceDetectElement: public QbElement
{
    Q_OBJECT
        Q_ENUMS(MarkerType)
        Q_PROPERTY(QString haarFile
                   READ haarFile
                   WRITE setHaarFile
                   RESET resetHaarFile
                   NOTIFY haarFileChanged)
        Q_PROPERTY(QString markerType
                   READ markerType
                   WRITE setMarkerType
                   RESET resetMarkerType
                   NOTIFY markerTypeChanged)
        Q_PROPERTY(QRgb markerColor
                   READ markerColor
                   WRITE setMarkerColor
                   RESET resetMarkerColor
                   NOTIFY markerColorChanged)
        Q_PROPERTY(int markerWidth
                   READ markerWidth
                   WRITE setMarkerWidth
                   RESET resetMarkerWidth
                   NOTIFY markerWidthChanged)
        Q_PROPERTY(QString markerStyle
                   READ markerStyle
                   WRITE setMarkerStyle
                   RESET resetMarkerStyle
                   NOTIFY markerStyleChanged)
        Q_PROPERTY(QString markerImage
                   READ markerImage
                   WRITE setMarkerImage
                   RESET resetMarkerImage
                   NOTIFY markerImageChanged)
        Q_PROPERTY(QSize pixelGridSize
                   READ pixelGridSize
                   WRITE setPixelGridSize
                   RESET resetPixelGridSize
                   NOTIFY pixelGridSizeChanged)
        Q_PROPERTY(int blurRadius
                   READ blurRadius
                   WRITE setBlurRadius
                   RESET resetBlurRadius
                   NOTIFY blurRadiusChanged)
        Q_PROPERTY(QSize scanSize
                   READ scanSize
                   WRITE setScanSize
                   RESET resetScanSize
                   NOTIFY scanSizeChanged)

    public:
        enum MarkerType
        {
            MarkerTypeRectangle,
            MarkerTypeEllipse,
            MarkerTypeImage,
            MarkerTypePixelate,
            MarkerTypeBlur
        };

        explicit FaceDetectElement();

        Q_INVOKABLE QObject *controlInterface(QQmlEngine *engine,
                                              const QString &controlId) const;

        Q_INVOKABLE QString haarFile() const;
        Q_INVOKABLE QString markerType() const;
        Q_INVOKABLE QRgb markerColor() const;
        Q_INVOKABLE int markerWidth() const;
        Q_INVOKABLE QString markerStyle() const;
        Q_INVOKABLE QString markerImage() const;
        Q_INVOKABLE QSize pixelGridSize() const;
        Q_INVOKABLE int blurRadius() const;
        Q_INVOKABLE QSize scanSize() const;

    private:
        QString m_haarFile;
        MarkerType m_markerType;
        QPen m_markerPen;
        QString m_markerImage;
        QImage m_markerImg;
        QSize m_pixelGridSize;
        int m_blurRadius;
        QSize m_scanSize;

        QbElementPtr m_convert;
        QMap<MarkerType, QString> m_markerTypeToStr;
        QMap<Qt::PenStyle, QString> m_markerStyleToStr;
        cv::CascadeClassifier m_cascadeClassifier;

    signals:
        void haarFileChanged();
        void markerTypeChanged();
        void markerColorChanged();
        void markerWidthChanged();
        void markerStyleChanged();
        void markerImageChanged();
        void pixelGridSizeChanged();
        void blurRadiusChanged();
        void scanSizeChanged();

    public slots:
        void setHaarFile(const QString &haarFile);
        void setMarkerType(const QString &markerType);
        void setMarkerColor(QRgb markerColor);
        void setMarkerWidth(int markerWidth);
        void setMarkerStyle(const QString &markerStyle);
        void setMarkerImage(const QString &markerImage);
        void setPixelGridSize(const QSize &pixelGridSize);
        void setBlurRadius(int blurRadius);
        void setScanSize(const QSize &scanSize);
        void resetHaarFile();
        void resetMarkerType();
        void resetMarkerColor();
        void resetMarkerWidth();
        void resetMarkerStyle();
        void resetMarkerImage();
        void resetPixelGridSize();
        void resetBlurRadius();
        void resetScanSize();
        QbPacket iStream(const QbPacket &packet);
};

#endif // FACEDETECTELEMENT_H
