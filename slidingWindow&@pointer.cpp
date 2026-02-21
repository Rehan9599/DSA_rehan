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

int maxScore(vector<int>& cardScore , int k){
    // int l=0,r=cardScore.size()-1,maxx=0;
    // while(r>0&&k>0){
    //     if(cardScore[r]>cardScore[l]){
    //         maxx+=cardScore[r];
    //         r--;
    //         k--;
    //     }else{
    //         maxx+=cardScore[l];
    //         l++;
    //         k--;
    //     }
    // }
    // return maxx;

    int total=0;
    for(int i=0;i<k;i++){
        total+=cardScore[i];
    }

    int maxxx=total;

    for(int i=0;i<k;i++){
        total-=cardScore[k-i-1];

        total+=cardScore[cardScore.size()-i-1];

        maxxx=max(total,maxxx);
    }

    return maxxx;
}


int main(){
    vector<int> nums = {5, 4, 1, 8, 7, 1, 3};
    cout<<maxScore(nums,3);
    return 0;
}