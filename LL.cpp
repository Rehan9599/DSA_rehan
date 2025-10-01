#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

struct DListNode
{
    int val;
    DListNode *next;
    DListNode *prev;
    DListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    DListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    DListNode(int data1, DListNode *next1, DListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};



void printLL(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<"-->";
        head=head->next;
    }
    cout<<"\n";
}


DListNode * deleteHead(DListNode* head) {
        head->next->prev=NULL;
        head=head->next;
        DListNode* f=head;
        DListNode* b;
        DListNode* t=head;
        while(t!=NULL){
            b=t;
            t=t->next;
        }
        while(f!=NULL){
            cout<<f->val<<"-->";
            f=f->next;
        }
        cout<<"\n";
        while(b->prev!=NULL){
            cout<<b->val<<"-->";
            b=b->prev;
        }
}

DListNode* reverseDLL(DListNode* head) {
        // Your code goes here
        DListNode* l;
        DListNode* t=head;
        while(t!=NULL){
            l=t;
            t=t->next;
        }
     DListNode* f=l;
        while(l!=NULL){
                DListNode* pr= l->prev;
                l->prev=l->next;
                l->next=pr;
            if(l->next==NULL) break;
            l=l->next;
        }
        cout<<l->val;
        while(f!=NULL){
            cout<<f->val<<"-->";
            f=f->next;
        }
}

ListNode* insertAtHead(ListNode* &head, int X) {
    ListNode* temp= new ListNode(X);
    temp->next=head;
    ListNode* t;
    t=temp;
    while(t!=NULL){
        cout<<t->val<<"-->";
        t=t->next;
    }
    cout<<"\n";
    return head;
}



ListNode* middleOfLinkedList(ListNode* head) {
    ListNode* f=head;
    int count=0;
    while(f!=NULL){
            cout<<f->val<<"-->";
            count++;
            f=f->next;
        }
    f=head;
    int mid=count/2;
    for(int i=0; i<mid;i++){
        f=f->next;
    }
    return f;
}


ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    ListNode* f=prev;
    return prev;
}

ListNode* reverseListR(ListNode* temp) {
    if(temp->next==NULL || temp==NULL) return temp;
    ListNode* newHead= reverseListR(temp->next);
    ListNode* front=temp->next;
    front->next=temp;
    temp->next=NULL;
    return newHead;
}


bool hasCycle(ListNode *head) {
    ListNode* t=head;
    // printLL(head);
    while(t!=NULL){
        ListNode* f=head;
        while(f!=t){
            if(t->next==f ){
                return true;
            }
            f=f->next;
        }
        t=t->next;
    }
    return false;
}

ListNode *findStartingPoint(ListNode *head) {
    ListNode* t=head;
    while(t!=NULL){
        ListNode* f=head;
        while(f!=t){
            if(t->next==f ){
                return t->next;
            }
            f=f->next;
        }
        t=t->next;
    }
    return NULL;
}

int findLengthOfLoop(ListNode *head) {
    ListNode* t=head;
    ListNode* y=NULL;
    while(t!=NULL){
        ListNode* f=head;
        while(f!=t){
            if(t->next==f ){
                y=f;
                break;
            }
            f=f->next;
        }
        if(y!=NULL) break;
        t=t->next;
    }

    int count=0;
    while(y!=t){
        count++;
        y=y->next;
    }
    if(count==0) return 0;
    return count+1;

}


bool isPalindrome(ListNode* head) {
    ListNode* t=head, *f=head;
    int count=0;
    while(t!=NULL){
        t=t->next;
        count++;
    }
    t=f;
    while(f!=NULL){
        int c=count;
        t=head;
        while(c>1){
            t=t->next;
            c--;
        }
        if(f->val!=t->val) return false;
        f=f->next;
        count--;
    }
    return true;
}


int main(){
    // DListNode* head=new DListNode(0);
    // DListNode* node0=new DListNode(1);
    // head->next=node0;
    // node0->prev=head;
    // DListNode* node1=new DListNode(2);
    // node0->next=node1;
    // node1->prev=node0;
    // DListNode* node2=new DListNode(3);
    // node1->next=node2;
    // node2->prev=node1;
    ListNode* head= new ListNode(2);
    ListNode* head1= new ListNode(9);
    head->next=head1;
    ListNode* head2= new ListNode(1);
    head1->next=head2;
    ListNode* head3= new ListNode(1);
    head2->next=head3;
    ListNode* head4= new ListNode(9);
    head3->next=head4;
    ListNode* head5= new ListNode(2);
    head4->next=head5;
    cout<<isPalindrome(head);
    return 0;
}