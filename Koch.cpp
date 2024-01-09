/*
  Problem Statement: c) C++ program to generate fractal patterns using Koch curves.
  Code from Computer Graphics (SPPU - Second Year - Computer Engineering - Content) repository on KSKA Git: https://git.kska.io/sppu-se-comp-codes/CG
*/

#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

// Function to draw Koch curve
void koch(int x1, int y1, int x2, int y2, int it)
{
    // Calculate the angle for trisection
    float angle = (60 * 3.14) / 180;

    // Calculate trisection points
    int x3 = (2 * x1 + x2) / 3;
    int y3 = (2 * y1 + y2) / 3;
    int x4 = (2 * x2 + x1) / 3;
    int y4 = (2 * y2 + y1) / 3;

    // Calculate the new point for creating the triangle
    int x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
    int y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

    // Recursive calls to create the Koch curve
    if (it > 0)
    {
        koch(x1, y1, x3, y3, it - 1);
        koch(x3, y3, x, y, it - 1);
        koch(x, y, x4, y4, it - 1);
        koch(x4, y4, x2, y2, it - 1);
    }
    else
    {
        // Draw lines for the base case
        line(x1, y1, x3, y3);
        line(x3, y3, x, y);
        line(x, y, x4, y4);
        line(x4, y4, x2, y2);
    }
}

int main()
{
    // Initialize graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Input coordinates and order of the Koch curve
    int x1, y1, x2, y2, order;
    cout << "Enter value of x1: ";
    cin >> x1;
    cout << "Enter value of y1: ";
    cin >> y1;
    cout << "Enter value of x2: ";
    cin >> x2;
    cout << "Enter value of y2: ";
    cin >> y2;
    cout << "Enter order of curve: ";
    cin >> order;

    // Draw Koch curve
    koch(x1, y1, x2, y2, order);

    // Delay to keep the graphics window open
    delay(10000);

    // Close graphics window
    closegraph();

    return 0;
}
// END OF CODE
