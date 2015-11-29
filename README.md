# kite-detector
OpenCV object detector trained to recognize kites.  The detctor was trained on 7-14 M LEI kites flying over water or snow.


# installing
mkdir build
cd build
cmake ..
make


# running
build/src/kite_detector classifier/cascade.xml <path-to-image-dir>
