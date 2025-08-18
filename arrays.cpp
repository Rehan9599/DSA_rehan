#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <set>
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
void bubbleSort(vector<int>& nums) {
    for(int i=nums.size()-1; i>0; i--){
        for(int j=0; j<i;j++){
           if(nums[i]<=nums[j]){
            cout<< nums[i] << " , "<<nums[j]<< endl;
            int t= nums[j];
            nums[j]=nums[i];
            nums[i]=t;
        }
    } 
        }
}
int removeDuplicates(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums.size();j++){
            if(j==i) continue;
        if(nums[i] == nums[j]){
            cout<<nums[i]<<","<<nums[j]<< " ";
            nums.erase(nums.begin()+j);
        }
    }
    }
    bubbleSort(nums);
    cout<<endl;
    for (int i = 0; i <  nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    int size= nums.size();
    return size;
}

    int removeDuplicatesopt(vector<int>& nums) {
        int i=0;
        for (int j = 1; j < nums.size(); j++)
        {
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        cout<<endl;
        return i+1;
    }

int removeDuplicatesHash(vector<int>& arr, int n) {
  set < int > hash;
  for (int i = 0; i < n; i++) {
    hash.insert(arr[i]);
  }
  for (int x: hash) {
    cout<<x<<',';
  }
  cout<<endl;
  int k = hash.size();
  int j = 0;
  for (int x: hash) {
    arr[j++] = x;
  }
  return k;
}
void rotateArrayOp(vector<int>& nums) {
    int i=0, j=nums.size();
    int dup[j];
        dup[j-1]=nums[i];
        for(int r=1; r<j;r++){
            dup[j-r-1]=nums[j-r];
        } 
        for(int p=0; p<j;p++){
            nums[p]=dup[p];
    }   
}

void rotateArray(vector<int>& nums, int k) {
    int i=0, j=nums.size();
    int dup[j];
    while(k>0){
        dup[j-1]=nums[i];
        for(int r=1; r<j;r++){
            dup[j-r-1]=nums[j-r];
        } 
        for(int p=0; p<j;p++){
            nums[p]=dup[p];
    }
        k--;
    }
   
    // for(auto x:dup){
    //     cout<<x<<',';
    // }
    // cout<<endl;
    for(auto x:nums){
        cout<<x<<',';
    }
    
}

void rotateR(vector<int>& nums, int k) {
    int i=0, j=nums.size();
    int dup[j];
    while(k>0){
        dup[i]=nums[j-1];
        for(int r=1; r<j;r++){
            dup[r]=nums[r-1];
        }
        for(int p=0; p<j;p++){
            nums[p]=dup[p];
        }
        k--;
    }
    for(auto x:nums){
        cout<<x<<',';
    }  
}



void moveZeroesWithoutOrder(vector<int>& nums) {
    int j=nums.size();
  for(int i=0; i<nums.size(); i++){
    if(nums[i]==0){
        if(nums[j-1]==0) j--;
        cout<<nums[i]<<","<<nums[j-1] <<' ';
        if(i<j){
        swap(nums[i],nums[j-1]);
        j--;
    }
    }
  }
}

void moveZeroes(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                for(int j=i; j<nums.size();j++){
                    if(nums[j]!=0){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }
    }


int linearSearch(vector<int>& nums, int target) {
    int i,found=0;
        for(i=0; i<nums.size();i++){
            if(nums[i]==target){
                found=1;
                break;
            }
        }
        if(!found) return -1;
        else  return i;
    }

vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    vector<int> unionArr={0,0,0,0,0,0};
    int i=0;
    for(auto x : nums1){
        unionArr[i]=x;
        i++;
    }
    return unionArr;
}


int main(){
    vector<int> nums1={0, 1, 4, 0, 5, 2};
    vector<int> nums2={ 3, 7, 12};
    
    for(auto x:unionArray(nums1,nums2)){
        cout<<x<<", ";
    }
    return 0;
}

