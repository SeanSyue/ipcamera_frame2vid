#include "stdafx.h"
#include "opencv2/opencv.hpp"
#include <stdio.h>


using namespace cv;

int main()
{
	VideoCapture cap1;
	VideoCapture cap2;
	if (!cap1.open("http://avlabadmin:avlab32343738@140.118.45.30/img/video.mjpeg")) // rtsp://avlabadmin:avlab32343738@140.118.199.217:555/img/video.sav
	{
		std::cout << "Error Opening Video Stream1" << std::endl;
	};

	VideoWriter writeVideo("result17.avi", CV_FOURCC('D', 'I', 'V', 'X'), 30, cvSize(1280, 720), 1);

	Mat frame1;
	Mat frame2;
	int frameCounter = 0;
	int mins_to_record = 1;
	while (frameCounter < mins_to_record * 120 * 30) {

		cap1 >> frame1;

		if (!frame1.data) break;

		imshow("video1", frame1);

		writeVideo.write(frame1);
		frameCounter++;
		printf("%d\n", frameCounter);
		if (waitKey(33) >= 0) break;
	}

	system("pause");
	return 0;
}