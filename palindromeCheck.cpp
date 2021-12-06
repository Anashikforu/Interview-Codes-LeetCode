/*
Author: Md Ashik Khan
Problem: Odd Even Linked List
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

bool isPalindrome(ListNode* head) {
    if(head->next == NULL ){
        return true;
    }

    ListNode *slow = head, *fast = head;

    //Find the middle of the linked List
    while(fast->next  && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    //Reverse the linked List
    ListNode *rev = NULL, *curr = slow->next, *temp ;
    while(curr != NULL){
        temp  = curr->next;
        curr->next  = rev;
        rev = curr;
        curr = temp;
    }

    //Check
    struct ListNode* p = head;
    struct ListNode* q = rev;
    while( p->next ){
        if(p->val != q->val){
            return false;
        }
        p=p->next;
        if(q->next == NULL){
            q=p;
        }else{
            q=q->next;
        }
    }
    

    return true;
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
    ListNode *head = new ListNode(1);
    head = addtoNode(head,0);
    head = addtoNode(head,1);
    // head = addtoNode(head,3);
    // head = addtoNode(head,3);
    // head = addtoNode(head,1);

    bool palindromeCheck = isPalindrome(head);
    cout<<palindromeCheck<<endl;

}
