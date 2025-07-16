#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include<ctime>
using namespace std;
using namespace cv;




//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////


int main()
{
    cv::Mat img = cv::imread("D:\\University\\Semester 3\\Data Structure\\Assignments\\Assignment 1\\Material\\Segmented Outputs\\mIMD002.bmp");
    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    cv::imshow("First OpenCV Application", img);
    cv::moveWindow("First OpenCV Application", 0, 45);
    cv::waitKey(0);
    cv::destroyAllWindows();
    int label = 1;
    
    int** image;
    int row = img.rows;
    int col = img.cols;
    image = new int* [row];
    for (int i = 0; i < row; i++)
    {
        image[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            image[i][j] = (img.at<Vec3b>(i, j)[0]+img.at<Vec3b>(i, j)[1]+img.at<Vec3b>(i, j)[2])/3;
        }
    }
    
    

    /////////////////////////////////////
    
    int nonzero=0;
    
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            nonzero = 0;
            if (image[i][j] != 0)
            {
                nonzero = 0;
                
                
                ////////////////////////////////////////////////non   zerooo/////////////////////////////
                if (image[i - 1][j - 1] != 0)
                {
                    nonzero++;
                }
                

                if (image[i - 1][j] != 0)
                {
                    nonzero++;
                }
                if (image[i][j - 1] != 0)
                {
                    nonzero++;
                }
                if (image[i - 1][j + 1] != 0)
                {
                    nonzero++;
                }
                if (nonzero == 0)
                {
                    image[i][j] = label;
                    label++;
                }
                if (nonzero == 1)
                {
                    if (i > 0 && j > 0)
                    {
                        if (image[i - 1][j - 1] != 0)
                        {
                            image[i][j] = image[i - 1][j - 1];
                        }
                        if (image[i - 1][j] != 0)
                        {
                            image[i][j] = image[i - 1][j];
                        }
                        if (image[i][j - 1] != 0)
                        {
                            image[i][j] = image[i][j - 1];
                        }
                        if (image[i - 1][j + 1] != 0)
                        {
                            image[i][j] = image[i - 1][j + 1];
                        }
                    }
                }
                if (nonzero == 2)
                {
                    if (image[i - 1][j - 1] != 0)
                    {
                        image[i][j] = image[i - 1][j - 1];
                        if (image[i - 1][j] != 0)
                        {
                                
                                if (image[i - 1][j] != image[i - 1][j - 1])
                                {
                                    int chng = image[i-1][j];
                                    for (int k = 0; k < row; k++)
                                    {
                                        for (int l = 0; l < col; l++)
                                        {
                                            if (image[k][l] == chng)
                                            {
                                                image[k][l] = image[i][j];
                                            }
                                        }
                                    }
                                }
                        }

                        if (image[i][j - 1] != 0)
                        {
                                
                                  image[i][j] = image[i - 1][j - 1];
                                if (image[i][j - 1] != image[i - 1][j - 1])
                                {
                                    int chng = image[i][j - 1];
                                    for (int k = 0; k < row; k++)
                                    {
                                        for (int l = 0; l < col; l++)
                                        {
                                            if (image[k][l] == chng)
                                            {
                                                image[k][l] = image[i][j];
                                            }
                                        }
                                    }
                                }
                        }


                            if (image[i - 1][j + 1] != 0)
                            {

                                image[i][j] = image[i - 1][j - 1];
                                if (image[i - 1][j + 1] != image[i - 1][j - 1])
                                {
                                   int chng = image[i - 1][j + 1];
                                    for (int k = 0; k < row; k++)
                                    {
                                        for (int l = 0; l < col; l++)
                                        {
                                            if (image[k][l] == chng)
                                            {
                                                image[k][l] = image[i][j];
                                            }
                                        }
                                    }
                                }
                            }
                    }
                    if (image[i - 1][j] != 0)
                    {
                        if (image[i][j - 1] != 0)
                            {
                                image[i][j] = image[i - 1][j];
                                if (image[i][j - 1] != image[i - 1][j])
                                {
                                    int chng = image[i][j - 1];
                                    for (int k = 0; k < row; k++)
                                    {
                                        for (int l = 0; l < col; l++)
                                        {
                                            if (image[k][l] == chng)
                                            {
                                                image[k][l] = image[i][j];
                                            }
                                        }
                                    }
                                }
                            }


                            if (image[i - 1][j + 1] != 0)
                            {
                                image[i][j] = image[i - 1][j];
                                if (image[i - 1][j + 1] != image[i - 1][j])
                                {
                                    int chng = image[i - 1][j + 1];
                                    for (int k = 0; k < row; k++)
                                    {
                                        for (int l = 0; l < col; l++)
                                        {
                                            if (image[k][l] == chng)
                                            {
                                                image[k][l] = image[i][j];
                                            }
                                        }
                                    }
                                }
                            }
                    }
                    if (image[i][j - 1] != 0)
                    {
                        if (image[i - 1][j + 1] != 0)
                            {
                                image[i][j] = image[i][j - 1];
                                if (image[i - 1][j + 1] != image[i][j - 1])
                                {
                                    int chng = image[i - 1][j + 1];
                                    for (int k = 0; k < row; k++)
                                    {
                                        for (int l = 0; l < col; l++)
                                        {
                                            if (image[k][l] == chng)
                                            {
                                                image[k][l] = image[i][j];

                                            }
                                        }
                                    }
                                }
                            }
                    }
                    
                }
                if (nonzero == 3)
                {
                    if (image[i - 1][j - 1] != 0 && image[i - 1][j] != 0 && image[i][j - 1] != 0)
                    {
                        image[i][j] = image[i - 1][j - 1];
                        if (image[i - 1][j - 1] != image[i - 1][j])
                        {
                            int chng = image[i - 1][j];
                            for (int k = 0; k < row; k++)
                            {
                                for (int l = 0; l < col; l++)
                                {
                                    if (image[k][l] == chng)
                                    {
                                        image[k][l] = image[i][j];
                                    }
                                }
                            }
                        }
                        if (image[i - 1][j - 1] != image[i][j - 1])
                        {
                            int chng = image[i][j - 1];
                            for (int k = 0; k < row; k++)
                            {
                                for (int l = 0; l < col; l++)
                                {
                                    if (image[k][l] == chng)
                                    {
                                        image[k][l] = image[i][j];
                                    }
                                }
                            }
                        }
                    }
                
                    if (image[i - 1][j] != 0 && image[i][j - 1] != 0 && image[i - 1][j + 1] != 0)
                    {
                        image[i][j] = image[i - 1][j];
                        if (image[i - 1][j] != image[i][j - 1])
                        {
                            int chng = image[i][j - 1];
                            for (int k = 0; k < row; k++)
                            {
                                for (int l = 0; l < col; l++)
                                {
                                    if (image[k][l] == chng)
                                    {
                                        image[k][l] = image[i][j];
                                    }
                                }
                            }
                        }
                        if (image[i - 1][j] != image[i - 1][j + 1])
                        {
                            int chng = image[i - 1][j + 1];
                            for (int k = 0; k < row; k++)
                            {
                                for (int l = 0; l < col; l++)
                                {
                                    if (image[k][l] == chng)
                                    {
                                        image[k][l] = image[i][j];
                                    }
                                }
                            }
                        }
                    }
                    if (image[i - 1][j - 1] != 0 && image[i][j - 1] != 0 && image[i - 1][j + 1] != 0)
                    {
                        image[i][j] = image[i - 1][j - 1];
                        if (image[i - 1][j - 1] != image[i][j - 1])
                        {
                            int chng = image[i][j - 1];
                            for (int k = 0; k < row; k++)
                            {
                                for (int l = 0; l < col; l++)
                                {
                                    if (image[k][l] == chng)
                                    {
                                        image[k][l] = image[i][j];
                                    }
                                }
                            }
                        }
                        if (image[i - 1][j - 1] != image[i - 1][j + 1])
                        {
                            int chng = image[i - 1][j + 1];
                            for (int k = 0; k < row; k++)
                            {
                                for (int l = 0; l < col; l++)
                                {
                                    if (image[k][l] == chng)
                                    {
                                        image[k][l] = image[i][j];
                                    }
                                }
                            }
                        }
                    }
                    if (image[i - 1][j - 1] != 0 && image[i - 1][j] != 0 && image[i - 1][j + 1] != 0)
                    {
                        image[i][j] = image[i - 1][j - 1];
                        if (image[i - 1][j - 1] != image[i - 1][j])
                        {
                            int chng = image[i - 1][j];
                            for (int k = 0; k < row; k++)
                            {
                                for (int l = 0; l < col; l++)
                                {
                                    if (image[k][l] == chng)
                                    {
                                        image[k][l] = image[i][j];
                                    }
                                }
                            }
                        }
                       
                        if (image[i - 1][j - 1] != image[i - 1][j + 1])
                        {
                            int chng = image[i - 1][j + 1];
                            for (int k = 0; k < row; k++)
                            {
                                for (int l = 0; l < col; l++)
                                {
                                    if (image[k][l] == chng)
                                    {
                                        image[k][l] = image[i][j];
                                    }
                                }
                            }
                        }
                    }
                }
                if (nonzero == 4)
                {
                    if (image[i - 1][j - 1] != 0 && image[i - 1][j] != 0 && image[i][j - 1] != 0 && image[i - 1][j + 1] != 0)
                    {
                            image[i][j] = image[i - 1][j - 1];
                            if (image[i - 1][j - 1] != image[i - 1][j])
                            {
                                int chng = image[i - 1][j];
                                for (int k = 0; k < row; k++)
                                {
                                    for (int l = 0; l < col; l++)
                                    {
                                        if (image[k][l] == chng)
                                        {
                                            image[k][l] = image[i][j];
                                        }
                                    }
                                }
                            }
                            if (image[i - 1][j - 1] != image[i][j - 1])
                            {
                                int chng = image[i][j - 1];
                                for (int k = 0; k < row; k++)
                                {
                                    for (int l = 0; l < col; l++)
                                    {
                                        if (image[k][l] == chng)
                                        {
                                            image[k][l] = image[i][j];
                                        }
                                    }
                                }
                            }
                            if (image[i - 1][j - 1] != image[i - 1][j + 1])
                            {
                                int chng = image[i - 1][j + 1];
                                for (int k = 0; k < row; k++)
                                {
                                    for (int l = 0; l < col; l++)
                                    {
                                        if (image[k][l] == chng)
                                        {
                                            image[k][l] = image[i][j];
                                        }
                                    }
                                }
                            }
                    }
                }
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


               
            }
            
        }
    }
    
    int* freq;
    freq = new int[label + 1];
    for (int i = 0; i < label + 1; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (image[i][j] != 0)
            {
                freq[int(image[i][j])]++;
            }
        }
    }
    int count;
    int max = 0;
    for (int i = 0; i < label + 1; i++)
    {
        if (freq[i] > max)
        {
            max = freq[i];
            count = i;
           // cout << " frequency: " << count << endl;
        }
    }
    
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (image[i][j] == count)
            {
                img.at<Vec3b>(i,j)[0]=255;
                img.at<Vec3b>(i, j)[1] = 255;
                img.at<Vec3b>(i, j)[2] = 255;
                image[i][j] = 255;
                
            }
            else
            {
                img.at<Vec3b>(i, j)[0] = 0;
                img.at<Vec3b>(i, j)[1] = 0;
                img.at<Vec3b>(i, j)[2] = 0;
                image[i][j] = 0;
            }
        }
    }
    
    
    
    cv::imshow("Last OpenCV Application", img);
    cv::moveWindow("First OpenCV Application", 0, 45);
    cv::waitKey(0);
    cv::destroyAllWindows();
    cout << col << endl;
    cout << img.rows << endl;
    cout << label;
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    int temp;
    node* n = NULL;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp = image[i][j];
            if (temp != 0)
            {
                if (image[i][j - 1] == 0 && image[i][j + 1] == 0)
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