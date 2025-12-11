#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double z1, z2, z3;
    double z4, z5, z6;
    double z7, z8, z9;
    double cellsize_x, cellsize_y;

    // Taking the 3x3 elevation inputs
    cout << "Enter the 3x3 elevation values (z1 to z9):\n";
    cout << "z1 z2 z3: ";
    cin >> z1 >> z2 >> z3;
    cout << "z4 z5 z6: ";
    cin >> z4 >> z5 >> z6;
    cout << "z7 z8 z9: ";
    cin >> z7 >> z8 >> z9;

    // Taking cell sizes
    cout << "Enter the cell size in X direction: ";
    cin >> cellsize_x;
    cout << "Enter the cell size in Y direction: ";
    cin >> cellsize_y;

    // Applying Horn's method for slope
    double dzdx = ( (z3 + 2*z6 + z9) - (z1 + 2*z4 + z7) ) / (8.0 * cellsize_x);
    double dzdy = ( (z7 + 2*z8 + z9) - (z1 + 2*z2 + z3) ) / (8.0 * cellsize_y);

    // Compute slope
    double slope_rad = atan( sqrt( (dzdx * dzdx) + (dzdy * dzdy) ) );
    double slope_deg = slope_rad * (180.0 / M_PI);

    // Output
    cout << "\n=========== OUTPUT ===========\n";
    cout << "dz/dx : " << dzdx << endl;
    cout << "dz/dy : " << dzdy << endl;
    cout << "Slope (radians): " << slope_rad << endl;
    cout << "Slope (degrees): " << slope_deg << endl;

    return 0;
}
