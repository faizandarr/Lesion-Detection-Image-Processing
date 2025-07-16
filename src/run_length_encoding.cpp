#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include<ctime>
using namespace std;
using namespace cv;
struct node
{
    int value;
    node* address;
    node(int val)
    {
        value = val;
        address = NULL;
    }
};
    void insert(node*& haha, int val)
    {
        node* n = new node(val);

        if (haha == NULL)
        {
            haha = n;
            return;
        }
        node* temp = haha;
        while (temp->address != NULL)
        {
            temp = temp->address;
        }
        temp->address = n;
    }
    void print(node* haha)
    {
        while (haha != NULL)
        {
            cout << haha->value << "  ";
            if (haha->value == -1)
            {
                cout << endl;
            }
            haha = haha->address;
            
        }
    }
    void insertfirst(node*& haha, int value)
    {
        node* n = new node(value);
        n->address = haha;
        haha = n;
    }


int main()
{
    
    cv::Mat img = cv::imread("D:\\University\\Semester 3\\Data Structure\\Assignments\\Assignment 1\\Material\\Segmented Outputs\\mIMD144.bmp");
    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    cv::imshow("First OpenCV Application", img);
    cv::moveWindow("First OpenCV Application", 0, 45);
    cv::waitKey(0);
    cv::destroyAllWindows();
    int row = img.rows;
    int col = img.cols;
    float** image = new float* [row];
    for (int i = 0; i < row; i++)
    {
        image[i] = new float[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            image[i][j]=img.at<Vec3b>(i, j)[0];
        }
    }
    int temp;
    node* n=NULL;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp = image[i][j];
            if (temp != 0)
            {
                if (image[i][j-1] == 0 && image[i][j + 1] == 0)
                {
                    insert(n, j);
                    insert(n, j);
                }
                if (image[i][j - 1] == 255 && image[i][j + 1] == 0)
                {
                    insert(n, j);
                }
                if (image[i][j - 1] == 0 && image[i][j + 1] == 255)
                {
                    insert(n, j);
                }
            }
        }
        insert(n, -1);
    }
    print(n);
    return 0;
}
