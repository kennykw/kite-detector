# kite-detector

OpenCV object detector trained to recognize kites.  The detector was trained on 7-14 M LEI kites flying over water or snow.

There is a small example program which opens all images in a directory, places a red bounding box over all detetced kites, and then dislpays each image with bounding boxes.


![Kites with red bounding boxes](http://beavercreekconsulting.com/img/kite-detector.png) 

## Installing

Install OpenCV first.  Then:

    mkdir build
    cd build
    cmake ..
    make

## Running

    build/src/kite_detector classifier/cascade.xml <path-to-image-dir>			