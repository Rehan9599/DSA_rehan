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

void unionArray(vector<int>& nums1, vector<int>& nums2) {
    vector<int> unionArr;
    int count;
    for(int p=0; p<nums1.size(); p++){
        count=0;
        for(int j=0;j<unionArr.size();j++){
            if(unionArr[j]==nums1[p]){
                count=1;
                break;
            }
        }
        if(count==0){
            unionArr.push_back(nums1[p]);
        }
    }
    
    for(int j=0;j<nums2.size();j++){
        count=0;
        for(int r=0;r<unionArr.size(); r++){
            if(nums2[j]==unionArr[r]){
                count=1;
                break;
            }
        }
        if(count==0){
            unionArr.push_back(nums2[j]);
        }
    }
    bubbleSort(unionArr);
    for(auto x: unionArr){
        cout<<x <<", ";
    }
}



void  unionHash(vector<int>& nums1, vector<int>& nums2){
    int hash[10]={0};
    for(auto x: nums1){
        hash[x]=x;
    }
    for(auto y: nums2){
        hash[y]=y;
    }
    for(int i=0; i<10; i++){
        if(i>1 && hash[i]==0) continue;
        cout<<hash[i]<<',';
    }
}

void unionSet(vector<int>& nums1, vector<int>& nums2){
    set<int> hash;
    for(auto x: nums1){
        hash.insert(x);
    }
    for(auto y: nums2){
        hash.insert(y);
    }
    for(auto p:hash){
        cout<<p<<",";
    }
}


int missingNumber(vector<int>& nums) {
    int n=nums.size();
    int hash[n+1];
    for(auto x: nums){
        hash[x]=x;
    }
    int missingNum;
    for(int i=0; i<n+1; i++){
        if(hash[i]>10) missingNum=i;
    }
    for(auto y: hash){
        cout<<y<<"\n";
    }
    return missingNum;
}

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count=0;
    vector<int> store(nums.size());
    for(int i=0;i<nums.size(); i++){
        if(nums[i]==1) count++;
        else {
            store[count]=count;
            count=0;
        }
    }
    store[count]=count;
    for(int i=0;i<nums.size();i++){
        if(store[i]>0) count=i;
    }
    for(auto x: store){
        cout<<x<<',';
    }
    return count;
}


int singleNumber(vector<int>& nums){
    int cou;
    for(int i=0;i<nums.size(); i++){
        cou=0;
        for(int j=0;j<nums.size();j++){
            if(j==i) continue;
            if(nums[i]==nums[j]){
                cou++;
            }
           
        }
        if(cou==0){
            return nums[i];
        } 
    }
    return 0;
}

int longestSubarray(vector<int> &nums, int k){
    int sum=0;
    int count=0,len=0;
    for(int i=0; i<nums.size();i++){
        sum=0;
        for (int j=i; j<nums.size();j++){
            
            // for(int x=i; x<=j; x++){
            //     sum+=nums[x];
            // }
            sum+=nums[j];
            if(sum==k){
                // len=max(len,j-i+1);
                count++;
            }
        }
    }
    return count;
}
int main(){
    vector<int> nums={ 1,1,2,2,4,1,1,1,1,-3,-2,-2,5,5,-4};
    cout<< longestSubarray(nums,9);
    return 0;
}
