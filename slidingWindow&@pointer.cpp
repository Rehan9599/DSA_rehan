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
    string ss;
    while(r<s.size()-1){
        ss=s.substr(l,r);
        cout<<ss<<" "<<longest<<"\n";
        for(int i=0; i<ss.size();i++){
            if(ss[i]==ss[ss.size()-i]/2){
                l++;
            }
        }
        longest=max(longest,r-l+1);
        r++;
    }
    return longest;
}

int main(){
    string S = "abcddabac";
    cout<<longestNonRepeatingSubstring(S);
    return 0;
}