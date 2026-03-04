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

class Solution{
    private:
    int n;
    int i;
    vector<int> heapVec;
    public:

        void initializeHeap(){
            n=10;
            i=0;
            heapVec.resize(n);
        }

        void insert(int key){
            heapVec[i++]=key;
            int k=i-1;
            while (k > 0 && heapVec[k] < heapVec[(k-1)/2]) {
                swap(heapVec[k], heapVec[(k-1)/2]);
                k = (k-1)/2;
            }
        }

        void display(){
            for(int k=0; k<i; k++){
                cout<< heapVec[k]<<" ";
            }
        }

        void changeKey(int index, int new_val){
            heapVec[index]=new_val;
            int k=i-1;
            while (k > 0 && heapVec[k] < heapVec[(k-1)/2]) {
                swap(heapVec[k], heapVec[(k-1)/2]);
                k = (k-1)/2;
            }
        }

        void extractMin(){
            heapVec[0]=heapVec[i-1];
            heapVec.pop_back();
            i--;
            int k=i-1;
            while(k>0){
                if(heapVec[k]<heapVec[(k-1)/2]){
                    swap(heapVec[k],heapVec[(k-1)/2]);
                }
                k=(k-1)/2;
            }
            while(k<=i && 2*k+1<=i && 2*k+2<=i){
                if(heapVec[k]>heapVec[2*k+1] && 2*k+1<=i){
                    swap(heapVec[k],heapVec[2*k+1]);
                }
                k=2*k+1;
            }
        }

        bool isEmpty(){
            return i==0;
        }

        int getMin(){
            return heapVec[0];
        }

        int heapSize(){
            return i;
        }
};

bool isHeap(vector<int>& nums) {
    int i=0,f=0;
    while(i<nums.size() && 2*i+1 < nums.size()){
        if(nums[i]<nums[i*2+1] && nums[i]<nums[2*i+2]){
            f=1;
        }else{
            f=0;
        }
        i++;
    }
    return f;
}

// vector<int> minToMaxHeap(vector<int> nums) {
//     int i= nums.size()-1;
//     while(i>0){
//         if(nums[i]>nums[int(floor((i-1)/2))]){
//              swap(nums[i],nums[int(floor((i-1)/2))]);
//         }
//         i--;
//     }
//     i=0;
//     while(i<nums.size() && 2*i+1<nums.size()&& 2*i+2 <nums.size()){
//         if(nums[i]<nums[2*i+1]){
//             swap(nums[i],nums[2*i+1]);
//         }else if(nums[i]< nums[2*i+2]){
//             swap(nums[i],nums[2*i+2]);
//         }
//         i++;
//     }
//     return nums;
// }
vector<int> minToMaxHeap(vector<int> nums) {
    int n = nums.size();
    for (int i = n/2 - 1; i >= 0; i--) {
        int largest = i;
        while (true) {
            int left = 2*largest + 1;
            int right = 2*largest + 2;
            int maxIndex = largest;

            if (left < n && nums[left] > nums[maxIndex])
                maxIndex = left;
            if (right < n && nums[right] > nums[maxIndex])
                maxIndex = right;

            if (maxIndex != largest) {
                swap(nums[largest], nums[maxIndex]);
                largest = maxIndex;
            } else {
                break;
            }
        }
    }

    return nums;
}


// int kthLargestElement(vector<int>& nums, int k) {
//     Solution heapK;
//     heapK.initializeHeap();
//     for(int i=0;i<nums.size();i++){
//         heapK.insert(nums[i]);
//     }
//     int z=nums.size()-k;
//     while(z>0){
//         heapK.extractMin();
//         z--;
//     }
//     return heapK.getMin();
// }

int kthLargestElement(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    return minHeap.top();
}
vector<int> replaceWithRank(vector<int>& arr) {
    vector<int> sol;
    vector<int> sarr=arr;
    sort(sarr.begin(),sarr.end());
    unordered_map<int,int> rank;
    int r = 1;
    for(int i=0;i<sarr.size();i++){
        if(i-1>=0 && sarr[i]==sarr[i-1]){
            continue;
        }
        rank.insert({sarr[i], r++});
    }

    for(auto x: arr){
        sol.push_back(rank[x]);
    }
    return sol;
}


int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> taskF;
    for(auto x: tasks){
        taskF[x]++;
    }
    priority_queue<int> maxHeap;


    for(auto t: taskF){
        maxHeap.push(t.second);
    }

    int t=0;

    while(!maxHeap.empty()){
        vector<int> temp;

        int cycle=n+1;

        int i=0;

        while(i<cycle && !maxHeap.empty()){

            int p=maxHeap.top();
            maxHeap.pop();

            p--;

            if(p>0){
                temp.push_back(p);
            }
            t++;

            i++;
        }

        for(auto val: temp){
            maxHeap.push(val);
        }

        if(maxHeap.empty()){
            break;
        }
        t+= cycle-i; //idle time
    }

    return t;
}

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(hand.size()%groupSize!=0){
       return false;
    }
    sort(hand.begin(), hand.end());
    map<int,int> f;
    for(auto x : hand){
        f[x]++;
    }
    auto it=f.begin();

    while(it!=f.end()){
        if(it->second==0){
            ++it;
            continue;
        }

        int start=it->first;

        int count=it->second;

        for(int i=0; i<groupSize;i++){
            if(f[start+i]<count) return false;

            f[start+i]-=count;
        }
        it++;
    }

    return true;
}



class Twitter {
private: 
map<int,vector<int>> tweet;
map<int,vector<int>> user;
int n;
public:
  Twitter() {
    n=10;
  }

  void postTweet(int userId, int tweetId) {
    tweet[userId].push_back(tweetId);
  }

  vector<int> getNewsFeed(int userId) {
    stack<int> news;
    vector<int> feed;
    for(auto x: tweet[userId]){
        news.push(x);
    }
    for(auto y: user[userId]){
        for(auto z: tweet[y]){
            news.push(z);
        }
    }
    while(!news.empty()){
        feed.push_back(news.top());
        news.pop();
    }
    return feed;
  }

  void follow(int followerId, int followeeId) {
    user[followerId].push_back(followeeId);
  } 
  void unfollow(int followerId, int followeeId) {
    for(int i=0;i<user[followerId].size();i++){
        if(followeeId==user[followerId][i]){
            user[followerId][i]=-1;
        }
    }
  } 
};

int connectSticks(vector<int>& sticks) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(auto x:sticks){
        minHeap.push(x);
    }
    int minCost=0;
    while(minHeap.size()>1){
        int d=minHeap.top();
        minHeap.pop();
        int c=minHeap.top();
        minHeap.pop();
        minCost+=(c+d);
        minHeap.push(c+d);
    }
    return minCost;
}

vector<int> topKFrequent(const vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for(auto x: nums){
        freq[x]++;
    }
    priority_queue<pair<int,int>> maxHeap;
    for(auto x: freq){
        maxHeap.push({x.second,x.first});
    }
    vector<int> topF;
    while(k>0 && !maxHeap.empty()){
        topF.push_back(maxHeap.top().second);
        maxHeap.pop();
        k--;
    }

    return topF;
}

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    for(auto x: topKFrequent(nums,2)){
        cout<<x<<" ";
    }
    return 0;
}