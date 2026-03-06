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


int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
    sort(Cookie.begin(), Cookie.end());
    sort(Student.begin(),Student.end());

    int l=0,r=0;
    while(l<Cookie.size() && r<Student.size()){
        if(Cookie[l]>=Student[r]){
            r++;
        }
        l++;
    }
    return r;
}

double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
    long long sum=0;
    long long res=0;
    for(auto x: wt){
        sum+=x;
    }
    if(sum<capacity){
        for(auto x: val){
        res+=x;
        }
        return res;
    }
    vector<pair<double ,int>> unitValue;
    for(int i=0;i<val.size();i++){
        unitValue.push_back({val[i]/wt[i],i});
    }
    
    sort(unitValue.begin(),unitValue.end(),greater<pair<double, int>>());
    for(int i=0;i<val.size();i++){
        if(capacity==0) break;
        int y=unitValue[i].second;
        if(wt[y]<capacity){
            res+=val[y];
            capacity-=wt[y];
        }else{
            res+=(capacity*val[y])/wt[y];
            capacity=0;
        }
    }
    return res;
}


int main(){
    vector<long long> val={60,100};
    vector<long long> wt={10,20};
    long long capacity=50;
    cout<<fractionalKnapsack(val,wt,capacity);
    return 0;
}