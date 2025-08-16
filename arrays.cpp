#include <iostream>
#include <utility>
#include <list>
#include <vector>
using namespace std;

int largestElement(vector<int>& nums) {
      for(int i=0; i<nums.size(); i++){
        int j=i+1;
        if(nums[i]>nums[j]){
          swap(nums[i], nums[j]);
        }
      }
      return nums[nums.size()-1];
}

int secondLargestElement(vector<int>& nums) {
    int secLarge=nums[0],max1=nums[0];
    for(int i=0; i<nums.size(); i++){
        if(max1<nums[i]) max1=nums[i];
    }
    int in=0;
    while(in<nums.size()){
        if(secLarge>=max1) secLarge=nums[in];
        in++;
    }
    for(int i=0; i<nums.size(); i++){
        if(max1==nums[i]) continue;
        if(secLarge<nums[i]) secLarge=nums[i];
    }
    int f=0;
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i]!=nums[i+1]) f=1;
    }
    if(f){
        return secLarge;
    }
    else{
        return -1;
    }
}



bool isSorted(vector<int>& nums){
    int c=0;
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i]>nums[i+1]) c=1;
    }
    if(!c) return true;
    else return false;
}
int main(){
    vector<int> nums={1,2,1,3,4,7};
    cout<< isSorted(nums);
    return 0;
}

