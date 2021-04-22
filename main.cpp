#include <iostream>
#include <unistd.h>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(){
	VideoCapture cap("bad_apple.mp4");
	ofstream f("bad_apple.txt");

	while(1){
		Mat frame;
		bool read = cap.read(frame);

		if(frame.empty()){
			break;
		}


		Mat resized;
		resize(frame, resized, Size(frame.cols * 0.1, frame.rows * 0.05));

		Mat grayscale;
		cvtColor(resized, grayscale, COLOR_RGB2GRAY);

		int rows = grayscale.rows;
		int cols = grayscale.cols;

		for(int i=0; i<rows; i++){
			string temp;
			for(int j=0; j<cols; j++){
				if(100 > grayscale.at<unsigned char>(i, j)){
					temp += ".";
				}else{
					temp += "#";
				}
			}
			temp += "\n";
			f << temp;
		}
	}
	cap.release();
	f.close();

	string line;
	int counter = 0;
	ifstream pf("bad_apple.txt");

	while(getline(pf, line)){
		cout << line << endl;
		counter++;
		if(counter >= 18){
			usleep(33333);
			counter = 0;
		}
	}
}
