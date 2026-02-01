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
public:
    LinkedListQueue() {
    }
    
    void push(int x) {
   
    }
    
    int pop() {
  
    }
    
    int peek() {
    
    }
    
    bool isEmpty() {
  
    }
};

int main(){
LinkedListStack stack =  LinkedListStack();

stack.push(3);

stack.push(7);

cout<<stack.pop(); // returns 7

cout<<stack.top(); // returns 3

cout<<stack.isEmpty(); // returns false 
    return 0;
}