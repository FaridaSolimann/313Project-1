#include <iostream>

using namespace std;

int main (){

    double a11 = 10, a12 = 2, a13 = -1, a21 = -3, a22 = -6, a23 = 2, a31 = 1, a32 = 1, a33 = 5;
    double b1 = 27, b2 = -61.5, b3 = -21.5;
    double x1_old, x2_old, x3_old, x1_new, x2_new, x3_new, e1, e2, e3;

    e1 = e2 = e3 = 100;

    cout << "Please enter the initial guesses: " << endl;
    cout << "x1: ";
    cin >> x1_old;
    cout << "x2: ";
    cin >> x2_old;
    cout << "x3: ";
    cin >> x3_old;

    while (e1 > 0.01 || e2 > 0.01 || e3 > 0.01) {
        x1_new = (b1 - a12 * x2_old - a13 * x3_old) / a11;
        x2_new = (b2 - a21 * x1_old - a23 * x3_old) / a22;
        x3_new = (b3 - a31 * x1_old - a32 * x2_old) / a33;

        e1 = ((x1_new - x1_old) / x1_new) * 100;
        e2 = ((x2_new - x2_old) / x2_new) * 100;
        e3 = ((x3_new - x3_old) / x3_new) * 100;

        x1_old = x1_new;
        x2_old = x2_new;
        x3_old = x3_new;
    }

    cout << "x1: " << x1_old << endl;
    cout << "x2: " << x2_old << endl;
    cout << "x3: " << x3_old << endl;

    return 0;
}

