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

    
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
        return ;
        
    }

void displayLinkedList(ListNode *head) {
        cout<<"Link List"<<endl;

        struct ListNode* p = head;
        // while(p->next != NULL){
            cout<<p->val<<endl;
            p=p->next;
        // }
        cout<<p->val<<endl;
            p=p->next;cout<<p->val<<endl;
            p=p->next;cout<<p->val<<endl;

    }
    

int main(){
    ListNode *head = new ListNode(1);

    head = addtoNode(head,2);
    head = addtoNode(head,3);
    head = addtoNode(head,4);

    reorderList(head);

    displayLinkedList(head);


}
