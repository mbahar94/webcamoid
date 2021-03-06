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

#ifndef QBPLUGIN_H
#define QBPLUGIN_H

#include <QtPlugin>

class QbPlugin
{
    public:
        virtual ~QbPlugin() {}

        virtual QObject *create(const QString &name, const QString &spec) = 0;
        virtual QStringList keys() const = 0;
};

Q_DECLARE_INTERFACE(QbPlugin, "Qb.Plugin")

#endif // QBPLUGIN_H
