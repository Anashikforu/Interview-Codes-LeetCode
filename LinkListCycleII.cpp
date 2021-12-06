/*
Author: Md Ashik Khan
Problem: Linked List Cycle ||
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

struct ListNode *addtoNode(ListNode *head, int val){
    ListNode *ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->val = val;
    ptr->next = NULL;

    ListNode *p = head;
    while(p->next != NULL){
        p=p->next;
    }
    p->next = ptr;

    return  head;
    
}

ListNode *detectCycle(ListNode *head) {
        ListNode *p = head;
        ListNode *q = head;
        
        while(p && p->next){
            p=p->next->next;
            q=q->next;
            
            if(p == q){
                q= head;
                while(q != p){
                    p=p->next;
                    q=q->next;
                }
                return q;
            }
        }

    
        return NULL;
}

void displayLinkedList(ListNode *head) {
        cout<<"Link List"<<endl;

        struct ListNode* p = head;
        while(p->next != NULL){
            cout<<p->val<<endl;
            p=p->next;
        }
        cout<<p->val<<endl;

    }
    

int main(){
    ListNode *head = new ListNode(1);

    for (int i = 0; i < 27; i++)
    {
        head = addtoNode(head,i+2);
    }


    ListNode *p = head;
    ListNode *q = p->next;
    // ListNode *q = new ListNode();

    for (int i = 0; i < 23; i++)
    {
        p = p->next;
    }


    while(q->next != NULL){
        q=q->next;
    }

    // ListNode *ptr = new ListNode(-4,q);
    q->next = p;
    // displayLinkedList(head);

    ListNode *dtectcycl = detectCycle(head);
    // displayLinkedList(dtectcycl);
    cout<<dtectcycl->val<<endl;

}
