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

#include "geometryengine.h"

#include <QVector2D>
#include <QVector3D>

struct VertexData
{
    QVector3D position;
    QVector2D texCoord;
};

GeometryEngine::GeometryEngine() : indexCubeBuf(QOpenGLBuffer::IndexBuffer),
                                   indexSheetBuf(QOpenGLBuffer::IndexBuffer),
                                   indexHojaBuf(QOpenGLBuffer::IndexBuffer),
                                   indexVideoBuf(QOpenGLBuffer::IndexBuffer),
                                   indexVideoTarjetaBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();

    // Generate 2 VBOs
    arrayCubeBuf.create();
    indexCubeBuf.create();

    // Generate 2 VBOs
    arrayCameraBuf.create();
    indexCameraBuf.create();

    arraySheetBuf.create();
    indexSheetBuf.create();

    arrayHojaBuf.create();
    indexHojaBuf.create();

    arrayVideoBuf.create();
    indexVideoBuf.create();

    arrayVideoTarjetaBuf.create();
    indexVideoTarjetaBuf.create();


    // Initializes cube geometry and transfers it to VBOs
    initCubeGeometry();

//    initCameraGeometry();

    initSheetGeometry();

    initHojaGeometry();

    initVideoGeometry();

    initVideoTarjetaGeometry();
}

GeometryEngine::~GeometryEngine()
{
    arrayCubeBuf.destroy();
    indexCubeBuf.destroy();

    arrayCameraBuf.destroy();
    indexCameraBuf.destroy();

    arraySheetBuf.destroy();
    indexSheetBuf.destroy();

    arrayHojaBuf.destroy();
    indexHojaBuf.destroy();

    arrayVideoBuf.destroy();
    indexVideoBuf.destroy();

    arrayVideoTarjetaBuf.destroy();
    indexVideoTarjetaBuf.destroy();

}

void GeometryEngine::initHojaGeometry()
{
    GLfloat unidad = 1.0f;

    // Se dibuja bien pero pata para arriba
//    VertexData vertices[] = {
//        // Vertex data for face 0
//        { QVector3D( -unidad, -unidad, 0 ), QVector2D( 0.0f, 0.0f ) },  // v0
//        { QVector3D(  unidad, -unidad, 0 ), QVector2D( 1.0f, 0.0f ) },  // v1
//        { QVector3D( -unidad,  unidad, 0 ), QVector2D( 0.0f, 1.0f ) },  // v2
//        { QVector3D(  unidad,  unidad, 0 ), QVector2D( 1.0f, 1.0f ) }   // v3
//    };

//    VertexData vertices[] = {
//        // Vertex data for face 0
//        { QVector3D( -unidad * 2, -unidad * 4, 0 ), QVector2D( 0.0f, 1.0f ) },  // v0
//        { QVector3D(  unidad * 12 , -unidad *4, 0 ), QVector2D( 1.0f, 1.0f ) },  // v1
//        { QVector3D( -unidad * 2,  unidad * 17, 0 ), QVector2D( 0.0f, 0.0f ) },  // v2
//        { QVector3D(  unidad * 12 ,  unidad *17, 0 ), QVector2D( 1.0f, 0.0f ) }   // v3
//    };

    VertexData vertices[] = {
        // Vertex data for face 0
        { QVector3D( -unidad * 2, -unidad * 4, 0 ), QVector2D( 1.0f, 1.0f ) },  // v0
        { QVector3D(  unidad * 12 , -unidad *4, 0 ), QVector2D( 0.0f, 1.0f ) },  // v1
        { QVector3D( -unidad * 2,  unidad * 17, 0 ), QVector2D( 1.0f, 0.0f ) },  // v2
        { QVector3D(  unidad * 12 ,  unidad *17, 0 ), QVector2D( 0.0f, 0.0f ) }   // v3
    };


    GLushort indices[] = { 0,  1,  2,  3,  3 };

    // Transfer vertex data to VBO 0
    arrayHojaBuf.bind();
    arrayHojaBuf.allocate( vertices, 4 * sizeof( VertexData ) );

    // Transfer index data to VBO 1
    indexHojaBuf.bind();
    indexHojaBuf.allocate( indices, 5 * sizeof( GLushort ) );



}

void GeometryEngine::initVideoGeometry()
{
    GLfloat unidad = 1.0f;
    GLfloat distanciaSobreElPapel = 0.01f;

    VertexData vertices[] = {
        // Vertex data for face 0
        { QVector3D( -unidad, -unidad * -1, distanciaSobreElPapel ), QVector2D( 1.0f, 1.0f ) },
        { QVector3D(  unidad * 11 , -unidad * -1, distanciaSobreElPapel ), QVector2D( 0.0f, 1.0f ) },
        { QVector3D( -unidad,  unidad * 8, distanciaSobreElPapel ), QVector2D( 1.0f, 0.0f ) },
        { QVector3D(  unidad * 11 ,  unidad * 8, distanciaSobreElPapel ), QVector2D( 0.0f, 0.0f ) }
    };

    GLushort indices[] = { 0,  1,  2,  3,  3 };

    // Transfer vertex data to VBO 0
    arrayVideoBuf.bind();
    arrayVideoBuf.allocate( vertices, 4 * sizeof( VertexData ) );

    // Transfer index data to VBO 1
    indexVideoBuf.bind();
    indexVideoBuf.allocate( indices, 5 * sizeof( GLushort ) );



}


void GeometryEngine::initVideoTarjetaGeometry()
{
    GLfloat unidad = 1.0f;
    GLfloat distanciaSobreElPapel = 0.01f;

    VertexData vertices[] = {
        // lateral derecho, abajo, z=0
        { QVector3D( -unidad * 1.0, -unidad * 4, distanciaSobreElPapel ), QVector2D( 1.0f, 1.0f ) },
        // lateral izquierdo, abajo, z=0
        { QVector3D(  unidad * 3.2 , -unidad * 4, distanciaSobreElPapel ), QVector2D( 0.0f, 1.0f ) },

        // lateral derecho, arriba, z=0
        { QVector3D( -unidad * 1.0,  unidad * -1.0, distanciaSobreElPapel ), QVector2D( 1.0f, 0.0f ) },
        // lateral izquierdo, arriba, z=0
        { QVector3D(  unidad * 3.2 ,  unidad * -1.0, distanciaSobreElPapel ), QVector2D( 0.0f, 0.0f ) }
    };

    GLushort indices[] = { 0,  1,  2,  3,  3 };

    // Transfer vertex data to VBO 0
    arrayVideoTarjetaBuf.bind();
    arrayVideoTarjetaBuf.allocate( vertices, 4 * sizeof( VertexData ) );

    // Transfer index data to VBO 1
    indexVideoTarjetaBuf.bind();
    indexVideoTarjetaBuf.allocate( indices, 5 * sizeof( GLushort ) );



}

void GeometryEngine::initCubeGeometry()
{
    GLfloat unidad = 1.0f;

    // For cube we would need only 8 vertices but we have to
    // duplicate vertex for each face because texture coordinate
    // is different.
    VertexData vertices[] = {
        // Vertex data for face 0
        { QVector3D( -unidad, -unidad, 2*unidad ), QVector2D( 0.0f, 0.0f ) },  // v0
        { QVector3D(  unidad, -unidad, 2*unidad ), QVector2D( 1.0f, 0.0f ) },  // v1
        { QVector3D( -unidad,  unidad, 2*unidad ), QVector2D( 0.0f, 1.0f ) },  // v2
        { QVector3D(  unidad,  unidad, 2*unidad ), QVector2D( 1.0f, 1.0f ) },  // v3

        // Vertex data for face 1
        { QVector3D( unidad, -unidad,  2*unidad ), QVector2D( 0.0f, 0.0f ) },  // v4
        { QVector3D( unidad, -unidad, -0        ), QVector2D( 1.0f, 0.0f ) },  // v5
        { QVector3D( unidad,  unidad,  2*unidad ), QVector2D( 0.0f, 1.0f ) },  // v6
        { QVector3D( unidad,  unidad, -0        ), QVector2D( 1.0f, 1.0f ) },  // v7

        // Vertex data for face 2
        { QVector3D( unidad, -unidad, -0        ), QVector2D( 0.0f, 0.0f ) },  // v8
        { QVector3D(-unidad, -unidad, -0        ), QVector2D( 1.0f, 0.0f ) },  // v9
        { QVector3D( unidad,  unidad, -0        ), QVector2D( 0.0f, 1.0f ) },  // v10
        { QVector3D(-unidad,  unidad, -0        ), QVector2D( 1.0f, 1.0f ) },  // v11

        // Vertex data for face 3
        { QVector3D(-unidad, -unidad, -0        ), QVector2D( 0.0f, 0.0f ) },  // v12
        { QVector3D(-unidad, -unidad,  2*unidad ), QVector2D( 1.0f, 0.0f ) },  // v13
        { QVector3D(-unidad,  unidad, -0        ), QVector2D( 0.0f, 1.0f ) },  // v14
        { QVector3D(-unidad,  unidad,  2*unidad ), QVector2D( 1.0f, 1.0f ) },  // v15

        // Vertex data for face 4
        { QVector3D(-unidad, -unidad, -0        ), QVector2D( 0.0f, 0.0f ) },  // v16
        { QVector3D( unidad, -unidad, -0        ), QVector2D( 1.0f, 0.0f ) },  // v17
        { QVector3D(-unidad, -unidad,  2*unidad ), QVector2D( 0.0f, 1.0f ) },  // v18
        { QVector3D( unidad, -unidad,  2*unidad ), QVector2D( 1.0f, 1.0f ) },  // v19

        // Vertex data for face 5
        { QVector3D(-unidad,  unidad,  2*unidad ), QVector2D( 0.0f, 0.0f ) },  // v20
        { QVector3D( unidad,  unidad,  2*unidad ), QVector2D( 1.0f, 0.0f ) },  // v21
        { QVector3D(-unidad,  unidad, -0        ), QVector2D( 0.0f, 1.0f ) },  // v22
        { QVector3D( unidad,  unidad, -0        ), QVector2D( 1.0f, 1.0f ) }   // v23
    };

    // Indices for drawing cube faces using triangle strips.
    // Triangle strips can be connected by duplicating indices
    // between the strips. If connecting strips have opposite
    // vertex order then last index of the first strip and first
    // index of the second strip needs to be duplicated. If
    // connecting strips have same vertex order then only last
    // index of the first strip needs to be duplicated.
    GLushort indices[] = {
         0,  1,  2,  3,  3,     // Face 0 - triangle strip ( v0,  v1,  v2,  v3)
         4,  4,  5,  6,  7,  7, // Face 1 - triangle strip ( v4,  v5,  v6,  v7)
         8,  8,  9, 10, 11, 11, // Face 2 - triangle strip ( v8,  v9, v10, v11)
        12, 12, 13, 14, 15, 15, // Face 3 - triangle strip (v12, v13, v14, v15)
        16, 16, 17, 18, 19, 19, // Face 4 - triangle strip (v16, v17, v18, v19)
        20, 20, 21, 22, 23      // Face 5 - triangle strip (v20, v21, v22, v23)
    };

    // Transfer vertex data to VBO 0
    arrayCubeBuf.bind();
    arrayCubeBuf.allocate( vertices, 24 * sizeof( VertexData ) );

    // Transfer index data to VBO 1
    indexCubeBuf.bind();
    indexCubeBuf.allocate( indices, 34 * sizeof( GLushort ) );
}

void GeometryEngine::initCameraGeometry()
{
    GLfloat unidad = 1.0f;

    // For cube we would need only 8 vertices but we have to
    // duplicate vertex for each face because texture coordinate
    // is different.
    VertexData vertices[] = {
        // Vertex data for face 0
        { QVector3D( -unidad, -unidad, 0 ), QVector2D( 0.0f, 0.0f ) },  // v0
        { QVector3D(  unidad, -unidad, 0 ), QVector2D( 1.0f, 0.0f ) },  // v1
        { QVector3D( -unidad,  unidad, 0 ), QVector2D( 0.0f, 1.0f ) },  // v2
        { QVector3D(  unidad,  unidad, 0 ), QVector2D( 1.0f, 1.0f ) }   // v3
    };

    // Indices for drawing cube faces using triangle strips.
    // Triangle strips can be connected by duplicating indices
    // between the strips. If connecting strips have opposite
    // vertex order then last index of the first strip and first
    // index of the second strip needs to be duplicated. If
    // connecting strips have same vertex order then only last
    // index of the first strip needs to be duplicated.
    GLushort indices[] = {
         0,  1,  2,  3,  3     // Face 0 - triangle strip ( v0,  v1,  v2,  v3)
    };

    // Transfer vertex data to VBO 0
    arrayCameraBuf.bind();
    arrayCameraBuf.allocate( vertices, 4 * sizeof( VertexData ) );

    // Transfer index data to VBO 1
    indexCameraBuf.bind();
    indexCameraBuf.allocate( indices, 5 * sizeof( GLushort ) );
}


void GeometryEngine::initSheetGeometry()
{
    GLfloat unidad = 1.0f;

    VertexData vertices[] = {
        // Para la camera BackFace los puntos (x, y, z) corresponden a:

        // lateral derecho, abajo, z=0
        { QVector3D( -unidad * 1.2, -unidad * 1.2, 0 ), QVector2D( 1.0f, 1.0f ) },
        // lateral izquierdo, abajo, z=0
        { QVector3D(  unidad * 3.4 , -unidad * 1.2, 0 ), QVector2D( 0.0f, 1.0f ) },

        // lateral derecho, arriba, z=0
        { QVector3D( -unidad * 1.2,  unidad * 1.9, 0 ), QVector2D( 1.0f, 0.0f ) },
        // lateral izquierdo, arriba, z=0
        { QVector3D(  unidad * 3.4 ,  unidad * 1.9, 0 ), QVector2D( 0.0f, 0.0f ) }
    };

    GLushort indices[] = { 0,  1,  2,  3,  3 };

    // Transfer vertex data to VBO 0
    arraySheetBuf.bind();
    arraySheetBuf.allocate( vertices, 4 * sizeof( VertexData ) );

    // Transfer index data to VBO 1
    indexSheetBuf.bind();
    indexSheetBuf.allocate( indices, 5 * sizeof( GLushort ) );
}

void GeometryEngine::drawCubeGeometry( QOpenGLShaderProgram *program )
{
    // Tell OpenGL which VBOs to use
    arrayCubeBuf.bind();
    indexCubeBuf.bind();

    // Offset for position
    quintptr offset = 0;

    // Tell OpenGL programmable pipeline how to locate vertex position data
//    int vertexLocation = program->attributeLocation("a_position");
    int vertexLocation = program->attributeLocation( "vertex" );

    program->enableAttributeArray( vertexLocation );
    program->setAttributeBuffer( vertexLocation, GL_FLOAT, offset, 3, sizeof( VertexData ) );

    // Offset for texture coordinate
    offset += sizeof( QVector3D );

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
//    int texcoordLocation = program->attributeLocation("a_texcoord");
    int texcoordLocation = program->attributeLocation( "texCoord" );

    program->enableAttributeArray( texcoordLocation );
    program->setAttributeBuffer( texcoordLocation, GL_FLOAT, offset, 2, sizeof( VertexData ) );

    // Draw cube geometry using indices from VBO 1
    glDrawElements( GL_TRIANGLE_STRIP, 34, GL_UNSIGNED_SHORT, 0 );
}

void GeometryEngine::drawHojaGeometry( QOpenGLShaderProgram *program )
{
    arrayHojaBuf.bind();
    indexHojaBuf.bind();

    quintptr offset = 0;

    int vertexLocation = program->attributeLocation( "vertex" );

    program->enableAttributeArray( vertexLocation );
    program->setAttributeBuffer( vertexLocation, GL_FLOAT, offset, 3, sizeof( VertexData ) );

    offset += sizeof( QVector3D );

    int texcoordLocation = program->attributeLocation( "texCoord" );

    program->enableAttributeArray( texcoordLocation );
    program->setAttributeBuffer( texcoordLocation, GL_FLOAT, offset, 2, sizeof( VertexData ) );

//    glDrawElements( GL_TRIANGLE_STRIP, 34, GL_UNSIGNED_SHORT, 0 );
    glDrawElements( GL_TRIANGLE_STRIP, 5, GL_UNSIGNED_SHORT, 0 );

}

void GeometryEngine::drawVideoGeometry( QOpenGLShaderProgram *program )
{
    arrayVideoBuf.bind();
    indexVideoBuf.bind();

    quintptr offset = 0;

    int vertexLocation = program->attributeLocation( "vertex" );

    program->enableAttributeArray( vertexLocation );
    program->setAttributeBuffer( vertexLocation, GL_FLOAT, offset, 3, sizeof( VertexData ) );

    offset += sizeof( QVector3D );

    int texcoordLocation = program->attributeLocation( "texCoord" );

    program->enableAttributeArray( texcoordLocation );
    program->setAttributeBuffer( texcoordLocation, GL_FLOAT, offset, 2, sizeof( VertexData ) );

//    glDrawElements( GL_TRIANGLE_STRIP, 34, GL_UNSIGNED_SHORT, 0 );
    glDrawElements( GL_TRIANGLE_STRIP, 5, GL_UNSIGNED_SHORT, 0 );

}

void GeometryEngine::drawVideoTarjetaGeometry( QOpenGLShaderProgram *program )
{
    arrayVideoTarjetaBuf.bind();
    indexVideoTarjetaBuf.bind();

    quintptr offset = 0;

    int vertexLocation = program->attributeLocation( "vertex" );

    program->enableAttributeArray( vertexLocation );
    program->setAttributeBuffer( vertexLocation, GL_FLOAT, offset, 3, sizeof( VertexData ) );

    offset += sizeof( QVector3D );

    int texcoordLocation = program->attributeLocation( "texCoord" );

    program->enableAttributeArray( texcoordLocation );
    program->setAttributeBuffer( texcoordLocation, GL_FLOAT, offset, 2, sizeof( VertexData ) );

//    glDrawElements( GL_TRIANGLE_STRIP, 34, GL_UNSIGNED_SHORT, 0 );
    glDrawElements( GL_TRIANGLE_STRIP, 5, GL_UNSIGNED_SHORT, 0 );

}

void GeometryEngine::drawCameraGeometry( QOpenGLShaderProgram *program )
{
    // Tell OpenGL which VBOs to use
    arrayCameraBuf.bind();
    indexCameraBuf.bind();

    // Offset for position
    quintptr offset = 0;

    // Tell OpenGL programmable pipeline how to locate vertex position data
//    int vertexLocation = program->attributeLocation("a_position");
    int vertexLocation = program->attributeLocation( "vertex" );

    program->enableAttributeArray( vertexLocation );
    program->setAttributeBuffer( vertexLocation, GL_FLOAT, offset, 3, sizeof( VertexData ) );

    // Offset for texture coordinate
    offset += sizeof( QVector3D );

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
//    int texcoordLocation = program->attributeLocation("a_texcoord");
    int texcoordLocation = program->attributeLocation( "texCoord" );

    program->enableAttributeArray( texcoordLocation );
    program->setAttributeBuffer( texcoordLocation, GL_FLOAT, offset, 2, sizeof( VertexData ) );

    // Draw cube geometry using indices from VBO 1
    glDrawElements( GL_TRIANGLE_STRIP, 34, GL_UNSIGNED_SHORT, 0 );
}

void GeometryEngine::drawSheetGeometry( QOpenGLShaderProgram *program )
{    
    arraySheetBuf.bind();
    indexSheetBuf.bind();

    quintptr offset = 0;

    int vertexLocation = program->attributeLocation( "vertex" );
    program->enableAttributeArray( vertexLocation );
    program->setAttributeBuffer( vertexLocation, GL_FLOAT, offset, 3, sizeof( VertexData ) );

    offset += sizeof( QVector3D );

    int texcoordLocation = program->attributeLocation( "texCoord" );
    program->enableAttributeArray( texcoordLocation );
    program->setAttributeBuffer( texcoordLocation, GL_FLOAT, offset, 2, sizeof( VertexData ) );

    glDrawElements( GL_TRIANGLE_STRIP, 5, GL_UNSIGNED_SHORT, 0 );
}

