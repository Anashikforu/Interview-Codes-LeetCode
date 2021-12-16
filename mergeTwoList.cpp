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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        ListNode* mergeList = NULL,*last = NULL,*first = list1,*second = list2;

        while(first && second){
            ListNode* temp = NULL;
            if(first->val < second->val){
                temp = first;
                first = first->next;
            }else{
                temp = second;
                second = second->next;
            }

            if(temp){
                if(mergeList == NULL){
                    mergeList = last = temp;
                }else{
                    last->next = temp ;
                    last = temp;
                }
            }
        }

        if(first)
            last->next = first;
        if(second)
            last->next = second;

        return mergeList;


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
    ListNode *headA = new ListNode(1);
    headA = addtoNode(headA,2);
    headA = addtoNode(headA,4);

    ListNode *headB = new ListNode(1);
    headB = addtoNode(headB,3);
    headB = addtoNode(headB,4);

    ListNode *mergeList = mergeTwoLists(headA,headB);
    displayLinkedList(mergeList);

}
