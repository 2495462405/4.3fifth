//
//  main.cpp
//  test
//
//  Created by 徐亦燊 on 2020/2/28.
//  Copyright © 2020 徐亦燊. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main(int argc, const char * argv[]) {
    
    
    

    Mat dstMat;
    Mat srcMat;
    Mat sMat;
    sMat = imread("/Users/xuyishen/Desktop/sa jiganyouhaximeiyouga/2020.4.3/5/lena_rot.jpg");
    cvtColor(sMat, srcMat, COLOR_RGB2GRAY);
    threshold(srcMat, srcMat, 0, 255, THRESH_OTSU);
    int height = srcMat.rows;
    int width = srcMat.cols;
    int y1;
    int y2;
    int x1;
    int x2 = 0;
    int i;
   for (i = 0; i < width-1; i++)
       {
           if (srcMat.at<uchar>(i, 0) == 255 && srcMat.at<uchar>(i + 1, 0) != 255)
           {
               y1 = i + 1;
           }
           if (srcMat.at<uchar>(i, width - 1) == 255 && srcMat.at<uchar>(i + 1, width - 1) != 255)
           {
               y2 = i + 1;
               
           }
       }
   
       for (i = 0; i < height-1; i++)
       {
           if (srcMat.at<uchar>(1, i) == 255 && srcMat.at<uchar>(1,i + 1) != 255)
           {
               x1 = i + 1;
           }
           if (srcMat.at<uchar>(height-1, i) == 255 && srcMat.at<uchar>(height-1, i+1) != 255)
           {
               x2 = i+1;
               break;
           }
       }
    Point2f pts1[]={
       
        Point2f(0,y1),
        Point2f(width-1,y2),
        Point2f(x1,0),
        Point2f(x2,height-1),
    };
    Point2f pts2[]={
        Point2f(0,height-1),
        Point2f(width-1,0),
        Point2f(0,0),
        Point2f(width-1,height-1),
           
          
       };
    const Mat perspective_matrix = getPerspectiveTransform(pts1,pts2);
    warpPerspective(sMat,dstMat,perspective_matrix,srcMat.size(), INTER_CUBIC);
        imshow("src",sMat);
        imshow("dst",dstMat);
        
        waitKey(0);
        
    
    }
