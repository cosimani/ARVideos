#include "camerafilter.h"
#include "camerarunnable.h"

QVideoFilterRunnable *CameraFilter::createFilterRunnable()
{
    return new CameraRunnable(this);
}



