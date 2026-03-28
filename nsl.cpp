#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x){
   return (pow(x,3)-2*x-5);
}

double df(double x){
   return (3*pow(x,2)-2);
}


double findRootNewton(double x0, double x1, double e){
      static int iter = 1;
      cout << "Iteration " << iter << ": x = " << x1 << ", f(x) = " << f(x1) << endl;
      if(fabs(x1-x0) <= e){
         return x1;
      }
      double x2 = x1 - f(x1)/df(x1);
      iter++;
      return findRootNewton(x1, x2, e);
}


int main(){
    cout << "Rehan Fazal 24BCS067 \n";
   double x0 = 2.0;
   double x1 = x0 - f(x0)/df(x0);
   cout << findRootNewton(x0, x1, 0.0001);
   return 0;
}