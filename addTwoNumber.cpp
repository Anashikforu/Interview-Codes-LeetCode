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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1){ return l2;}
        if(!l2){ return l1;}

        ListNode *sum= NULL,*last= NULL;
        int carry = 0;
        int finish = 1;

        while(l1 && l2){
            ListNode *temp = NULL;
            int sumVal = l1->val + l2->val + carry;
            carry = sumVal/10;
            sumVal = sumVal%10;
            temp = l1;
            temp->val = sumVal;

            l1=l1->next;
            l2=l2->next;

            if(temp){
                if(!sum){
                    sum = last = temp;
                }else{
                    last->next = temp;
                    last = temp;
                }
            }
        }

        if(l1){
            while(l1 && carry != 0){
                int sumVal = l1->val + carry;
                carry = sumVal/10;
                sumVal = sumVal%10;
                l1->val = sumVal;

                last->next = l1;
                last = l1;

                l1 = l1->next;
            }
        }

        if(l2){
            while(l2 && carry != 0){
                int sumVal = l2->val + carry;
                carry = sumVal/10;
                sumVal = sumVal%10;
                l2->val = sumVal;

                last->next = l2;
                last = l2;

                l2 = l2->next;
            }
        }

        if(l1){
            last->next = l1;
            finish == 0;
        }
        if(l2){
            last->next = l2;
            finish == 0;
        }

        if(finish == 1 ){
            last->next = new ListNode(carry);
        }

        return sum;
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
    ListNode *headA = new ListNode(9);
    headA = addtoNode(headA,9);
    headA = addtoNode(headA,9);

    ListNode *headB = new ListNode(5);
    headB = addtoNode(headB,6);
    headB = addtoNode(headB,3);

    ListNode *sumList = addTwoNumbers(headA,headB);
    displayLinkedList(sumList);

}
