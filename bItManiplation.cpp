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


//could have used XOR also
int minBitsFlip(int start, int goal) { 
    int i=0;
    int c=0;
    while(pow(2,i)<=start || pow(2,i)<=goal){
        if(checkIthBit(start,i)!=checkIthBit(goal,i)){
            c++;
        }
        i++;
    } 
    return c;  
}

int singleNumber(vector<int>& nums){
    int a=0;
    for(int i=0; i<nums.size(); i++){
        a^=nums[i];
    }
    return a;
}
vector<vector<int> > powerSet(vector<int>& nums) {
    vector<vector<int>> p;
    int j=0;
    while(j<(1<<nums.size())){
        vector<int> s;
       for(int i=0; i<nums.size(); i++){
        if(checkIthBit(j,i)){
            s.push_back(nums[i]);
        }
       }
       p.push_back(s);
       j++; 
    }
    return p;
}

int findRangeXOR(int l,int r){
    int a=0;
    for(l; l<=r; l++){
        a^=l;
    }
    return a;
}


vector<int> singleNumber3(vector<int>& nums){
    int a=0;
    for(int i=0; i<nums.size(); i++){
        a^=nums[i];
    }
    int i=0;
    while(i<(a>>1)){
        if(1<<i &a){
            break;
        }
        i++;
    }
    int s=0,t=0;
    for(int j=0; j<nums.size(); j++){
        if(1<<i & nums[j]){
           s^=nums[j];
        }else{
           t^=nums[j];
        }
    }
    vector<int> ans;
    if(t>=s){
        ans={s,t};
    }else{
        ans={t,s};
    }
    return ans;
}

vector<int> divisors(int n) {
  
}

int main(){
    for(auto x: divisors(18)){
        cout<<x<<" ";
    }
    return 0;
}