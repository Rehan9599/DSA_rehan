#include <iostream>
#include <utility>
#include <list>
#include <vector>
using namespace std;

vector<vector<int>> countFrequencies(vector<int>& nums) {
        // Your code goes here

        int hash[15]={0};
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]+=1;
        }
        vector<vector<int>> resList;
       for (int i = 0; i < 15; i++)
     {
        if(hash[i]!=0){
        resList.push_back({i,hash[i]});
        }
     }

        return resList;
 }
int mostFrequentElement(vector<int>& nums) {
        int hash[10]={0};
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]+=1;
        }
        int largest= hash[0];
        int mode;
         cout<< largest<<" " << endl;

        for(int i=0; i<10; i++){
                if(largest< hash[i]){
                    largest=hash[i];
                    cout<< i << " "<< largest <<endl;
                    mode=i;
                }
            // cout<< largest<<" " << endl;
        }
        cout<<endl;
        return mode;
    }


int main(){

vector<int> nums={3,3,4,4,4,4,4,4,2,2,3,8,8,8,8,8,8};

cout<< "   " << mostFrequentElement(nums);
//  for (const auto& num : countFrequencies(nums)){
//     for(int x : num){
//         cout<< x<< " ";
//     }
//     cout<<endl;
//  } 
    // for (int i = 0; i < 5; i++)
    // {
    //     cin>>nums[i];
    // }
    
    // int hash[5]={0};
    //     for(int i=0; i<5; i++){
    //         hash[nums[i]]+=1;
    //     }
    // list<pair<int,int>> resList;
    // for (int i = 0; i < 5; i++)
    // {
    //     if(hash[i]!=0){
    //     //   pair<int ,int> result= {i,hash[i]};
    //     resList.push_back(make_pair(i,hash[i]));
    //     }
    // }
    
    // for(const auto& item : resList){
    //     cout<< item.first << " "<< item.second << endl;
    // }
        
        // result.first=n;
        // result.second=hash[n];
        return 0;
}