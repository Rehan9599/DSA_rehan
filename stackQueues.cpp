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
#include <string>
using namespace std;

class ArrayStack {
private:
int s;
int t;
int st[10];

public:
    ArrayStack() {
        s=10;
        t=-1;
    }
    
void push(int x){
    if(t>=s){
        return;
    }else{
        st[++t]=x;
    }
}

int pop(){
    if(t<=-1){
        return -1;
    }else{
        return st[t--];
    }
}

int top(){
    if(t>=s || t<=-1) return -1;
    return st[t];
}

bool isEmpty() {
    if(t<=-1){
        return true;
    }
    return false;
}
void display(){
    int u=0;
    while(u<=t){
        cout<<st[u++]<<" ";
    }
}
};



class ArrayQueue {
private:
int s;
int f,r;
int qu[10];
public:
    ArrayQueue() {
        s=10;
        f=r=-1;
    }
    
    void push(int x) {
        if(f>s) return;
        if(r==-1||f==-1){
            r=f=0;
            qu[f]=x;
        }else{
            qu[++f]=x;
        }  
    }
    
    int pop() {
        if(r>f) return -1;
        return qu[r++];
    }
    
    int peek() {
      if(r>f || f>=s) return -1;
      return qu[r];
    }
    
    bool isEmpty() {
        if(r>f||r==-1){
        return true;
    }
        return false;
    }
    void display(){
    int u=r;
    while(u<=f){
        cout<<qu[u++]<<" ";
    }
}
};


class QueueStack {
    private:
int s;

queue<int> qu;
public:
    QueueStack() {
        s=10;
    }
    
    void push(int x) {
        int t=qu.size();
        qu.push(x);
        for(int i=0;i<t;i++){
            qu.push(qu.front());
            qu.pop();
        }
    }
    
    int pop() {
        int popped=qu.front();
        qu.pop();
        return popped;
    }
    
    int top() {
     return qu.back();
    }
    
    bool isEmpty() {
        return qu.empty();
    }
};
class StackQueue {
    private:
int s;
stack<int> st, sts;
public:
    StackQueue() {
        s=10;
    }
    
    void push(int x) {
        int t=st.size();
        for(int i=0; i<t; i++){
            sts.push(st.top());
            st.pop();
        }
        st.push(x);
        for(int i=0; i<t; i++){
            st.push(sts.top());
            sts.pop();
        }
    }
    
    int pop() {
        int v=st.top();
        st.pop();
        return v;
    }
    
    int peek() {
        return st.top();
    }
    
    bool isEmpty() {
        return st.empty();
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
};
class LinkedListStack {
private:
    int s;
    ListNode *head;
public:
    LinkedListStack() {
        head=NULL;
        s=0;
    }
    void push(int x) {
        ListNode* node=new ListNode(x);
        if(head==NULL){
            head=node;
        }
        else{
            ListNode* n=head;
            while(n->next!=NULL){
                n=n->next;
            }
            n->next=node;
        }
    }
    
    int pop() {
        ListNode* n=head;
        while(n->next->next!=NULL){
            n=n->next;
        }
        int v= n->next->val;
        n->next=NULL;
        return v;
    }
    
    int top() {
        ListNode* n=head;
        while(n->next!=NULL){
            n=n->next;
        }
        return n->val;
    }
    
    bool isEmpty() {
        if(head==NULL) return true;
        return false;
    }
};


class LinkedListQueue {
private:
    int s;
    ListNode *head;
public:
    LinkedListQueue() {
        head=NULL;
        s=0;
    }
    void push(int x) {
        s++;
        ListNode* node=new ListNode(x);
        if(head==NULL){
            head=node;
        }
        else{
            ListNode* n=head;
            while(n->next!=NULL){
                n=n->next;
            }
            n->next=node;
        }
    }
    
    int pop() {
        if(head!=NULL){
            int v=head->val;
            s>=2?head->next=head->next->next: head->next=NULL;
            return v;
        }else{
            return 0;
        }
    }
    
    int peek() {
       return head==NULL ? 0: head->val;
    }
    
    bool isEmpty() {
        return head==NULL;
    }
};


bool isValid(string str) {
    stack<char> open;
    for(int i=0; i<str.size(); i++){
        char x=str[i];
        if(x == '(' || x== '{' || x== '['){
            open.push(x);
        }
        else{
            if(open.empty()) return false;
            char t = open.top();
            if((t=='(' && x==')') || (t=='{' && x=='}') || (t=='[' && x==']')){
                open.pop();
            }
            else{
                return false;
            }
        }
    }
    return open.empty();
}


string infixToPostfix(string s) {
    stack<char> operat;
    map<char,int> mpp={
        {'+',0}, 
        {'-',0},
        {'*',1},
        {'/',1},
        {'^',2},
    };
    string expr;
    for(char x: s){
        if(x<='z' && x>='a'){
            expr+=x;
        }else if(x=='('){
               operat.push(x); 
        }else if(x==')'){
                while(!operat.empty() && operat.top()!='('){
                    expr+=operat.top();
                    operat.pop();
                }
                if(!operat.empty()) operat.pop();
        }else{
            while(!operat.empty()&& operat.top()!='(' 
                    && (mpp[operat.top()]>mpp[x] ||
                    (mpp[operat.top()]==mpp[x] && !(x == '^'))
                )){
                expr+=operat.top();
                operat.pop();
            }
            operat.push(x);
        }
    }
    while(!operat.empty()){
        expr+=operat.top();
        operat.pop();
    }
    return expr;    
}

string prefixToInfix(string s) {
    string rs(s.rbegin(), s.rend());
    stack<string> expr;
    string result;
    for(char x:rs){
        if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'){
            string op1=expr.top();
            expr.pop();
            string op2=expr.top();
            expr.pop();
            string inf="("+op1+x+op2+")";
            expr.push(inf);
        }else{
            expr.push(string(1,x));
        }
    }
    result+=expr.top();
    return result;
}

 string prefixToPostfix(const string& s) {
    string rs(s.rbegin(), s.rend());
    stack<string> expr;
    string result;
    for(char x:rs){
        if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'){
            string op1=expr.top();
            expr.pop();
            string op2=expr.top();
            expr.pop();
            string inf=op1+op2+x;
            expr.push(inf);
        }else{
            expr.push(string(1,x));
        }
    }
    result+=expr.top();
    return result;
 }   

string postToPre(string postfix) {
    stack<string> expr;
    string result;
    for(char x:postfix){
        if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'){
            string op1=expr.top();
            expr.pop();
            string op2=expr.top();
            expr.pop();
            string inf=x+op2+op1;
            expr.push(inf);
        }else{
            expr.push(string(1,x));
        }
    }
    result+=expr.top();
    return result;
}


string postToInfix(string postExp) {
    stack<string> expr;
    string result;
    for(char x:postExp){
        if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'){
            string op1=expr.top();
            expr.pop();
            string op2=expr.top();
            expr.pop();
            string inf="("+op2+x+op1+")";
            expr.push(inf);
        }else{
            expr.push(string(1,x));
        }
    }
    result+=expr.top();
    return result;
}

string infixToPrefix(const string& s) {
    stack<char> operat;
    string rs(s.rbegin(), s.rend());
    map<char,int> mpp={
        {'+',0}, 
        {'-',0},
        {'*',1},
        {'/',1},
        {'^',2},
    };
    string expr="";
    for(char x: rs){
        if(x<='z' && x>='a'){
            expr=x+expr;
        }else if(x==')'){
               operat.push(x);
        }else if(x=='('){
                while(!operat.empty() && operat.top()!=')'){
                    expr=operat.top()+expr;
                    operat.pop();
                }
                if(!operat.empty()) operat.pop();
        }else{
            while(!operat.empty()&& operat.top()!=')' 
                    && (mpp[operat.top()]>mpp[x] ||
                    (mpp[operat.top()]==mpp[x] && !(x == '^'))
                )){
                expr=operat.top()+expr;
                operat.pop();
            }
            operat.push(x);
        }
    }
    while(!operat.empty()){
        expr=operat.top()+expr;
        operat.pop();
    }
    return expr;
}

//monotonic stack 

vector<int> nextGreaterElements(vector<int> &arr) {
    stack<int> st;
    vector<int> nge;
    for(int i =arr.size()-1; i>=0;i--){
        st.push(arr[i]);
    }
    for(int i =arr.size()-1; i>=0;i--){
        if(st.empty()){
            st.push(arr[i]);
            nge.push_back(-1);
        }else if(arr[i]<st.top()){
            nge.push_back(st.top());
            st.push(arr[i]);
        }else{
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            st.empty()? nge.push_back(-1):nge.push_back(st.top());
            st.push(arr[i]);
        }
    }
    reverse(nge.begin(), nge.end());
    return nge;
}

vector<int> nextLargerElement(vector<int> arr) {
    stack<int> st;
    vector<int> nge;
    for(int i =arr.size()-1; i>=0;i--){
            while(!st.empty() && st.top()<arr[i]){
                st.pop();
            }
            st.empty()? nge.push_back(-1):nge.push_back(st.top());
            st.push(arr[i]);
    }
    reverse(nge.begin(), nge.end());
    return nge;
}

vector<int> nextSmallerElements(const vector<int>& arr) {
    stack<int> st;
    vector<int> nge;
    for(int i =arr.size()-1; i>=0;i--){
            while(!st.empty() && st.top()>arr[i]){
                st.pop();
            }
            st.empty()? nge.push_back(-1):nge.push_back(st.top());
            st.push(arr[i]);
    }
    reverse(nge.begin(), nge.end());
    return nge;
}
vector<int> prevLargerElement(vector<int> arr) {
    stack<int> st;
    vector<int> nge;
    for(int i =arr.size()-1; i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            st.empty()? nge.push_back(-1):nge.push_back(st.top());
            st.push(arr[i]);
    }
    reverse(nge.begin(), nge.end());
    return nge;
}
vector<int> prevSmallerElements(const vector<int>& arr) {
    stack<int> st;
    vector<int> pse;
    for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            pse.push_back(st.empty() ? -1 : st.top());
            st.push(arr[i]);
    }
    return pse;
}

vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
    vector<int> ngec;
    int j=0;
    while(j<indices.size()){
      stack<int> st;
      for(int i=indices[j]+1;i<arr.size();i++){
        if(arr[i]>arr[indices[j]]){
            st.push(arr[i]);
        }
      }
      ngec.push_back(st.size());
      j++;
    }
    return ngec;
}
int trap(vector<int> &height){
    int t=0;
    for(int i =0;i<height.size();i++){
        if(height[i]<=0){
            continue;
        }else{
            for(int j=i+1;j<height.size();j++){
                if(height[j]>=height[i]){
                    t+=((j-i-1)*(height[i]));
                    for(int c=i+1;c<j;c++){
                        t-=height[c];
                    }
                    i=j-1;
                    break;
                }
            }
        }
    }
    return t;
}

int minE(vector<int>& arr){
    int m=arr[0];
    for(int i=0;i<arr.size();i++){
        if(m>arr[i]){
            m=arr[i];
        }
    }
    return m;
}
int maxE(vector<int>& arr){
    int m=arr[0];
    for(int i=0;i<arr.size();i++){
        if(m<arr[i]){
            m=arr[i];
        }
    }
    return m;
}
int sumSubarrayMins(vector<int> &arr) {
    int s=0;
    vector<vector<int>> subArrC;
    for(int i=0;i<arr.size();i++){
        for (int j=i+1;j<=arr.size();j++){
            vector<int> sac(arr.begin()+i, arr.begin()+j);
            subArrC.push_back(sac);
        }
    }
    for(auto x:subArrC){
        s+=minE(x);
    }
    return s;
}

vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            int currEle = arr[i];
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    
    vector<int> findPSEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i < n; i++) {
            int currEle = arr[i];
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
            return ans;
    }

vector<int> findNLE(vector<int> &arr){
    int n=arr.size();
    vector<int>ans(n);
    stack<int> sr;
    for(int i=n-1;i>=0;i--){
        while(!sr.empty()&& arr[sr.top()] <= arr[i]){
            sr.pop();
        }
        ans[i]= !sr.empty()? sr.top(): n;
        sr.push(i); 
    }
    return ans;
}
vector<int> findPLEE(vector<int> &arr){
    int n=arr.size();
    vector<int>ans(n);
    stack<int> sr;
    for(int i=0;i<n;i++){
        while(!sr.empty()&& arr[sr.top()] < arr[i]){
            sr.pop();
        }
        ans[i]= !sr.empty()? sr.top(): -1;
        sr.push(i); 
    }
    return ans;
}

int sumSubarrayMins1(vector<int> &arr) {
        vector<int> nse = 
            findNSE(arr);
        vector<int> psee =
            findPSEE(arr);
        int n = arr.size();
        int sum = 0;
        for(int i=0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;
            int freq = left*right; 
            int val = (freq*arr[i]);
            sum = (sum + val);
        }
        return sum;
}
int sumSubarrayMaxs1(vector<int> &arr) {
        vector<int> nle = 
            findNLE(arr);
        vector<int> plee =
            findPLEE(arr);
        int n = arr.size();
        int sum = 0;
        for(int i=0; i < n; i++) {
            int left = i - plee[i];
            int right = nle[i] - i;
            int freq = left*right; 
            int val = (freq*arr[i]);
            sum = (sum + val);
        }
        return sum;
}

vector<int> asteroidCollision(vector<int> &asteroids){
    vector<int> ans;
    stack<int> spaceship1;
    stack<int> spaceship2;
    for(int i=asteroids.size()-1;i>=0;i--){
        spaceship1.push(asteroids[i]);
    }
    while((!spaceship1.empty()&&spaceship1.size()>1)){
        int a=spaceship1.top();
        spaceship1.pop();
        int b=spaceship1.top();
        spaceship1.pop();
        cout<<a<<" "<<b<<"\n";
        if((a>0&&b>0)||(a<0&&b<0)){
            spaceship2.push(a);
            spaceship1.push(b);
        }
        else if(abs(a)>abs(b)){
            spaceship1.push(a);
            if(!spaceship2.empty()&&(spaceship1.top()<0&&spaceship2.top()>0)||spaceship1.top()>0&&spaceship2.top()<0){
                spaceship1.push(spaceship2.top());
                spaceship2.pop();
            }
        }else if(abs(a)<abs(b)){
            spaceship1.push(b);
            if(!spaceship2.empty()&&(spaceship1.top()<0&&spaceship2.top()>0)||spaceship1.top()>0&&spaceship2.top()<0){
                spaceship1.push(spaceship2.top());
                spaceship2.pop();
            }
        }else{
            continue;
        }
    }
    while(!spaceship2.empty()){
        ans.push_back(spaceship2.top());
        spaceship2.pop();
    }
    while(!spaceship1.empty()){
        ans.push_back(spaceship1.top());
        spaceship1.pop();
    }
    return ans;
}

long long subArrayRanges(vector<int> &nums) {
    int s=0;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<=nums.size();j++){
            vector<int> sac(nums.begin()+i, nums.begin()+j);
            s+=(maxE(sac)-minE(sac));
        }
    }
    return s;
}
long long subArrayRanges1(vector<int> &nums) {
    return sumSubarrayMaxs1(nums)-sumSubarrayMins1(nums);
}


string removeKdigits(string nums, int k) {
    stack<char> srt;
    string ans;
    for(int i=0;i<nums.size();i++){
        while(!srt.empty()&& k>0 && srt.top()>nums[i]){
            srt.pop();
            k--;
        }
        srt.push(nums[i]);
    }
    while(!srt.empty()){
        ans+=srt.top();
        srt.pop();
    }
    while(ans.size()>0 && ans.back()=='0'){
        ans.pop_back();   
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string nums="1002991";
    cout<<removeKdigits(nums,3);
    return 0;
}

