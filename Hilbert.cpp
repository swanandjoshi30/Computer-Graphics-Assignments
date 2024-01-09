#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

// Function to move the pen in a specific direction
void move(int j, int h, int &x, int &y)
{
    if (j == 1)
        y -= h;
    else if (j == 2)
        x += h;
    else if (j == 3)
        y += h;
    else if (j == 4)
        x -= h;
    lineto(x, y);
}

// Function to generate Hilbert Curve using recursion
void hilbert(int r, int d, int l, int u, int i, int h, int &x, int &y)
{
    if (i > 0)
    {
        i--;

        // Recursive calls to generate Hilbert Curve
        hilbert(d, r, u, l, i, h, x, y);
        move(r, h, x, y);

        hilbert(r, d, l, u, i, h, x, y);
        move(d, h, x, y);

        hilbert(r, d, l, u, i, h, x, y);
        move(l, h, x, y);

        hilbert(u, l, d, r, i, h, x, y);
    }
}

int main()
{
    // Initial parameters for the Hilbert Curve
    int n, x1, y1;
    int x0 = 50, y0 = 150, x, y, h = 10, r = 2, d = 3, l = 4, u = 1;

    // Input the order of the Hilbert Curve
    cout << "\n Give the value of n: ";
    cin >> n;

    // Set initial position for the pen
    x = x0;
    y = y0;

    // Initialize graphics window
    int gm, gd = DETECT;
    initgraph(&gd, &gm, NULL);

    // Move to the starting position
    moveto(x, y);

    // Generate Hilbert Curve
    hilbert(r, d, l, u, n, h, x, y);

    // Delay to keep the graphics window open
    delay(100000);

    // Close graphics window
    closegraph();

    return 0;
}
