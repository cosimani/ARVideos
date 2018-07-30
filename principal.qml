import QtQuick 2.7
import QtMultimedia 5.8
import QtQuick.Controls 2.0
import QtWebView 1.0
import QtQuick.Window 2.3 // the 2.3 is necessary

import com.vayra.camera 1.0
import com.vayra.mp4 1.0
import com.vayra.rendering 1.0

Item  {
    id: item

//    scale: item.width / videoOutput.contentRect.width
    scale: 640/480

    property bool reproduciendo: false
    property bool reproduciendo_video2: false

    onReproduciendoChanged: {
        if ( reproduciendo == false )  {  mediaPlayer.pause();  }
        else  {  mediaPlayer.play();  }

        if ( reproduciendo_video2 == false )  {  mediaPlayer2.pause();  }
        else  {  mediaPlayer2.play();  }

    }

    rotation: 90


    TwoFingerArea {
            anchors.fill: parent

            enabled: true
            dragEnabled: true

            onZoomIn: console.debug("ZoomIn")
            onZoomOut:  console.debug("ZoomOut")
            onDragLeft: console.debug("DragLeft")
            onDragRight: console.debug("DragRight")
            onDragUp: console.debug("DragUp")
            onDragDown: console.debug("DragDown")
        }


//    MultiPointTouchArea {
//        property var drag: parent
//        property var offset: null

//        anchors.fill: parent
//        enabled: true
//        mouseEnabled: false

//        minimumTouchPoints: 1
//        maximumTouchPoints: 2

//        touchPoints: [ TouchPoint { id: point1 }, TouchPoint { id: point2 } ]

//        function dragMove( holder, point )  {
//            if ( point && drag )  {
//                var position = holder.mapFromItem( drag, point.x, point.y );
//                drag.x = position.x - offset.x;
//                drag.y = position.y - offset.y;
//            }
//        }

//        onPressed: {
//            console.log( "onTouchPressed", point1.x, point2.x );
//            for ( var touch in touchPoints )
//                console.log(" Nro. i =", touch );

//            var point = touchPoints[ 0 ];
//            offset = Qt.point( point.x, point.y );
//            dragMove( item, point );
//        }

//        onTouchUpdated: {
//            console.log( "onTouchUpdated", point1.x, point2.x );
//            for ( var touch in touchPoints )
//                console.log(" Nro. i =", touch );

//            var point = touchPoints[ 0 ];
//            dragMove( item, point );
//        }

//        onUpdated: {
//            for ( var touch in touchPoints )
//                console.log( "Multitouch updated touch", "i=", touch, "id=", touchPoints[ touch ].pointId,
//                             "at", touchPoints[ touch ].x, ",", touchPoints[ touch ].y, point1.x, point2.x )
//        }

//        onReleased: {
//            console.log( "onTouchReleased", point1.x, point2.x );
//            for ( var touch in touchPoints )
//                console.log(" Nro. i =", touch );

//            var point = touchPoints[ 0 ];
//            dragMove( item, point );
//        }
//    }






    MouseArea  {
        id: mouseArea

        anchors.fill: parent

//        onClicked: {


//            var screens = Qt.application.screens;
//            console.log("item " + item.width + " video " + videoOutput.width
//                        + " " + videoOutput.contentRect.width +
//                        " " + renderer.width + " " )
//            for (var i = 0; i < screens.length; ++i)
//                console.log("screen " + screens[i].name + " has geometry " +
//                            screens[i].virtualX + ", " + screens[i].virtualY + " " +
//                            screens[i].width + "x" + screens[i].height)




//            if ( camera.position == Camera.FrontFace )  {
//                camera.position = Camera.BackFace
//            }
//            else  {
//                camera.position = Camera.FrontFace
//            }
//        }
    }

    Camera  {
        id: camera

        captureMode: Camera.CaptureViewfinder

        viewfinder.resolution: Qt.size(640, 480)

//        position: Camera.FrontFace
        position: Camera.BackFace
    }

    VideoOutput  {
        id: videoOutput

        anchors.fill: parent

        fillMode: Image.PreserveAspectFit
//        fillMode: Image.Stretch  // Estira la imagen de la camara para ocupar todo videoOutput

        source: camera

        focus : visible
        filters: [cameraFilter]
//        orientation: 270
    }

    VideoOutput {
        id: mp4VideoOutput
        source: mediaPlayer

        visible: false

        MediaPlayer {
            id: mediaPlayer
//            autoPlay: true
            volume: 1.0
            loops: Audio.Infinite

//            source: "file:///storage/emulated/0/DCIM/Camera/20170913_100145.mp4"
//            source: "file:///storage/emulated/0/Download/rentasonline.mp4"
//            source: "assets:/videos/rentasonline.mp4"
            source: "assets:/videos/video1.mp4"
//            source: "file:///storage/emulated/0/Download/rentasautomotor.mp4"
        }

        filters: [mp4Filter]
    }

    VideoOutput {
        id: mp4VideoOutput2
        source: mediaPlayer2

        visible: false

        MediaPlayer {
            id: mediaPlayer2
            volume: 1.0
            loops: Audio.Infinite
            source: "assets:/videos/video1.mp4"
        }
        filters: [mp4Filter]
    }

    Renderer {
        id: renderer

        // Para que el render se haga justo donde esta la imagen de la camara
        x: videoOutput.contentRect.x
        y: videoOutput.contentRect.y
        width: videoOutput.contentRect.width
        height: videoOutput.contentRect.height
    }

    CameraFilter  {
        id: cameraFilter
    }

    Mp4Filter  {
        id: mp4Filter
    }


//    WebView {
//        id: webView
//        anchors.fill: parent
//        url : "https://www.youtube.com/embed/iUdNKZUvpzk"
//    }



}




