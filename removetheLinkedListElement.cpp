/*
Author: Md Ashik Khan
Problem: Remove Linked List Elements 
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

ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }

        while(head->val == val && head->next != NULL){
            struct ListNode* x = head;
            head = head->next;
            free(x);
        }

        if(head->val == val && head->next == NULL){
            return new ListNode();
        }

        ListNode* p = head;
        ListNode* q = head->next;
        
        while (p->next != NULL)
        {
            if(q->val == val){
                p->next = q->next;
            }else{
                p = p->next;
            }
            q = q->next;
        }
        
        return head; 
}

void displayLinkedList(ListNode *head) {

        struct ListNode* p = head;
        while(p->next != NULL){
            cout<<p->val<<endl;
            p=p->next;
        }
        cout<<p->val<<endl;
        cout<<"Finish"<<endl;

    }
    

int main(){
    ListNode *head = new ListNode(7);

    ListNode *reducedList = removeElements(head,6);
    displayLinkedList(reducedList);

}
