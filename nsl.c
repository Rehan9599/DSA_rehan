// #include <stdio.h>
// #include <math.h>

// int main() {
   
//     printf("NAME: REHAN FAZAL \nROLL NO:24BCS067\n");

//     float p, r, t, si, ci;

//     printf("Enter principal, rate, time: ");
//     scanf("%f %f %f", &p, &r, &t);

//     // Simple Interest
//     si = (p * r * t) / 100;

//     // Compound Interest
//     ci = p * pow((1 + r / 100), t) - p;

//     printf("Simple Interest = %.2f\n", si);
//     printf("Compound Interest = %.2f\n", ci);
//     return 0;
// }

// #include <stdio.h>
// #include <math.h>

// int main() {
   
//     printf("NAME: REHAN FAZAL \nROLL NO:24BCS067\n");

//     int n; 
//     printf("Enter decimal number: "); 
//     scanf("%d", &n); 
//     int bin[32], i = 0; 
    
//     while(n > 0)
//         { 
//         bin[i++] = n % 2; 
//         n /= 2; 
//         } 

//     printf("Binary: "); 
//     for(int j = i-1; j >= 0; j--) 
//     printf("%d", bin[j]); 
    
//     return 0;

// }

// #include <stdio.h>
// #include <math.h>
// #include <string.h>

// int main() {
   
//     printf("NAME: REHAN FAZAL \nROLL NO:24BCS067\n");

//     char bin[32]; 

//     printf("Enter binary number: "); 
//     scanf("%s", bin); 

//     int dec = 0, len = strlen(bin); 

//     for(int i = 0; i < len; i++) 
//     dec += (bin[len-i-1] - '0') * pow(2, i); 

//     printf("Decimal: %d\n", dec); 
//     return 0;

// }


// #include <stdio.h>
// #include <math.h>
// #include <string.h>

// int main() {
   
//     printf("NAME: REHAN FAZAL \nROLL NO:24BCS067\n" );

//     int n,i;double x,term,sum; 
//     printf("Enter the angle in degrees: "); 
//     scanf("%lf",&x); 
//     printf("Enter number of terms: "); 
//     scanf("%d",&n);  
//     x=x* 3.1467 /180.0; 
//     sum=0; 

//     for(i=0;i<n;i++)
//     { 
//     term=pow(-1,i)*pow(x,2*i+1)/tgamma(2*i+2); 
//     sum+=term;
// } 
//     printf("Sum of sine series=%.6lf\n",sum); 
//     sum=0; 
//     for(i=0;i<n;i++)
//     { 
//     term=pow(-1,i)*pow(x,2*i)/tgamma(2*i+1); 
//     sum+=term;
// } 
//     printf("Sum of cosine series=%.6lf\n",sum); 
//     return 0; 
//  }


// #include <stdio.h>

// long fact(int n) 
// { 
// long f = 1; 
// for(int i=1; i<=n; i++) f *= i; 
// return f;
// } 

// int main() {
   
//     printf("NAME: REHAN FAZAL \nROLL NO:24BCS067\n" );

//     int n, r; 
//     printf("Enter n and r: "); 
//     scanf("%d %d", &n, &r); 

//     long P = fact(n) / fact(n-r); 
//     long C = fact(n) / (fact(r) * fact(n-r)); 

//     printf("nPr = %ld\n", P); 
//     printf("nCr = %ld\n", C); 

//     return 0;
// } 




#include <stdio.h>

 int fibonacci(int a) 
{ 
    if (a == 1 || a == 2) 
    { 
      return 1; 
    } 
   return fibonacci(a - 1) + fibonacci(a - 2);
}
int main() {
   
    printf("NAME: REHAN FAZAL \nROLL NO:24BCS067\n" );

    int a; 
    printf("number of terms :"); 
    scanf("%d", &a); 

    printf("series is : "); 

    for(int i=1;i<=a;i++)
    {
    printf(" %d", fibonacci(i));
    } 

    return 0;
}
