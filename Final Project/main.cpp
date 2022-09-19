#include<opencv2\opencv.hpp>
#include<iostream>
#include"Structure_propagation.h"
#include"Texture_Propagation.h"
#include"Photometric_Correction.h"
#include"param.h"
#include<math.h>
using namespace cv;
using namespace std;

int main() {
	Mat a = imread("test_data/cowimage2.png");
	Structure_propagation s(a);
	s.getMask();
	s.getCurves();
	s.getAnchors();
	s.drawAnchors();
	s.getNewStructure();
	Texture_Propagation tp(&s);
	tp.synthesize_texture();
	waitKey();
	destroyAllWindows();
}

