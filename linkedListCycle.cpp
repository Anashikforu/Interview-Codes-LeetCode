/*
Author: Md Ashik Khan
Problem: Linked List Cycle
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

bool hasCycle(ListNode *head) {

    if(head == NULL || head->next == NULL){
        return false;
    }

    ListNode *p = head;
    ListNode *q = head;

    while(p->next && p->next->next){   
        p = p->next;                                                               //Hare & Tortoize ALgorithm
        if(p == q){
            return true;
        }
        p=p->next;                                                              //This node is running with double speed
        if(p == q){
            return true;
        }
        q=q->next;                                                              //This node is running with normal Speed
    }

    return false;
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
    ListNode *head = new ListNode(3);

    head = addtoNode(head,2);
    head = addtoNode(head,0);

    ListNode *p = head;
    // ListNode *q = p->next;
    ListNode *q = new ListNode();


    while(p->next != NULL){
        p=p->next;
    }

    ListNode *ptr = new ListNode(-4,q);
    p->next = ptr;

    
    // displayLinkedList(head);

    cout<<"Condition is "<<hasCycle(head)<<endl;

}
