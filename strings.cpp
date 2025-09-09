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
    string ans="";
    int count=0;
    for(int i=0;i<l;i++){
        if(s[i]=='('){
            if(count>0){
                ans.append("(");
            }
            count++;
        }
        else if(s[i]==')'){
            count--;
            if(count>0){
                ans.append(")");
            }
        }
    }
    return ans;
}



string reverseWords(string s) {
    if(s[0]==' ' && s[s.size()-1]==' '){
        s=s.substr(1,s.size()-2);
    }
    cout<<s<<'\n';
    int l=s.size();
    string rev="";
    int c=l-1;
    for(int i=l-1;i>=0;i--){
        if(s[i]==' '){
            cout<<c<<','<<i<<"\n";
            rev.append(s.substr(i+1,c-i));
            rev.append(" ");
            c=i-1;
        }
    }
    cout<<c<<'\n';
    if(c>0){
        rev.append(s.substr(0,c+1));
    }
    return rev;
} 

string binaryToHexa(string s){
    string zeroes;
    if(s.size()%4!=0){
        int siz=((s.size()/4)+1);
        for(int i=0;i<siz;i++){
            zeroes.append("0");
        }
        zeroes.append(s);
    }
    string ans;
    for(int j=0; j<zeroes.size()-1; j+=4){
        string num=zeroes.substr(j,4);
    }
    return zeroes;
}

int main(){
    string s="1010101011";
    cout<<binaryToHexa(s);

    return 0;
}