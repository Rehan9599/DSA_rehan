#include <iostream>
#include <utility>
#include <list>
#include <vector>
using namespace std;


vector<int> selectionSort(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++){
        for(int j=i; j<nums.size(); j++){
            if(nums[i]>=nums[j]){
                cout<< nums[i] << " , "<<nums[j]<< endl;
                int t= nums[j];
                nums[j]=nums[i];
                nums[i]=t;
            }
        }
    }
    return nums;
    }

vector<int> bubbleSort(vector<int>& nums) {
    for(int i=0; i<nums.size()-1; i++){
        int j=i+1;
        if(nums[i]<=nums[j]){
            cout<< nums[i] << " , "<<nums[j]<< endl;
            int t= nums[j];
            nums[j]=nums[i];
            nums[i]=t;
        }
    }
    return nums;
}

void recBubbleSort(vector<int>& nums, int n){
    if(n==1) return;
    for(int j=0; j<=n-2; j++){
        if(nums[j]>nums[j+1]){
            int t= nums[j];
            nums[j]=nums[j+1];
            nums[j+1]=t;
        }
    }
    recBubbleSort(nums,n-1);
}

vector<int> insertionSort(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int j= i;
            while(j>0 && nums[j-1]>nums[j]){
                int t= nums[j-1];
                nums[j-1]=nums[j];
                nums[j]=t;
                j--;
            }
        }
        return nums;
    }

void recInsertSort(vector<int>& nums, int j, int n){
    if(j==n) return;
     while(j>0 && nums[j-1]>nums[j]){
                int t= nums[j-1];
                nums[j-1]=nums[j];
                nums[j]=t;
                j--;
            }
            recInsertSort(nums, j+1, n);
}
void merge(vector<int>& nums, int low, int mid,  int high){
    int left=low;
    int right=mid+1;
    vector<int> temp;
     while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<= mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low; i<=high;i++){
        nums[i]=temp[i-low];
    }
}
void mergeSort(vector<int>& nums, int low , int  high){
    if (low==high){
        return ;
    } 
    int mid=(low+high)/2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);
    //merge
    merge(nums, low , mid, high);
}
int partition(vector<int>& nums, int low, int high){
    int p=nums[low];
    int i=low;
    int j=high;
    while(i<j){
        while(i<=high-1 && nums[i]>=p){
            i++;
        }
        while(j>=low+1 && nums[j]<p){
            j--;
        }
        if(i<j){
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[low],nums[j]);
    return j;
}
void quickSort(vector<int>& nums, int low, int high){
    if(low<high){
    int part= partition(nums, low,high);
    quickSort(nums, low , part-1);
    quickSort(nums, part+1 ,high);
}
}
int main(){
  vector<int> nums={7, 4,4,1,1,2,8,7,6,9,5, 3};
  quickSort(nums,0, nums.size()-1);
  for(int i=0; i<nums.size(); i++){
    cout<<nums[i]<<",";
  }
    return 0;
}