import QtQuick 2.0

//Rectangle {
    MultiPointTouchArea {
        id: touch
        minimumTouchPoints: 2
        maximumTouchPoints: 2

        property var startPoint
        property var startScale
        property bool gestureDone: false
        property bool dragEnabled: true
        property int threshold: width / 12

        function dist(point1, point2) { return Math.sqrt(Math.pow(point1.x - point2.x, 2) + Math.pow(point1.y - point2.y, 2)) }
        function centerOf(point1, point2) { return Qt.point((point1.x + point2.x) / 2, (point1.y + point2.y) / 2) }

        signal zoomIn
        signal zoomOut
        signal dragLeft
        signal dragRight
        signal dragUp
        signal dragDown

        onPressed: {
            if (touchPoints.length === 2) {
                startPoint = centerOf(touchPoints[0], touchPoints[1])
                startScale = dist(touchPoints[0], touchPoints[1])
                gestureDone = false
            }
        }

        onTouchUpdated: {
            console.debug(touchPoints.length)
            if (touchPoints.length === 2 && !gestureDone) {
                var center = centerOf(touchPoints[0], touchPoints[1])
                var distance = dist(center, startPoint)
                var scale = dist(touchPoints[0], touchPoints[1])

                if      (scale - startScale > threshold) { zoomIn(); gestureDone = true }
                else if (scale - startScale < -threshold) { zoomOut(); gestureDone = true }
                else if (dragEnabled && distance > threshold) {
                    var distX = startPoint.x - center.x
                    var distY = startPoint.y - center.y
                    var xBigger = Math.abs(distX) >= Math.abs(distY)
                    if      (xBigger && distX >= 0) { dragLeft(); gestureDone = true }
                    else if (xBigger && distX < 0)  { dragRight(); gestureDone = true }
                    else if (distY >= 0)            { dragUp(); gestureDone = true }
                    else                            { dragDown(); gestureDone = true }
                }
            }
        }
    }

//}

