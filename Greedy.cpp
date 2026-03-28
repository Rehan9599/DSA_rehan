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

bool lemonadeChange(vector<int>& bills){
    int l=0,r=0;
    int count5=0, count10=0, count20=0;
    while(r<bills.size()){
        if(bills[r]>5){
            int cash=bills[r];
            cout<<"recieved    "<<cash<<"\n";
            if(cash==10){
                if(count5>=1){
                    count5--;
                    cash-=5;
                    count10++;
                    cout<<"returning    5 \n";
                }else{
                    cout<<"no change\n";
                    return false;
                }
            }
            if(cash==20){
                if(count5>=1 && count10>=1){
                    count5--;
                    count10--;
                    cash-=15;
                    count20++;
                    cout<<"returning    5 10 \n";
                }else if(count5>=3){
                    count5-=3;
                    count20++;
                    cash-=15;
                    cout<<"returning    5 5 5 \n";
                }else{
                    cout<<"no appropriate change\n";
                    return false;
                }
            }
        }else{
            count5++;
        }
        r++;
    }
    return true;
}


int maxMeetings(vector<int>& start, vector<int>& end){
    

}


int main(){
    vector<int> bills={5, 5, 10, 10, 20};
    cout<<lemonadeChange(bills);
    return 0;
}