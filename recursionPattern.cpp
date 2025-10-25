#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <stack>
using namespace std;


double myPow(double x, int n) {
    if(x==1.0 || n==0) return 1.0;
    if(x==0.0) return 0.0;
    if(n>0){
        x*=myPow(x, n-1);
    }else{
        n=-n;
        x*=myPow(x, n-1);
        return 1/x;
    }
    return x;
}

double myPow1(double x, int n) {
    if(n==0) return 1.0;
    if(n==1) return x;
    int c=n;
    if(n<0){
        n=-n;
    }
    double res=1;
    while(n!=0){
        if(n%2!=0){
            res*=x;
            n--;
        }else{
            x=(x*x);
            n/=2;
        }
    }
    if(c<0) return 1/res;
    return res;
}

double myPow2(double x, int n,int res=1) {
    if(n==0) return res;
    if(n%2!=0){
        return myPow2(x,n-1,res*x);
    }else{
        return myPow2(x*x,n/2,res);
    }
    return res;
}

int countGoodNumbers(int ind,int n) {
    if(ind==n) return 1;
    int res=0;
    if(ind%2==0){
        res+=5;
    }
    else{
        res+=4;
    }
    countGoodNumbers(ind+1,n);
    return res;
}

int countGoodNumbers1(int n) {
    int ind=0;
    int res=1;
    while(ind!=n){
      if(ind%2==0){
        res*=5;
    }
    else{
        res*=4;
    }
    ind++;  
    }
    return res;
}


int main(){
    cout<<countGoodNumbers1(2);
    return 0;
}