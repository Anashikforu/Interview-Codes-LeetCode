/*
Author: Md Ashik Khan
Problem: Rotate Linked List
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

ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        ListNode* p = head;
        ListNode* first = head,*list = NULL,*last = NULL;
        int i = 0;

        while (p)
        {
            p=p->next;
            i++;
        }

        if(k%i == 0){
            return head;
        }else{
            k = k%i;
        }
        
        int rotPor = i - k - 1;
        
        while(rotPor > 0){
            first = first->next;
            rotPor--;
        }
        list = last = first->next;
        first->next = NULL;

        while (last->next != NULL)
        {
            last=last->next;
        }
        last->next = head;

        return list;
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
    head = addtoNode(head,4);
    head = addtoNode(head,6);

    int k = 2;

    ListNode *rotateList = rotateRight(head,k);
    displayLinkedList(rotateList);

}
