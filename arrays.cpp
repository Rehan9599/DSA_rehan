#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
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

void twoSum(vector<int>& nums, int target,int i) {
    // vector<int> result;
// for(int i=0;i<nums.size();i++){
//     for(int j=i+1;j<nums.size();j++){
//         if(nums[i]+nums[j]==target){
//             result.push_back(i);
//             result.push_back(j);
//         }
//     }
// }
if(i==nums.size()-1) return;
for(int j=i;j<nums.size();j++){
        if(nums[i]+nums[j]==target){
            cout<<i<<j;
            return;
        }
}
twoSum(nums,target,i++);
}


void sortZeroOneTwo(vector<int>& nums) {
    // int i=0,j=0,k=0;
    // for(auto x: nums){
    //     if(x==0) i++;
    //     else if(x==1) j++;
    //     else if(x==2)k++;
    // }
    // for(int p=0;p<i;p++){
    //     nums[p]=0;
    // }
    // for(int p=i;p<i+j;p++){
    //     nums[p]=1;
    // }
    // for(int p=i+j;p<i+j+k;p++){
    //     nums[p]=2;
    // }

 // Dutch National flag algorithm. 

    int low=0,mid=0,high=nums.size()-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            mid++;
            low++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }

}

int majorityElement(vector<int>& nums) {
    // vector<int> hash(nums.size(),0);
    // for(auto x: nums){
    //     hash[x]++;
    // }
    // for(int i=0;i<hash.size();i++){
    //     if(hash[i]>=nums.size()/2) return i;
    // }

//Moore’s Voting Algorithm:
    int count=0, element;
    for(int i=0; i<nums.size(); i++){
        if(count==0) {
            count=1;
            element=nums[i];
        }
        else if(nums[i]==element){
            count++;
        }
        else{
            count--;
        }
        
    }
    return element;
}


int maxSubArray(vector<int>& nums) {
    // int j, sum,largest=INT8_MIN;
    // for(int i=0;i<nums.size();i++){
    //     sum=0;
    //     for(j=i; j<nums.size(); j++){
    //         sum+=nums[j];
    //         // for(int p=i; p<=j; p++){
    //         //     sum+=nums[p];
    //         // }  
    //          largest=max(sum,largest); 
    //     }
        
    // }
    // return largest;

    //A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.

    int maxi=INT16_MIN, sum=0;
    int start=0,end=-1,ansStart=-1;
    for(int i=0;i<nums.size();i++){
        if(sum==0) start=i;
        sum+=nums[i];
        if(sum>maxi){
            maxi=sum;
            end=i;
            ansStart=start;
        }
        if(sum<=0) {
            sum=0;
        }
    }
    cout<<ansStart<<end<<"\n";
    for(int i=ansStart;i<=end;i++){
        cout<<nums[i]<<",";
    }
    cout<<"\n";
    return maxi;
}


int stockBuySell(vector<int> arr, int n){
    int minPrice=INT16_MAX, profit=0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1; j<n;j++){
    //         profit=max(profit, arr[j]-arr[i]);
    //     }
    // }
    // return profit;

    for(int i=0;i<n;i++){
        minPrice=min(minPrice,arr[i]);
        profit=max(profit,arr[i]-minPrice);
    }
    return profit;
}


vector<int> rearrangeArray(vector<int>& nums) {
vector<int> arr(nums.size(),0);
int pos=0,neg=1;
for(int i=0;i<nums.size();i++){
    if(pos>nums.size()&& neg>nums.size()) break;
    if(nums[i]>0){
        arr[pos]=nums[i];
        pos+=2;
    }
    else{
        arr[neg]=nums[i];
        neg+=2;
    }
}
for(auto x: arr){
        cout<<x<<",";
    }
return arr;
}



void nextPermutation(vector<int>& nums) {
    int breakPoint=-1;
    for(int i=nums.size()-2;i>=0;i--){
        if(nums[i]<nums[i+1]) breakPoint=i;
        break;
    }

    if(breakPoint==-1){
        reverse(nums.begin(), nums.end());
    }
    else{
        for(int i=nums.size()-1; i>=breakPoint;i--){
            if(nums[i]>nums[breakPoint]){
                swap(nums[i],nums[breakPoint]);
                break;
            } 
        }
        reverse(nums.begin()+breakPoint+1, nums.end());
    }
    for(auto x: nums){
        cout<<x<<",";
    }

}



vector<int> leaders(vector<int>& nums) {
vector<int> leads={nums[nums.size()-1]};
// int isLead;
// for(int j=0;j<nums.size();j++){
//     for(int i=j+1;i<nums.size();i++){
//         isLead=0;
//         if(nums[i]>nums[j]) break;
//         else{
//             isLead=1;
//         }
//     }
//     if(isLead){
        
//         leads.push_back(nums[j]);
//     }
// }
// if(leads[leads.size()-1] != nums[nums.size()-1]){
//     leads.push_back(nums[nums.size()-1]);
// }

for(int i=nums.size()-2; i>=0;i--){
    if(nums[i]>nums[i+1]) leads.push_back(nums[i]);
}
reverse(leads.begin(), leads.end());
return leads;
}

int main(){
    vector<int> nums={-3, 4, 5, 1, -4, -5};
    for(auto x: leaders(nums)){
        cout<<x;
    }
    
    cout<<"\n";
    return 0;
}
