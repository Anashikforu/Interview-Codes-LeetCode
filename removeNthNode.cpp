/*
Author: Md Ashik Khan
Problem: Remove Nth Node ||
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL ||(head->next == NULL && n > 1)){
        return head;
    }
    
    ListNode* x = head;
    ListNode* p = head;
    ListNode* q = head->next;

    int size=1;

    while(x->next != NULL){
        x=x->next;
        size++;
    }

    int i=size-n;

    if(i == 0){
        p = p->next; 
        head = p;
    }

    while(i>1){
        p=p->next;
        q=q->next;
        i--;
    }
    p->next = q->next; 
    
    return head;
        
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

    for (int i = 0; i < 4; i++)
    {
        head = addtoNode(head,i+2);
    }

    ListNode *reducedNode = removeNthFromEnd(head,2);
    displayLinkedList(reducedNode);

}
