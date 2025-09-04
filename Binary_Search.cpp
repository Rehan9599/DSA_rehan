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



pair<int,int> searchRange(vector<int> &nums, int target) {
    int start=0, end=0;
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
            end=mid+1;
            start=mid-1;
            while(nums[end]==target  && end < nums.size()){
                end++;
            }
            while(nums[start]==target && start >=0){
                start--;
            }
            break;
        }
        
    }
    return {start+1,end-1};
}

int countOccurrences(vector<int>& nums, int target) {
    // int low=0, high=nums.size()-1, count=0;
    // while(low<=high){
    //     int mid= (low+high)/2;
    //     if(target>nums[mid]){
    //         low=mid+1;
    //     }
    //     else if(target<nums[mid]){
    //         high=mid-1;
    //     }
    //     else if(target==nums[mid]){
    //         count++; 
    //         nums[mid]=-1;
    //         for(int i=0; i<=mid/2;i++){
    //             swap(nums[i], nums[mid-i]);
    //         }
    //         low=0, high=nums.size()-1;
    //     }
    // }
    // return count;


   return searchRange(nums,5).second - searchRange(nums,5).first +1;
}



int searchRot(vector<int> &nums, int target) {
    int maxi=0;
        for(auto x: nums){
            maxi=max(maxi,x);
        }
        cout<< maxi<<  "\n";
    vector<pair<int ,int>> valueInd(maxi+1,{-1,-1});
    for(int i=0; i<nums.size(); i++){
        valueInd[nums[i]]={nums[i],i};
    }
    for(int i=0; i<maxi; i++){
        if(valueInd[i+1].first!=-1){
            if(i==maxi) continue;
                valueInd[i].first=valueInd[i+1].first-1;
            }
            else{
                if(i==0) continue;
                valueInd[i].first=valueInd[i-1].first+1;
            }
        }

    for(auto x: valueInd){
        cout<< x.first<< ","<< x.second<<"\n";
    }
    int low=0, high=valueInd.size()-1;
    while(low<=high){
        int mid= (low+high)/2;
        if(target>valueInd[mid].first){
            low=mid+1;
        }
        else if(target<valueInd[mid].first){
        high=mid-1;
        }
        else if(target==valueInd[mid].first){
            return valueInd[mid].second;
        }
    }
    return -1;
}


int main(){
    vector<int> nums={1,3,5};
    cout<<searchRot(nums,3);
    return 0;
}