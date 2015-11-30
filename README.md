# kite-detector

OpenCV object detector trained to recognize kites.  The detector was trained on 7-14 M LEI kites flying over water or snow.

A small example program is provided which demonstrates how to use the classifier (see src/kite_classifier.cpp) .  The example program opens all images in a directory, places a red bounding box over all 
detected kites, and then dislpays each image with bounding boxes.

![Kites with red bounding boxes](http://beavercreekconsulting.com/img/kite-detector.png) 


## Installing

Install [OpenCV](http://docs.opencv.org/3.0.0/df/d65/tutorial_table_of_content_introduction.html) first.  Then:

    mkdir build
    cd build
    cmake ..
    make


## Running

    build/src/kite_detector classifier/cascade.xml <path-to-image-dir>			