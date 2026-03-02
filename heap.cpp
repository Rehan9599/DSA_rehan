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
int main(){
    vector<int>  nums = {1, 5, 8, 15, 8, 25, 9};
    for(auto x: replaceWithRank(nums)){
        cout<<x<<" ";
    }
    return 0;
}