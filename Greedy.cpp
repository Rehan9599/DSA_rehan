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
#include <unordered_map>
#include <string>
using namespace std;


int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
    sort(Cookie.begin(), Cookie.end());
    sort(Student.begin(),Student.end());

    int l=0,r=0;
    while(l<Cookie.size() && r<Student.size()){
        if(Cookie[l]>=Student[r]){
            r++;
        }
        l++;
    }
    return r;
}

double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        // Your code goes here
    }


int main(){
    vector<int> student={1,2};
    vector<int> cookie={1,2,3};
    cout<<findMaximumCookieStudents(student,cookie);
    return 0;
}