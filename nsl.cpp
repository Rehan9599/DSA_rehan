#include <iostream>
#include <cmath>   // for pow()

using namespace std;

int main() {
    cout << "NAME: REHAN FAZAL \nROLL NO:24BCS067\n" << endl;

    float p, r, t, si, ci;

    cout << "Enter principal, rate, time: ";
    cin >> p >> r >> t;

    // Simple Interest
    si = (p * r * t) / 100;

    // Compound Interest
    ci = p * pow((1 + r / 100), t) - p;

    cout << "Simple Interest = "  << si << endl;
    cout << "Compound Interest = " << ci << endl;

    return 0;
}
