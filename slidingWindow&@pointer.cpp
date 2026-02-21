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
#include <string>
using namespace std;

int longestNonRepeatingSubstring(string& s){
    int l=0;
    int r=0;
    int longest=0;
    map<char,int> mpstr;
    while(r<s.size()){
        if(mpstr.find(s[r]) != mpstr.end() && mpstr[s[r]]>=l){
            l=mpstr[s[r]]+1;
        }
        mpstr[s[r]]=r;
        longest=max(longest,r-l+1);
        cout<<s.substr(l,r-l+1)<<" "<<mpstr[s[r]]<<" "<<longest<<" "<<l<<" "<<r<<"\n";
        r++;
    }
    return longest;
}


int longestOnes(vector<int>& nums, int k) {
    int l=0,r=0,nzero=0;
    int longest=0;
    while(r<nums.size()){
        if(nums[r]==0){
            nzero++;
        }
        if(nzero>k){
            if(nums[l]==0){
                nzero--;
            }
            l++;
        }
        longest=max(longest,r-l+1);
        r++;
    }
    return longest;
}


int totalFruits(vector<int>& fruits){
    int l=0,r=0,longest=0;
    map<int,int> mpf;
    while(r<fruits.size()){
        mpf[fruits[r]]++;
        while(mpf.size()>2){
            mpf[fruits[l]]--;
            if(mpf[fruits[l]]==0){
                mpf.erase(fruits[l]);
            }
            l++;
        }
        longest=max(longest,r-l+1);
        r++;
    }
    return longest;
}


int main(){
    vector<int> nums = {1, 2, 1};
    cout<<totalFruits(nums);
    return 0;
}