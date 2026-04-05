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


long long solve(vector<int>& bt) {
    sort(bt.begin(),bt.end());
    int wt=0;
    int twt=0;
    int r=0;
    while(r<bt.size()-1){
        wt+=bt[r];
        r++;
        twt+=wt;
        cout<<wt<<" "<<twt<<"\n";
    }
    return floor(twt/bt.size());
}



class LRUCache {
  private:
  int n;
  int i,recent;
  unordered_map<int,int> lru;
  public:

  LRUCache(int capacity) {
    n=capacity;
    i=0;
  }

  int get(int key_) {
    if(lru.find(key_) != lru.end()){
        recent=key_;
        return lru[key_];
    }else{
        return -1;
    }
  }

  void put(int key_, int value) {
    if(i<n){
        lru[key_]=value;
        recent=key_;

        i++;
    }else{
        int lr;
        if(n>1){
        for(auto x :lru){
            if(x.first!=recent){
                lr=x.first;
            }
        } 
        }else{
            lr=recent;
        }
        lru.erase(lr);
        recent=key_;
        lru[key_]=value;
    }
  }
};



vector<vector<int>> insertNewInterval(vector<vector<int>>& Intervals, vector<int>& newInterval){
    int l=0,r=0;
    while(l<Intervals.size()){
        if(newInterval[0]<=Intervals[l][1] && Intervals[l][1]<=newInterval[1]){
            Intervals.insert(Intervals.begin()+l+1,newInterval);
            break;
        }
        l++;
    }
    while(r<Intervals.size()-1){
        if(Intervals[r][1]>=Intervals[r+1][0]){
            Intervals[r][1]=max(Intervals[r+1][1], Intervals[r][1]);
            Intervals.erase(Intervals.begin()+r+1);
        }else{
            r++;
        }
    }
    return Intervals;
}

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    int r=0;
    while(r<intervals.size()-1){
        if(intervals[r][1]>=intervals[r+1][0]){
            intervals[r][1]=max(intervals[r+1][1], intervals[r][1]);
            intervals.erase(intervals.begin()+r+1);
        }else{
            r++;
        }
    }
    return intervals;
}


int MaximumNonOverlappingIntervals(vector<vector<int>>& Intervals) {
    sort(Intervals.begin(),Intervals.end(),[](vector<int> x, vector<int> y){
        return x[1]<y[1];
    });
    int r=0,c=0,l=1;
    while(r<Intervals.size() && l<Intervals.size()){
        if(Intervals[r][1]<=Intervals[l][0]){
            r++;
            c++;
        }
        l++;
    }
return Intervals.size()-c-1;
}


int main(){
vector<vector<int>> Intervals = {{ 1, 2},{2,3},{3,4},{1,3}};
vector<int> newInterval= {2,5};
cout<<MaximumNonOverlappingIntervals(Intervals);
return 0;
}