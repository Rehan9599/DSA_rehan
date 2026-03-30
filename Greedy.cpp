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
    for(int i=0;i<end.size();i++){
        for(int j=i+1; j<end.size()-1;j++){
            if(end[j]<end[i]){
                swap(end[j],end[i]);
                swap(start[j],start[i]);
            }
        }
    }

    int r=0, ans=0 , lastend=INT16_MIN;
    while(r<end.size()){
        if(start[r]>lastend){
            ans++;
            lastend=end[r];
        }
        r++;
    }
    return ans;
}


bool canJump(vector<int>& nums) {
    int r=0, maxin=nums[0];
    while(r<nums.size()){
        if(r>maxin){
            return false;
        }else{
            maxin=max(maxin, r+nums[r]);
        }
        r++;
    }
    return true;
}

int jump(vector<int>& nums) {
int r=0, maxin=0,jump=0,end=0;
    while(r<nums.size()){
        if(r>maxin){
            return 0;
        }else{
            maxin=max(maxin, r+nums[r]);
            if(r==end){
                jump++;
                end=maxin;
            }
            if(end>=nums.size()-1) break;
        }
        r++;
    }
    return jump;
}

int findPlatform(vector<int>& Arrival, vector<int>& Departure){
    int nPlatforms=1,maxplatform=1;
    sort(Departure.begin(),Departure.end());
    sort(Arrival.begin(),Arrival.end());
    int r=1,l=0;
    // while(nPlatforms<Arrival.size()){
    //     nPlatforms++;
    //     r=0;
    //     int Atime=50,f=0;
    //    while(r<Departure.size()){
    //     if(Arrival[r]>Atime){
    //         Arrival[r]=nPlatforms;
    //         Atime=Departure[r];
    //     }
    //     r++;
    // }
    // for(auto x:Arrival){
    //     if(x>Arrival.size()){
    //         f=1;
    //     }
    // }
    // if(f==0) break;
    // }

    while(r<Departure.size()){
        maxplatform=max(maxplatform,nPlatforms);
        if(Arrival[r]<=Departure[l]){
            nPlatforms++;
            r++;
        }else{
            nPlatforms--;
            l++;
        }
    }
    return maxplatform;
}

bool compareCols(const std::vector<int>& v1, const std::vector<int>& v2) {
    return v1[2] > v2[2]; 
}
vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
    sort(Jobs.begin(), Jobs.end(), compareCols);

    vector<int> ans;
    int maxprofit=0, njobs=0;

    int i=0,j=0,time=0;
    while(i<Jobs.size()){
        if(Jobs[i][1]>time){
            maxprofit+=Jobs[i][2];
            njobs++;
            time++;
        }
        i++;
    }

    ans.push_back(njobs);
    ans.push_back(maxprofit);

    return ans;

} 


int main(){
vector<vector<int>> jobs= {{1, 2, 100} , {2, 1, 19} , {3, 2, 27} , {4, 1, 25}, {5,1,15}};
for(auto &x:JobScheduling(jobs)){
    cout<<x<<" ";
}
    return 0;
}