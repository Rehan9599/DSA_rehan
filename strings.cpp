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


string largeOddNum(string& s){
    int l=s.size();
    string oddS;
    int oddLargest=INT16_MIN;
    for(int i=0;i<l;i++){
        if(s[i]=='0') continue;
        for(int j=i; j<l; j++){
            oddS=s.substr(i,j-i+1);
            int l1=oddS.size();
            char lastDigit=oddS.back();
            int dig=stoi(oddS);
            if( ( lastDigit - '0') %2 !=0 ){
                oddLargest=max(oddLargest,dig);
            }
        }
    }

    string ans=to_string(oddLargest);
    return ans;
}


string longestCommonPrefix(vector<string>& str){
    string ans="";
    int count=0;
    int j;
    for(int i=1; i<str.size(); i++){
        if(str[0].front()!=str[i].front()){
                return ans;
            }
        for(j=1; j<str.size(); j++){
            if(str[0].substr(0,j)!=str[i].substr(0,j)){
                break;
            }
            else{
                count++;
            }
    }
}
    if(count==str.size()-1) ans.append(str[0].substr(0,j));
    return ans;
}


int main(){
    vector<string> str={"flowers" , "flow" , "fly", "flight"};
    cout<<longestCommonPrefix(str);

    return 0;
}