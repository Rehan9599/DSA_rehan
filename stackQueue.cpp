#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <stack>
using namespace std;
int tope=-1;
void push(int stack[10],int x) {
    if(tope==9) return;
    stack[++tope]=x;
}
    
int pop(int stack[10]) {
  if(tope==-1) return -1;
  return stack[tope--];
}
    
int top(int stack[10]) {
    return stack[tope];
}
    
bool isEmpty() {
  return tope==-1;
}


int first=-1,last=-1;

void enQueue(int queue[10],int x) {
  if(last=-1){
    first=0;
    last=0;
  }
  if(last>=9) return;
  queue[last++]=x;
}

bool isEmptyQ() {
  return last<first;
}

int deQueue(int queue[10]) {
  if(isEmptyQ()) return -1;
  return queue[first++];
}
    
int peek(int queue[10]) {
    return queue[first];
}
    





int main(){
    int stack[10]={-1};
    int queue[10]={-1};
    enQueue(queue,1);
    enQueue(queue,10);
    enQueue(queue,11);
    enQueue(queue,100);
    cout<<"\n"<<peek(queue);
    cout<<"\n"<<deQueue(queue);
    cout<<"\n"<<peek(queue);
    cout<<"\n"<<deQueue(queue);
    cout<<"\n"<<peek(queue);
    cout<<"\n"<<isEmptyQ();
    return 0;
}