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


ListNode* oddEvenList(ListNode* head) {
    ListNode* Oh=head, *Ot=head, *Eh=head->next, *Et=head->next;
    while(Et!=NULL && Et->next!=NULL){
        Ot->next=Ot->next->next;
        Ot=Ot->next;
        Et->next=Et->next->next;
        Et=Et->next;
    }
    Ot->next=Eh;
    printLL(Oh);
    return Oh;
}


ListNode* removeNthFromEnd(ListNode* head, int n) {
    int c=0;
    ListNode* f=head;
    while(f!=NULL){
        c++;
        f=f->next;
    }
    f=head;
    int m=c-n-1;
    while(m>0){
        f=f->next;
        m--;
    }
    if(m<0){
        head=head->next;
        printLL(head);
        return head;
    }
    f->next=f->next->next;
    printLL(head);
    return head;
}

ListNode* deleteMiddle(ListNode* head) {
     int c=0;
    ListNode* f=head;
    while(f!=NULL){
        c++;
        f=f->next;
    }
    f=head;
    int m=c/2-1;
    while(m>0){
        f=f->next;
        m--;
    }
    f->next=f->next->next;
    return head;
}


ListNode* sortList(ListNode* head) {
    ListNode *f=head, *t=head;
    while(f!=NULL){
        t=head;
        while(t!=NULL){
            if(f->val<t->val){
                swap(f->val,t->val);
            }
            t=t->next;
        }
        f=f->next;
    }
    return head;
}


ListNode *sortList012(ListNode *head) {
    ListNode* f=head;
    // int c0=0,c1=0,c2=0;
    // while(f!=NULL){
    //     if(f->val==0) c0++;
    //     if(f->val==1) c1++;
    //     if(f->val==2) c2++;
    //     f=f->next;
    // }
    // f=head;
    // while(c0>0){
    //     f->val=0;
    //     f=f->next;
    //     c0--;
    // }
    // while(c1>0){
    //     f->val=1;
    //     f=f->next;
    //     c1--;
    // }
    // while(c2>0){
    //     f->val=2;
    //     f=f->next;
    //     c2--;
    // }
    // printLL(head);
    ListNode zhDummy(-1), ohDummy(-1), thDummy(-1);
    ListNode *zh = &zhDummy, *zt = zh, *oh = &ohDummy, *ot = oh, *th = &thDummy, *tt = th;
    while(f!=NULL){
        if(f->val==0){
            zt->next=f;
            zt=f;
        }
        else if(f->val==1){
            ot->next=f;
            ot=f;
        }
        else{
            tt->next=f;
            tt=f;
        }
        f=f->next;
    }
    zt->next=(oh->next)?oh->next:th->next;
    ot->next=(th->next)?th->next:NULL;
    tt->next=NULL;
    printLL(zh->next);
    return zt;
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
    ListNode* head= new ListNode(1);
    ListNode* head1= new ListNode(0);
    head->next=head1;
    ListNode* head2= new ListNode(2);
    head1->next=head2;
    ListNode* head3= new ListNode(0);
    head2->next=head3;
    ListNode* head4= new ListNode(1);
    head3->next=head4;
    // ListNode* head5= new ListNode(0);
    // head4->next=head5;
    cout<<sortList012(head);
    return 0;
}