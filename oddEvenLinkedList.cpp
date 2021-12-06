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

ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* p =  head;
        ListNode* q =  head->next;
        ListNode* r =  head->next;
        
        //Easy Way
        // while(p->next!= NULL && q->next!= NULL){
        //     p->next = q->next;
        //     p=p->next;
        //     q->next = p->next;
        //     q=q->next;
        // }

        //Efficient Way
        while(q->next!= NULL){
            p->next = q->next;

            if(p->next->next != NULL){
                p=p->next;
                q->next = p->next;
                q=p->next;
            }else{
                p=p->next;
                if(q->next == NULL){
                    q=q->next;
                }else{
                    p->next = q->next;
                    q->next = NULL;
                    p = p->next;
                }
            }
        }

        p->next = r;

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
    ListNode *head = new ListNode(1);
    head = addtoNode(head,2);
    head = addtoNode(head,3);
    head = addtoNode(head,4);
    head = addtoNode(head,5);
    head = addtoNode(head,6);
    head = addtoNode(head,7);
    head = addtoNode(head,8);

    ListNode *oeList = oddEvenList(head);
    displayLinkedList(oeList);

}
