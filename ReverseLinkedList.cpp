/*
Author: Md Ashik Khan
Problem: Reverse the Linked List
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

ListNode* reverseList(ListNode* head) {
        if(head == NULL|| head->next == NULL){
            cout<<"a"<<head->val<<endl;
            return head;
        }

            struct ListNode* p = reverseList(head->next);
            cout<<"b"<<head->next->val<<endl;
            head->next->next = head;
            cout<<"c"<<head->next->val<<endl;
            head->next = NULL;

            return p;
}


ListNode* reverseListNew(ListNode* head) {
            if(head == NULL|| head->next == NULL){
                return head;
            }
            
            struct ListNode* temp = head;
            struct ListNode* p = head->next;
            struct ListNode* q = head->next;
            struct ListNode* r ;
            int count = 0;

            while(p->next != NULL){
                p=p->next;
                count++;
            }

            p->next = head;
            temp->next = NULL;
            head = q;

            while(count>0){
                temp = head;
                q = head->next;
                r = p->next;
                p->next = head;
                temp->next = r;

                head = q;
                count--;
            }

            
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
    ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    // head->val = 1;
    // head->next = NULL;

    for(int i=2; i<=8; i++){
        // head = addtoNode(head,i);
    }
    // ListNode* res =  reverseList(head);
    ListNode* res =  reverseListNew(head);
    displayLinkedList(res);

}
