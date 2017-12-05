#ifndef CAMERAFILTER
#define CAMERAFILTER

#include <QAbstractVideoFilter>
#include <QOpenGLTexture>

#include <QDebug>

class CameraFilter : public QAbstractVideoFilter
{
    Q_OBJECT

public:
    QVideoFilterRunnable * createFilterRunnable() Q_DECL_OVERRIDE;

};

#endif // CAMERAFILTER

