#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string>
using namespace std;


string removeOuterParentheses(string s) {
    int l= s.length();
    set<int> p={};
    vector<string>  ponda;
    while(l>0){
    p.insert(s.find(")(",l));
    l--;
    }
    l= s.length();
    for(auto x:p){
        cout<<x<<"\n";
    }
    if(*p.begin()){
        for(int i=0; i<p.size(); i++){
            int c= *(p.begin());
            ponda.push_back(s.substr(0,2));
        }
    }
    else{
        return s.substr(1,l-2);
    }
    return "io";
}


int main(){
    string s="()((())))()";
    cout<<removeOuterParentheses(s);

    return 0;
}