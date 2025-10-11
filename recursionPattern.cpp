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


int main(){
    cout<<countGoodNumbers(0,2);
    return 0;
}