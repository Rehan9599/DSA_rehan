#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <climits>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


int climbStairs(int n) {
    if(n==0){
        return 1;
    }
    if(n==1) return 1;

    int l= climbStairs(n-1);
    int r=climbStairs(n-2);
    

    return l+r;
}

int energy(vector<int>& heights, int n){
    if(n==0) return 0;
    int s2;
    int s1= energy(heights,n-1) + abs(heights[n]-heights[n-1]);
    if(n>1) s2= energy(heights,n-2) + abs(heights[n]-heights[n-2]);

    return min(s1,s2);
}

int frogJump(vector<int>& heights) {
    int n=heights.size()-1;
    return energy(heights,n);
}

int main(){
    vector<int> s={2,1,3,5,4};
    cout<<frogJump(s);
    return 0;
}