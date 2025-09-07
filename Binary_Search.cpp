#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
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
    // int maxi=0;
    //     for(auto x: nums){
    //         maxi=max(maxi,x);
    //     }
    //     cout<< maxi<<  "\n";
    // vector<pair<int ,int>> valueInd(maxi+1,{-1,-1});
    // for(int i=0; i<nums.size(); i++){
    //     valueInd[nums[i]]={nums[i],i};
    // }
    // for(int i=0; i<maxi; i++){
    //     if(valueInd[i+1].first!=-1){
    //         if(i==maxi) continue;
    //             valueInd[i].first=valueInd[i+1].first-1;
    //         }
    //         else{
    //             if(i==0) continue;
    //             valueInd[i].first=valueInd[i-1].first+1;
    //         }
    //     }

    // for(auto x: valueInd){
    //     cout<< x.first<< ","<< x.second<<"\n";
    // }
    // int low=0, high=valueInd.size()-1;
    // while(low<=high){
    //     int mid= (low+high)/2;
    //     if(target>valueInd[mid].first){
    //         low=mid+1;
    //     }
    //     else if(target<valueInd[mid].first){
    //     high=mid-1;
    //     }
    //     else if(target==valueInd[mid].first){
    //         return valueInd[mid].second;
    //     }
    // }
    // return -1;


 int low=0, high=nums.size()-1;
    while(low<=high){
        int mid= (low+high)/2;
        if(target==nums[mid]){
            return mid;
        }
        if(nums[high]>=nums[mid]){
             if(nums[mid]<=target && target<=nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        else if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
    }
return -1;

}



int findMin(vector<int> &nums)  {
    int low=0, high=nums.size()-1,mini=INT16_MAX;
     while(low<=high){
        int mid= (low+high)/2;
        if(nums[low]<=nums[mid]){
             mini=min(mini,nums[low]);
             low=mid+1;
        }
        else{
            mini=min(mini,nums[mid]);
            high=mid-1;
        }
    }
    return  mini;
}


int findKRotation(vector<int> &nums)  {
    int f=findMin(nums);
    for(int i=0;i<nums.size(); i++){
        if(nums[i]==f) return i;
    }
}



int singleNonDuplicate(vector<int> &nums) {
    int low=0, high=nums.size()-1;
     while(low<=high){
        int mid=(low+high)/2;
        cout<<low<<','<<mid<<","<<high<<"\n";
        if((nums.size()-1)/2 % 2==0){
             if(nums[mid]==nums[mid-1]){
            high=mid+1;
        }
        else if(nums[mid]==nums[mid+1]){
            low=mid-1;
        }
        else{
            return nums[mid];
        }
        }
        else{
            if(nums[mid]==nums[mid-1]){
            low=mid-1;
        }
        else if(nums[mid]==nums[mid+1]){
            high=mid+1;
        }
        else{
            return nums[mid];
        }
        } 
    }
    return -1;
}

int findPeakElement(vector<int> &nums) {
    int low=0, high=nums.size()-1;
    int found,count=0;
    if(high==0) return 0;
    while(low<=high){
        int mid= (low+high)/2;
        cout<<nums[low]<<nums[mid]<<nums[high]<<"\n";
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1] ){
            found=mid;
            count++;
            high=mid-1;
        }
        else{
            high=mid-1;
        }
    }
    low=0, high=nums.size()-1;
    while(low<=high){
        int mid= (low+high)/2;
        cout<<nums[low]<<nums[mid]<<nums[high]<<"\n";
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1] ){
            found=mid;
            count++;
            low=mid+1;
        }
        else{
            low=mid+1;
        }
    }

    if(count>1){
        return 1;
    } 
    else{
        return found;
    }
    
}


long long floorSqrt(long long n)  {
    long long low=1;
    long long high=n;
    long long floorSq=0;
    while(low<=high){
        long long mid=(low+high)/2;
        long long sq=mid*mid;
        cout<<low<<","<<high<<","<<mid<<","<<sq<<","<<floorSq<<"\n";
        if(sq==n) return mid;
        if(sq>n){
            high=mid-1;
        }
        else if(sq<n){
            floorSq=mid;
            low=mid+1;
        }
        
    }
    return floorSq;
}



int NthRoot(int N, int M) {
    int low=1;
    int high=M;
    while(low<=high){
        int mid=(low +high)/2;
        int midSq=1;
        for(int i=0; i<N;i++){
            midSq*=mid;
        }
        if(midSq==M) return mid;
        if(midSq>M){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}


int minimumRateToEatBananas(vector<int> nums, int h) {
    int low=0;
    int high=INT16_MIN;
    int hour=0;
    float speed=1000;
    for(int i=0; i<nums.size(); i++){
        high=max(high,nums[i]);
    }
    while(low<=high){
        float mid=(low+high)/2;
        hour=0;
        for(int i=0; i<nums.size(); i++){
            hour+=ceil((nums[i]/mid));
        }
        cout<<"\n";
        cout<<low<<","<<high<<","<<mid<<","<<hour<<"\n";
        if(hour==h){
            speed=min(speed,mid);
        }
        if(hour<h){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return speed;
}


int roseGarden(int n,vector<int> nums, int k, int m) {
    int low=INT16_MAX;
    int high=INT16_MIN;
    if(n<m*k) return -1;
    for(int i=0;i<n;i++){
        high=max(high,nums[i]);
        low=min(low,nums[i]);
    }
    int roses=INT16_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        int count=0;
        int nOfBq=0;
        for(int i=0;i<=n-1;i+=1){
            if(nums[i]<=mid){
                count++;
            }
            else{
                nOfBq+=(count/k);
                count=0;
            }
        }
        nOfBq+=(count/k);
        cout<<low<<","<<high<<","<<mid<<","<<nOfBq<<"\n";
        if(nOfBq==m){
            roses=min(mid,roses);
        }
        if(nOfBq<m){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return roses;
}

int smallestDivisor(vector<int> &nums, int limit) {
    int low=1;
    int high=INT16_MIN;
    float divisor=INT16_MAX;
    for(int i=0; i<nums.size(); i++){
        high=max(high,nums[i]);
    }
    while(low<=high){
        float mid=(low+high)/2;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=ceil(nums[i]/mid);
        }
        cout<<low<<","<<high<<","<<mid<<","<<sum<<"\n";
        if(sum<=limit){
            divisor=min(divisor,mid);
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return divisor;
}



int findKthPositive(vector<int>& nums, int k) {
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missings= nums[mid]-mid-1;
        if(missings<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return k+high+1;

}



int kthElement(vector<int> &a, vector<int>& b, int k) {

}

int main(){
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout<<kthElement(a,b,8);
    return 0;
}