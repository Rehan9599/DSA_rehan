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


bool checkIthBit(int n, int i) {
    return (1<<i & n);
}

bool isOdd(int n) {
    return 1&n;
}


bool isPowerOfTwo(int n){
    return !(n&(n-1));
}
int countSetBits(int n, int i,int c) {
    if(pow(2,i) >= n) return c;
    if((1<<i) & n){
        c++;
    }
    return countSetBits(n,i+1,c);
    
}


void swap(int &a, int &b) {
    a=a^b;
    b=a^b;
    a=a^b;
}

int divbit(int n, int d, int q){
    bool sign=true;
    if(n>0&&d<0 || n<0 && d>0) sign=false;
    n=abs(n);
    d=abs(d);
    while(n>=d){
        int i =0;
        while ((d<<i+1) < n){
            i++;
        }
        q+=1<<i;
        n-=d<<i;
    }
    return sign? q: -q;
}

int divide(int dividend, int divisor) {
    return divbit(dividend,divisor,0);
}
int main(){
    cout<<divide(10,-2);
    return 0;
}