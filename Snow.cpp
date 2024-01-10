#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

float a = 60 * 3.14 / 180; // Angle in radians for rotation

// Recursive function to generate Koch snowflake
void koch(int x1, int y1, int x2, int y2, int it) {
    int x3, y3, x4, y4, x, y;

    // Calculate the coordinates of the two intermediate points
    x3 = (2 * x1 + x2) / 3;
    y3 = (2 * y1 + y2) / 3;

    x4 = (x1 + 2 * x2) / 3;
    y4 = (y1 + 2 * y2) / 3;

    // Calculate the new endpoint after rotation
    x = x3 + (x4 - x3) * cos(a) + (y4 - y3) * sin(a);
    y = y3 - (x4 - x3) * sin(a) + (y4 - y3) * cos(a);

    // Recursively call koch function for each segment
    if (it > 0) {
        koch(x1, y1, x3, y3, it - 1);
        koch(x3, y3, x, y, it - 1);
        koch(x, y, x4, y4, it - 1);
        koch(x4, y4, x2, y2, it - 1);
    } else {
        // Draw lines when recursion depth is reached
        line(x1, y1, x3, y3);
        line(x3, y3, x, y);
        line(x, y, x4, y4);
        line(x4, y4, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 150, y1 = 200, x2 = 250, y2 = 200;

    // Calculate the third point for the equilateral triangle
    int x3 = x1 + (x2 - x1) * cos(a) + (y2 - y1) * sin(a);
    int y3 = y1 - (x2 - x1) * sin(a) + (y2 - y1) * cos(a);

    // Call koch function to draw the snowflake
    koch(x2, y2, x1, y1, 2);
    koch(x1, y1, x3, y3, 2);
    koch(x3, y3, x2, y2, 2);

    delay(10000);
    closegraph();
}
