#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
void gaussJordan(double a[10][11], int n, double x[10]){
   for(int i = 0; i < n; i++){
      if(fabs(a[i][i]) < 1e-12){
         for(int k = i + 1; k < n; k++){
            if(fabs(a[k][i]) > 1e-12){
               for(int j = 0; j <= n; j++){
                  swap(a[i][j], a[k][j]);
               }
               break;
            }
         }
      }

      double pivot = a[i][i];
      for(int j = 0; j <= n; j++){
         a[i][j] = a[i][j] / pivot;
      }

      for(int k = 0; k < n; k++){
         if(k != i){
            double factor = a[k][i];
            for(int j = 0; j <= n; j++){
               a[k][j] = a[k][j] - factor * a[i][j];
            }
         }
      }
   }

   for(int i = 0; i < n; i++){
      x[i] = a[i][n];
   }
}



int main(){
   cout << "Rehan Fazal 24BCS067 \n";

   int n;
   double a1[10][11], a2[10][11];
   double x1[10], x2[10];

   cout << "Enter number of equations: ";
   cin >> n;

   cout << "Enter augmented matrix coefficients:" << endl;
   for(int i = 0; i < n; i++){
      for(int j = 0; j <= n; j++){
         cin >> a1[i][j];
         a2[i][j] = a1[i][j];
      }
   }

   cout << "\nGauss Jordan Process:\n";
   gaussJordan(a2, n, x2);
   cout << "Solution by Gauss Jordan:" << endl;
   for(int i = 0; i < n; i++){
      cout << "x" << i + 1 << " = " << fixed << setprecision(6) << x2[i] << endl;
   }
   return 0;
}

// cout << "\nGauss Elimination Process:\n";
   // gaussElimination(a1, n, x1);
   // cout << "Solution by Gauss Elimination:" << endl;
   // for(int i = 0; i < n; i++){
   //    cout << "x" << i + 1 << " = " << fixed << setprecision(6) << x1[i] << endl;
   // }

   
   void gaussElimination(double a[10][11], int n, double x[10]){
//    for(int k = 0; k < n - 1; k++){
//       if(fabs(a[k][k]) < 1e-12){
//          for(int i = k + 1; i < n; i++){
//             if(fabs(a[i][k]) > 1e-12){
//                for(int j = 0; j <= n; j++){
//                   swap(a[k][j], a[i][j]);
//                }
//                break;
//             }
//          }
//       }

//       for(int i = k + 1; i < n; i++){
//          double factor = a[i][k] / a[k][k];
//          for(int j = k; j <= n; j++){
//             a[i][j] = a[i][j] - factor * a[k][j];
//          }
//       }
//    }

//    for(int i = n - 1; i >= 0; i--){
//       double sum = 0;
//       for(int j = i + 1; j < n; j++){
//          sum = sum + a[i][j] * x[j];
//       }
//       x[i] = (a[i][n] - sum) / a[i][i];
//    }
// }