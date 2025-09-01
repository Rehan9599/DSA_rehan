#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int search(vector<int> &nums, int target){
    int low=0, high=nums.size()-1;
    while(low<=high){
        int mid= (low+high)/2;
        if(target>nums[mid]){
            low=mid+1;
        }
        else if(target<nums[mid]){
            high=mid-1;
        }
        else if(target==nums[mid]){
            return mid;
        }
    }
    return -1;
}

int searchR(vector<int> &nums, int target,int low, int high){
    if(low>high) return -1;
   int mid=(low+high)/2;
   if(target>nums[mid]){
    searchR(nums,target, mid+1,high);
   }
   else if(target<nums[mid]){
    searchR(nums,target, low,mid-1);
   }
   else if(target==nums[mid]){
    return mid;
   }
}


int lowerBound(vector<int> &nums, int x){
    int low=0, high=nums.size()-1;
    int mid= (low+high)/2,ans=nums.size();
    while(low<=high){
        mid=(low+high)/2;
        cout<<low<<','<<mid<<","<<high<<"\n";
        if(nums[mid]<x){
            low=mid+1;
        }
        else if(nums[mid]>=x){
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}



int upperBound(vector<int> &nums, int x){
    int low=0, high=nums.size()-1;
    int mid= (low+high)/2,ans=nums.size();
    while(low<=high){
        mid=(low+high)/2;
        cout<<low<<','<<mid<<","<<high<<"\n";
        if(nums[mid]<x){
            low=mid+1;
        }
        else if(nums[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}



int searchInsert(vector<int> &nums, int target)  {
    int low=0, high=nums.size()-1;
    int mid= (low+high)/2;
    while(low<=high){
        mid= (low+high)/2;
        cout<<low<<','<<mid<<","<<high<<"\n";
        if(target>nums[mid]){
            low=mid+1;
        }
        else if(target<nums[mid]){
            high=mid-1;
        }
        else if(target==nums[mid]){
            return mid;
        }
    }
    return low;
}

vector<int> getFloorAndCeil(vector<int> nums, int x) {
    int low=0, high=nums.size()-1;
    int mid=(low+high)/2;
    vector<int> ans{2,0};
    while(low<=high){
        int mid=(low+high)/2;
        if(x>nums[mid]){
            low=mid+1;
        }
        else if(x<nums[mid]){
            high=mid-1;
        }
        else if(x==nums[mid]){
            ans[0]=x;
            ans[1]=x;
            return ans;
        }
    }
    ans[0]=nums[high];
    ans[1]=nums[low];
    return ans;
}



vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> range(2,-1);
    int low=0, high=nums.size()-1;
    while(low<=high){
        int mid= (low+high)/2;
        if(target>nums[mid]){
            low=mid+1;
        }
        else if(target<nums[mid]){
            high=mid-1;
        }
        else if(target==nums[mid]){
            if( mid!=low && nums[mid]==nums[low]){
                range[0]=mid-1;
                range[1]=mid;
            }
            else if(mid==low && nums[mid]!=nums[high]){
                range[0]=mid;
                range[1]=mid;
            }
            else{
                range[0]=mid;
                range[1]=mid+1;
            }
            break;
        }
    }
    return range;
}



int main(){
    vector<int> nums={2,3,4,5,5,6,7,7};
    for(auto x: searchRange(nums,7)){
        cout<<x<<",";
    } 
    return 0;
}