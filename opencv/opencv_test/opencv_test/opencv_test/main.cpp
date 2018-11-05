#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/video.hpp>
using namespace cv;
int main()
{
#if 0
	Mat img = imread("pic.png");
	cvNamedWindow("游戏原图");
	imshow("游戏原图",img);
	waitKey(6000);
	system("pause");
#else
	VideoCapture capture(1);
	Mat edegs;
	while(1)
	{
		Mat Frame;
		capture>>Frame;
		cvtColor(Frame,edegs,CV_BGR2GRAY);
		blur(edegs,edegs,Size(7,7));
		Canny(edegs,edegs,0,30,3);
		imshow("视频",edegs);
		if(waitKey(30)>=0)
			break;
		//waitKey(30);
	}
#endif
	return 0;
}