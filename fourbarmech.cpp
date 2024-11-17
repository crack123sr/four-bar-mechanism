#include <iostream>
#include <cmath>
using namespace std;

// taking origin as point O;

double L1, L2, L3, d;
double sin_theta, cos_theta;
double x1_coord, y1_coord, r1;
double x2, y2, r2;
double theta_degrees;

void solveCircleIntersection()
{
    double distance = sqrt((x2 - x1_coord) * (x2 - x1_coord) + (y2 - y1_coord) * (y2 - y1_coord));

    double a = (r1 * r1 - r2 * r2 + distance * distance) / (2 * distance);
    double h = sqrt(r1 * r1 - a * a);
    double x0 = x1_coord + a * (x2 - x1_coord) / distance;
    double y0 = y1_coord + a * (y2 - y1_coord) / distance;

    double rx = -h * (y2 - y1_coord) / distance;
    double ry = h * (x2 - x1_coord) / distance;

    double xi1 = x0 + rx;
    double xi2 = x0 - rx;
    double yi1 = y0 + ry;
    double yi2 = y0 - ry;

    cout << "coordinates of joint 2 are:" << endl;

    if ( theta_degrees<=180)
    {
        cout << " (" << xi1 << ", " << yi1 << ")" << endl;
    }
    else
    {
        cout << "(" << xi2 << ", " << yi2 << ")" << endl;
    }
}

int main()
{
    // Angle in degrees
    

    cout << "ENTER L1: ";
    cin >> L1;
    cout << "ENTER L2: ";
    cin >> L2;
    cout << "ENTER L3: ";
    cin >> L3;
    cout << "ENTER d: ";
    cin >> d;
    double i;

for(i=0;i<=60;i++){
   theta_degrees=i;
     double theta_radians = theta_degrees * M_PI / 180.0;

    sin_theta = sin(theta_radians);
    cos_theta = cos(theta_radians);


    x1_coord = L1 * cos_theta;
    y1_coord = L1 * sin_theta;
    r1 = L2;
    x2 = d;
    y2 = 0;
    r2 = L3;
    cout<<theta_degrees<<endl;
    cout << "Coordinates of joint 1 are: (" << x1_coord << ", " << y1_coord << ")" << endl;
    solveCircleIntersection();
}
    return 0;
}
