#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return x * log10(x) - 1.2;
}

int main() {
    double a, b, x;
    int i = 0;
    int m = 100;
    double e = 0.000001;

    cout << "Rehan Fazal 24BCS067 \n";

    cout << "Enter initial guesses a and b: ";
    cin >> a >> b;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval: f(a) and f(b) must have opposite signs." << endl;
        return 0;
    }

    while (i < m) {
        x = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (fabs(f(x)) < e) {
            break;
        }

        if (f(a) * f(x) < 0) {
            b = x;
        } else {
            a = x;
        }
        i++;
    }


    cout << "Root = " << x << endl;
    cout << "Iterations = " << i << endl;

    return 0;
}
