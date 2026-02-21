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

int main(){
    string S = "aaabbbccc";
    cout<<longestNonRepeatingSubstring(S);
    return 0;
}