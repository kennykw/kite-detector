#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <dirent.h>


using namespace std;
using namespace cv;

void detectAndDisplay(Mat frame, CascadeClassifier classifier, string image_name);

void usage()
{
  cerr << endl;
  cerr <<  "Loads images for a directory, detects kites and displays the images with a" << endl;
  cerr <<  "red bounding box around detected kites." << endl;
  cerr <<  "Usage:" << endl;
  cerr <<  "kite_detector <classifer> <image-dir>" << endl;
}


int main(int argc, char* argv[])
{

  if(argc != 3) {usage(); exit(-1);}

  // load classifier
  CascadeClassifier classifier;
  if( !classifier.load( argv[1] ) ){ printf("Error loading cascade\n"); return -1; };
  cout << "Classifer loaded from " << argv[1] << endl << endl;

  // Open the image directory and read the images
  string dirname = argv[2];
  cout << "Opening directory " << dirname << endl;
  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir (dirname.c_str())) != NULL) {
    while ((ent = readdir (dir)) != NULL) {
      if((strcmp(".", ent->d_name) == 0) || (strcmp("..", ent->d_name) == 0)) {
	continue;
      }	
      string image_path = dirname + "/" + ent->d_name;
      cout << "Loading " << image_path << endl;

      Mat I = imread(image_path, IMREAD_COLOR);
      if(I.empty()) {
	cout << "The image " << image_path << " could not be read." << endl;
	continue;
      }

      detectAndDisplay(I, classifier, image_path);
      int c = waitKey();
      if( (char)c == 27 ) { break; }
    }
    closedir (dir);
  } else {
    /* could not open directory */
    perror ("Could not open dir ");
    return EXIT_FAILURE;
  }
}


void detectAndDisplay(Mat frame, CascadeClassifier classifier, string image_name)
{
  std::vector<Rect> faces;
  Mat frame_gray;
  cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
  equalizeHist( frame_gray, frame_gray );
  //-- Detect faces  
  cout << "Detecting..." << endl;
  classifier.detectMultiScale( frame_gray, faces, 1.2, 3, 0|CASCADE_SCALE_IMAGE, Size(50, 50), Size(500, 500));
  cout << "Detecting complete" << endl;
  for( size_t i = 0; i < faces.size(); i++ )
    {
      cout << "Rectangle " << faces[i] << endl;
      rectangle(frame, faces[i], Scalar(0, 0, 255), 1, CV_AA, 0);
    }
  //-- Show what you got
  namedWindow(image_name, WINDOW_NORMAL);
  imshow(image_name, frame );
}
