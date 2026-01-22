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


double myPow(double x, int n) {
    if(x==1.0 || n==0) return 1.0;
    if(x==0.0) return 0.0;
    if(n>0){
        x*=myPow(x, n-1);
    }else{
        n=-n;
        x*=myPow(x, n-1);
        return 1/x;
    }
    return x;
}

double myPow1(double x, int n) {
    if(n==0) return 1.0;
    if(n==1) return x;
    int c=n;
    if(n<0){
        n=-n;
    }
    double res=1;
    while(n!=0){
        if(n%2!=0){
            res*=x;
            n--;
        }else{
            x=(x*x);
            n/=2;
        }
    }
    if(c<0) return 1/res;
    return res;
}

double myPow2(double x, int n,int res=1) {
    if(n==0) return res;
    if(n%2!=0){
        return myPow2(x,n-1,res*x);
    }else{
        return myPow2(x*x,n/2,res);
    }
    return res;
}

int countGoodNumbers(int ind,int n) {
    if(ind==n) return 1;
    int res=0;
    if(ind%2==0){
        res+=5;
    }
    else{
        res+=4;
    }
    countGoodNumbers(ind+1,n);
    return res;
}

int countGoodNumbers1(int n) {
    int ind=0;
    int res=1;
    while(ind!=n){
      if(ind%2==0){
        res*=5;
    }
    else{
        res*=4;
    }
    ind++;  
    }
    return res;
}

void insert(stack<int> &st, int top){
    if(st.empty()||st.top()<=top){
        st.push(top);
        return;
    }
    int val=st.top();
    st.pop();
    insert(st,top);
    st.push(val);
}

void sortStack(stack<int> &st){
    if(st.empty()) return;
    int top=st.top();
    st.pop();
    sortStack(st);
    insert(st,top);
}

void insertAtBot(stack<int> &st,int top){
    if(st.empty()){
        st.push(top);
        return;
    }
    int val = st.top();
    st.pop();
    insertAtBot(st,top);

    st.push(val);
}

void reverseStack(stack<int> &st) {
       if(st.empty()) return;
       int top=st.top();
       st.pop();
       reverseStack(st);
       insertAtBot(st,top);
}



vector<string> generateBinaryStrings(int n, vector<string> &vs,const string &s) {
    if(s.length()==n){
        vs.push_back(s);
        return vs;
    };
    generateBinaryStrings(n,vs,s+"0");
    if(s.empty()|| s.back()!='1'){
        generateBinaryStrings(n,vs,s+"1");
    }
    return vs;
}


vector<string> generateParenthesis(int n, vector<string> &vs,const string &s) {
    if(s.length()==2*n){
        vs.push_back(s);
        return vs;
    };
    if(s.empty()){
        generateParenthesis(n,vs,s+"(");
    }else{
        int z=0;
        for(char x : s){
            if(x==')') z++;
        }
        int c=0;
        for(char x : s){
            if(x=='(') c++;
        }

        if(c!=z && z!=n){
            generateParenthesis(n,vs,s+")");
        }
        
        if(c!=n){
           generateParenthesis(n,vs,s+"("); 
        }   
    }
    return vs;
        
}


vector<vector<int>> powerSet(vector<int>& nums,vector<vector<int>>& pSet, int n,vector<int>& s) {
    if(n==nums.size()){
        pSet.push_back(s);
        return pSet;
    }
    powerSet(nums,pSet,n+1,s);
    s.push_back(nums[n]);

    powerSet(nums,pSet,n+1,s);
    s.pop_back();
    return pSet;   
}


int countSubsequenceWithTargetSum(vector<int>& nums, int k, vector<int>& s, int n, int c){
    //     vector<vector<int>>pSet={};
    //     vector<int> s={};
    //     int c=0;
    // 	for(vector<int> x: powerSet(nums,pSet,0,s)){
    //     int s=0;
    //     for(int y : x){
    //         s+=y;
    //     }
    //     if(s==k){
    //         c++;
    //         cout<<"[";
    //     for(int y : x){

    //         cout<<y<<",";
    //     }
    //     cout<<"],  ";
    //     }  
    // }

    if(n==nums.size()){
        int m=0;
        for(int x: s){
            m+=x;
        }
        if(m==k){
            c++;
        }
        
        return c;
    }
    
    c = countSubsequenceWithTargetSum(nums, k , s, n+1, c);
    s.push_back(nums[n]);

    c = countSubsequenceWithTargetSum(nums, k , s, n+1, c);
    s.pop_back();

    return c;
}

bool checkSubsequenceSum(vector<int>& nums, int k) {
    vector<int> s={};
   if(countSubsequenceWithTargetSum(nums,k,s,0, 0) >0){
    return true;
   }
   return false;
}


void findcombinationSum(vector<int>& nums, int k,int n, vector<vector<int>>& res, vector<int>& s) {
    if(n==nums.size()){
        if(k==0){
           res.push_back(s);
        }
        return;
    }
    if(nums[n]<=k){
        s.push_back(nums[n]);
        findcombinationSum(nums,k-nums[n], n,res,s);
        s.pop_back();
    }
    findcombinationSum(nums,k,n+1,res,s);
}

vector<vector<int>> combinationSum(vector<int>& nums, int k) {
    vector<vector<int>> res={};
    vector<int> s={};
    findcombinationSum(nums,k,0,res,s);
    return res;
}

void findcombinationSum2(vector<int>& nums, int k,int n, set<vector<int>>& res, vector<int>& s) {
    if(n==nums.size()){
        if(k==0){
           res.insert(s);
        }
        return;
    }
    if(nums[n]<=k){
        s.push_back(nums[n]);
        findcombinationSum2(nums,k-nums[n],n+1,res,s);
        s.pop_back();
    }
    findcombinationSum2(nums,k,n+1,res,s);
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    set<vector<int>> res={};
    vector<int> s={};
    sort(candidates.begin(), candidates.end());
    findcombinationSum2(candidates,target,0,res,s);
    vector<vector<int>> res1(res.begin(), res.end());
    return res1;
}



vector<int> powerSetSum(vector<int>& nums,vector<int>& psS, int n,vector<int>& s) {
    if(n==nums.size()){
        int sum=0;
        for(int y:s){
            sum+=y;
        }
        psS.push_back(sum);
        return psS;
    }
    powerSetSum(nums,psS,n+1,s);
    s.push_back(nums[n]);

    powerSetSum(nums,psS,n+1,s);
    s.pop_back();
    return psS;   
}

vector<int> subsetSums(vector<int>& nums) {
    vector<vector<int>> pSet;
    vector<int> s;
    vector<int> psS;
    powerSetSum(nums,psS,0,s);
    return psS;
}

set<vector<int>> powerSetD(vector<int>& nums,set<vector<int>>& pSet, int n,vector<int>& s) {
    if(n==nums.size()){
        pSet.insert(s);
        return pSet;
    }
    powerSetD(nums,pSet,n+1,s);
    s.push_back(nums[n]);

    powerSetD(nums,pSet,n+1,s);
    s.pop_back();
    return pSet;   
}
 vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    set<vector<int>> pSet;
    vector<int> s;
    powerSetD(nums,pSet,0,s);
    vector<vector<int> > pSetD(pSet.begin(), pSet.end());
    return pSetD;
 }


void findcombinationSum3(vector<int>& nums, int k,int n, vector<vector<int>>& res, vector<int>& s,int m) {
    if(n==nums.size()){
        if(k==0 && s.size()==m){
           res.push_back(s);
        }
        return;
    }
    if(nums[n]<=k){
        s.push_back(nums[n]);
        findcombinationSum3(nums,k-nums[n],n+1,res,s,m);
        s.pop_back();
    }
    findcombinationSum3(nums,k,n+1,res,s,m);
}

vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> s;
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    findcombinationSum3(nums,k,0,res,s,n);
    return res;
}


int main(){
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    for(vector<int> x :combinationSum3(9,3)){
        cout<<"[";
        for(int y:x){
            cout<<y<<",";
        }
        cout<<"]"<<", ";
    }
    return 0;
}