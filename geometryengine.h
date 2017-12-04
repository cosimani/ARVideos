/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef GEOMETRYENGINE_H
#define GEOMETRYENGINE_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class GeometryEngine : protected QOpenGLFunctions
{
public:
    GeometryEngine();
    virtual ~GeometryEngine();


//    genera la geometria de un cubo donde se dibujara la textura
    void drawCubeGeometry( QOpenGLShaderProgram *program );

    void drawCameraGeometry( QOpenGLShaderProgram *program );
//    genera la geometria de la cara de un cubo sobre la que se dibujara la textura
    void drawSheetGeometry(QOpenGLShaderProgram *program);

    void drawHojaGeometry(QOpenGLShaderProgram *program);

    void drawVideoGeometry(QOpenGLShaderProgram *program);


    void drawVideoTarjetaGeometry(QOpenGLShaderProgram *program);
private:
    void initCubeGeometry();
    void initCameraGeometry();
    void initSheetGeometry();
    void initHojaGeometry();
    void initVideoGeometry();
    void initVideoTarjetaGeometry();

    QOpenGLBuffer arrayCubeBuf;
    QOpenGLBuffer indexCubeBuf;

    QOpenGLBuffer arrayHojaBuf;
    QOpenGLBuffer indexHojaBuf;

    QOpenGLBuffer arrayCameraBuf;
    QOpenGLBuffer indexCameraBuf;

    QOpenGLBuffer arraySheetBuf;
    QOpenGLBuffer indexSheetBuf;

    QOpenGLBuffer arrayVideoBuf;
    QOpenGLBuffer indexVideoBuf;

    QOpenGLBuffer arrayVideoTarjetaBuf;
    QOpenGLBuffer indexVideoTarjetaBuf;



};

#endif // GEOMETRYENGINE_H
