/* TicTacToe in OpenCV
*
* \File: TicTacToe.cpp
* \Author: Jared Gregor (jmg2586@rit.edu)
* \Date: May 2020
*
*/

//INCLUDES
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#include "TicTacToe.h"

using namespace cv;
using namespace std;

void mouseClick(int event, int x, int y, int flags, void* param) {
    Mat& img = *((Mat*)(param));
	if (event == EVENT_LBUTTONDOWN) {
        cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
		circle(img, Point(x, y), 100, Scalar(255, 0, 0), 1);
	}
	else if (event == EVENT_MBUTTONDOWN) {
		cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
		circle(img, Point(x, y), 100, Scalar(0, 255, 0), 5);
	}
	else if (event == EVENT_RBUTTONDOWN) {
		cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
		circle(img, Point(x, y), 100, Scalar(0, 0, 255), -1);
	}
}

int main(int argc, char** argv) {
	
	TicTacToe tictactoe;

	cout << tictactoe.xMoves() << endl;
	cout << tictactoe.oMoves() << endl;

	Mat board = Mat::zeros(900, 900, CV_8UC3);

	//display tic tac toe board
	namedWindow("TicTacToe", 1);

	setMouseCallback("TicTacToe", mouseClick, &board);

	while (true) {
		imshow("TicTacToe", board);
		auto k = waitKey(10);
		if (k == 27) {
			break;
		}
	}
	

	return EXIT_SUCCESS;
}
