#include <iostream>
using namespace std;

typedef double (*FUNC)(double);

// Returns the area under the curve between x=a and x=b.
// The function passed as the first parameter determines the shape of the curve.
// Use a Riemann sum to estimate the area by dividing it into narrow rectangles (each rectangle should have a width of .0001)
// and adding up the areas of the individual rectangles.
// For a rectangle at horizontal position x, the height will be f(x).
// (when you call f(x) it'll call whatever function you passed as the first parameter)
double integrate(FUNC f, double a, double b)
{
    // Initialize current x-coordinate to lower bound
    double x = a;

    // This will be the sum of the areas, aka the Riemann sunm
    double area = 0.0;

    // To approximate integral using rectangles, the loop continues until x hits/exceeds upper bound
    while (x < b)
    {
        // Add area of current rectangle to sum of areas
        // f points to whatever function the user gave in as a parameter
        area += f(x) * 0.0001;
        x += .0001;
    }
    return area;
}

double line(double x)
{
    return x;
}

double square(double x)
{
    return x * x;
}

double cube(double x)
{
    return x * x * x;
}

int main()
{
    cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
    cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
    cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
    return 0;
}