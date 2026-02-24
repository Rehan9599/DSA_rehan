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
            while(k>0){
                if(heapVec[k]<heapVec[int(floor((k-1)/2))]){
                    swap(heapVec[k],heapVec[int(floor((k-1)/2))]);
                }
                k=int(floor((k-1)/2));
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
            while(k>0){
                if(heapVec[k]<heapVec[int(floor((k-1)/2))]){
                    swap(heapVec[k],heapVec[int(floor((k-1)/2))]);
                }
                k=int(floor((k-1)/2));
            }
        }

        void extractMin(){
            heapVec[0]=heapVec[i-1];
            heapVec.pop_back();
            i--;
            int k=i-1;
            while(k>0){
                if(heapVec[k]<heapVec[int(floor((k-1)/2))]){
                    swap(heapVec[k],heapVec[int(floor((k-1)/2))]);
                }
                k=int(floor((k-1)/2));
            }
            while(k<=i){
                if(heapVec[k]>heapVec[2*k+1] && 2*k+1<=i){
                    swap(heapVec[k],heapVec[2*k+1]);
                }
                k=2*k+1;
            }
        }

        bool isEmpty(){
            return heapVec.size()? false: true;
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

vector<int> minToMaxHeap(vector<int> nums) {
    int k=nums.size()-1;
    while(k>0){
        if(nums[k]>nums[int(floor((k-1)/2))]){
            cout<<nums[k]<<" "<< nums[int(floor((k-1)/2))]<<"\n";
            swap(nums[k],nums[int(floor((k-1)/2))]);
            int i=int(floor((k-1)/2));
            while(i<nums.size() && 2*i+1<nums.size()){
              if(nums[i]<nums[2*i+1]){
              swap(nums[i],nums[2*i+1]);
            }
            i++;
           }
        k--;
    }
}
    return nums;
}


int main(){
    vector<int>  nums = {-5, -4, -3, -2, -1};
    for(auto x: minToMaxHeap(nums)){
        cout<<x<<" ";
    }
    return 0;
}