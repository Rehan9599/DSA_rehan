#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <stack>
#include <queue>
#include <map>
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
            if(open.top()+x=='('+')'||'{'+'}'||'['+']'){
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
                while(operat.top()!='(' && !operat.empty()){
                    expr+=operat.top();
                    operat.pop();
                }
                operat.pop();
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


int main(){
cout<<infixToPostfix("a+b*(c^d-e)^(f+g*h)-i");
    return 0;
}

