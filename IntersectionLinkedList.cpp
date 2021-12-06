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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA;
        ListNode *q = headB;

        if(p== NULL || q == NULL){
            return p;
        }
        
        while(p != q){
            p = p->next;
            q = q->next;

            if(p == q){
                return p;
            }

            if(p->next == NULL){
                p = headB;
            }

            if(q->next == NULL){
                q = headA;
            }
        }
        
        return p;
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
    ListNode *headA = new ListNode(1);

    headA = addtoNode(headA,9);
    headA = addtoNode(headA,1);

    ListNode *headB = new ListNode(3);

    ListNode *cycle1 = new ListNode(2);
    ListNode *cycle2 = new ListNode(4);
    cycle1->next = cycle2;

    ListNode *p = headA;
    while(p->next != NULL){
        p=p->next;
    }
    p->next = cycle1;
    headB->next = cycle1;
    

    displayLinkedList(headA);
    displayLinkedList(headB);

    ListNode *intersectionNode = getIntersectionNode(headA,headB);

    displayLinkedList(intersectionNode);

}
