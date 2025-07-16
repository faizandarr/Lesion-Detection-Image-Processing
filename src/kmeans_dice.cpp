#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include<ctime>
#include <string>
using namespace std;
using namespace cv;


int main()
{
    const std::string RAW_IMAGE_PATH = "data/raw/IMD091.bmp"; // Set your image filename here
    const std::string GROUND_TRUTH_PATH = "data/ground_truth/IMD091_lesion.bmp"; // Set your mask filename here
    cv::Mat img = cv::imread(RAW_IMAGE_PATH);
    cv::Mat img2 = cv::imread(GROUND_TRUTH_PATH);
    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    cv::imshow("First OpenCV Application", img);
    cv::moveWindow("First OpenCV Application", 0, 45);
    cv::waitKey(0);
    cv::destroyAllWindows();
    int row = img.rows;
    int col = img.cols;
    float** image = new float*[row];
    for (int i = 0; i < row; i++)
    {
        image[i] = new float[col];
    }
    float** groundimage = new float* [row];
    for (int i = 0; i < row; i++)
    {
        groundimage[i] = new float[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            groundimage[i][j] = img2.at<Vec3b>(i, j)[0];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            image[i][j] = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3;
        }
    }
    ////////////////////////////////////////////////////////////////
    srand(time(0));
    int c1, c2;
    int diff = 0, diff2 = 0;
    int average = 0, average2 = 0;
    int** distance;
    int count = 0, count2 = 0, sum1 = 0, sum2 = 0;
    distance = new int* [row];
    for (int i = 0; i < row; i++)
    {
        distance[i] = new int[col];
    }
    c1 = image[rand() % row][rand() % col];
    c2 = image[rand() % row][rand() % col];
    if (c1 == c2)
    {
        c2 = image[rand() % row][rand() % col];
    }
    //c1 = 2;
    //c2 = 1;
    cout << "intial value of centriods " << c1 << "  " << c2 << endl;
    bool n = true;
    while (n == true)
    {

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                diff = c1 - image[i][j];
                diff2 = c2 - image[i][j];
                if (diff < 0 || diff2 < 0)
                {
                    if (diff < 0)
                    {
                        diff = diff * (-1);
                    }
                    if (diff2 < 0)
                    {
                        diff2 = diff2 * (-1);
                    }
                }
                if (diff > diff2)
                {
                    distance[i][j] = 255;
                }
                else
                {
                    distance[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (distance[i][j] == 0)
                {
                    sum1 = sum1 + image[i][j];
                    count++;
                }
                if (distance[i][j] == 255)
                {
                    sum2 = sum2 + image[i][j];
                    count2++;
                }
            }
        }
        average = sum1 / count;
        average2 = sum2 / count2;

        if (average != c1 || average2 != c2)
        {
            c1 = average;
            c2 = average2;
            count = 0;
            count2 = 0;
            average = 0;
            average2 = 0;
            sum1 = 0;
            sum2 = 0;
            diff = 0;
            diff2 = 0;
           // cout << c1 << " the not running average " << c2 << endl;
        }
        else
        {
            //cout << c1 << " the final average " << c2 << endl;
            n = false;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    image[i][j] = distance[i][j];
                }

            }
        }
        //cout << c1 << " average " << c2 << endl;
        
        //cout << "\n\n";

    }
    //cout << "\n";
    /*for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << distance[i][j] << "\t";
        }
        cout << endl;
    }*/
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (image[i][j] == 255)
            {
                img.at<Vec3b>(i, j)[0] = 0;
                img.at<Vec3b>(i, j)[1] = 0;
                img.at<Vec3b>(i, j)[2] = 0;
            }
            if (image[i][j] == 0)
            {
                img.at<Vec3b>(i, j)[0] = 255;
                img.at<Vec3b>(i, j)[1] = 255;
                img.at<Vec3b>(i, j)[2] = 255;
            }
        }

    }
    /*for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            img.at<Vec3b>(i,j)[0]=distance[i][j];
            img.at<Vec3b>(i,j)[1] = distance[i][j];
            img.at<Vec3b>(i,j)[2] = distance[i][j];
        }
        
    }*/
    double tp=0, fp=0,fn=0,dc=0,tp2=0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (groundimage[i][j] == 255 && image[i][j] == 255)
            {
                tp++;
            }
            if (groundimage[i][j] == 255 && image[i][j] == 0)
            {
                fp++;
            }
            if (groundimage[i][j] == 0 && image[i][j] == 255)
            {
                fn++;
            }
        }
    }
    cout << "fp " << fp << "\t" << "fn " << fn << "\t" << "tp " << tp << endl;
    tp2 = tp * 2;
    cout << "Dice Cofficent: " << tp2/(fp + tp2+ fn);
    /////////////////////////////////////////////////////////////////
    cv::imshow("Final OpenCV Application", img);
    cv::moveWindow("First OpenCV Application", 0, 45);
    cv::waitKey(0);
    cv::imshow("Segmented OpenCV Application", img2);
    cv::moveWindow("First OpenCV Application", 0, 45);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}


