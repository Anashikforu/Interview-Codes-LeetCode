/*
Author: Md Ashik Khan
Problem: Design Linked List
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class MyLinkedList {
public:
    struct Node {
        int data;
        struct Node* next;
    };

    struct Node* head;
    int size ;
    MyLinkedList() {
        head = (struct Node*)malloc(sizeof(struct Node));
        size = 0;
    }
    
    int get(int index) {
        if(index<size){
        struct Node* p = head;
        int i=0;
        while(i < index){
            p=p->next;
            i++;
        }
        return p->data;
        }else{
            return -1;
        }
    }

    void displayLinkedList() {
        cout<<"Link List"<<endl;

        struct Node* p = head;
        while(p->next != NULL){
            cout<<p->data<<endl;
            p=p->next;
        }
        cout<<p->data<<endl;

    }
    
    void addAtHead(int val) {
        if(size == 0){
            head->data = val;
            head->next = NULL;
            size++;
        }else{
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = val;

        temp->next = head;

        head = temp;
        size++;
        }
    }
    
    void addAtTail(int val) {
        if(size == 0){
           addAtHead(val);
        }else{
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = val;
        temp->next = NULL;

        struct Node* p = head;
        while(p->next != NULL){
            p=p->next;
        }
        p->next = temp;
        size++;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(size == 0 && index == 0 || index == 0){
            addAtHead(val);
        }else if(index < size){
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = val;

        int i =0;
        struct Node* p = head;
        while(i < index-1){
            p=p->next;
            i++;
        }
        temp->next = p->next;
        p->next = temp;
        size++;
        }else if(index == size){
            addAtTail(val);
        }
    }
    
    void deleteAtIndex(int index) {
        if((size ==  0 && index >= size)|| index >= size){
            return ;
        }else if(index ==  0 && size > 0 ){
            struct Node* p = head;
            head = head->next;
            free(p);
            size--;
        }else{
            struct Node* p = head;
            struct Node* q = head->next;
            for (int i = 0; i < index-1; i++)
            {
                p = p->next;
                q = q->next;
            }
            p->next =  q->next;
            free(q);
            size--;
        }
    }
};

int main(){
    MyLinkedList* obj = new MyLinkedList();
    
//test
obj->addAtHead(1);
obj->addAtTail(3);
obj->addAtIndex(3,2);


//test
    // obj->addAtHead(1);
    // obj->addAtTail(3);
    // obj->addAtIndex(1,2);
    // obj->displayLinkedList();

    // int param_1 = obj->get(1);
    // cout<<param_1<<endl;
    // obj->deleteAtIndex(1);
    // param_1 = obj->get(1);
    // cout<<param_1<<endl;

//test
    // obj->addAtIndex(0,10);
    // obj->addAtIndex(0,20);
    // obj->addAtIndex(1,30);    
    // int param_1 = obj->get(1);
    // cout<<param_1<<endl;
    // int param_1 = obj->get(0);
    // cout<<param_1<<endl;
    // obj->displayLinkedList();
    // obj->deleteAtIndex(0);

//test
    // obj->addAtIndex(3,0);
    // obj->deleteAtIndex(2);
    
    // int param_1 = obj->get(4);
    // obj->addAtHead(4);
    // cout<<param_1<<endl;
    // obj->addAtIndex(5,0);
    // obj->addAtHead(6);
    // obj->displayLinkedList();
    // int param_2 = obj->get(1);
    // cout<<param_2<<endl;

}
