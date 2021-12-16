/*
Author: Md Ashik Khan
Problem: Odd Even Linked List
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

 struct Node {
        int val;
        Node *prev;
        Node *next;
        Node *child;

        Node() : val(0), prev(nullptr), next(nullptr), child(nullptr) {}
        Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
        Node(int x, Node *prev, Node *next, Node *child) : val(x), prev(prev), next(next), child(child) {}
 };

struct Node *addtoNode(Node *head, int val){
    Node *ptr = new Node(val);
    
    Node *p = head;
    while(p->next != NULL){
        p=p->next;
    }
    ptr->prev = p;
    ptr->next = NULL;

    p->next = ptr;

    return  head;
    
}

struct Node *addtoChild(Node *head, Node *child){
    
    Node *p = head;
    while(p->next != NULL){
        p=p->next;
    }
    p->child = child;

    return  head;
    
}



Node* flatten(Node *head) {

        struct Node* p = head;
        while(p){
            
            if(p->child != NULL){
                Node* next = p->next;
                Node* child = flatten(p->child);

                p->child = NULL;
                p->next = child;
                child->prev = p;
                while(child->next){
                    child = child->next;
                }
                child->next=next;
                if(next != NULL){
                    next->prev = child;
                    p=child;
                }
            }
            p=p->next;
        }
        return head;
    }

void displayLinkedList(Node *head) {

        struct Node* p = head;
        while(p){
            cout<<p->val<<endl;
            p=p->next;
        }
        cout<<"Finish"<<endl;

    }
    

int main(){

    Node *headA = new Node(1);
    headA = addtoNode(headA,2);
    headA = addtoNode(headA,3);

    Node *headB = new Node(7);
    headB = addtoNode(headB,8);

    headA = addtoChild(headA,headB);

    Node *headC = new Node(11);
    headC = addtoNode(headC,12);
    
    headB = addtoChild(headB,headC);

    headA = addtoNode(headA,4);
    headA = addtoNode(headA,5);
    headA = addtoNode(headA,6);

    headB = addtoNode(headB,9);
    headB = addtoNode(headB,10);

    headA = flatten(headA);
   
    displayLinkedList(headA);

}
