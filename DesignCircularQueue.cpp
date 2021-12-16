/*
Author: Md Ashik Khan
Problem: Design Circular Queue
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



class MyCircularQueue {
private:
    vector<int> queue ;                             //Queue Initialization
    int q_start;                                    //A pointer to indicate the first place
    int q_end;                                    //A pointer to indicate the first place
    int len;                                        //A pointer to indicate the last place
public:
    MyCircularQueue(int k) {
        queue.resize(k);
        q_start = 0;
        q_end = 0;
        len = 0;
    }

    void seeList(){
            cout<<"List"<<endl;
        for (int i = 0; i < 3; i++)
        {
            cout<<queue[i]<<endl;
        }
            cout<<"Finish"<<endl;
        
    }
    
    bool enQueue(int value) {
        if (isFull()) {
                return false;
        }
        q_end = q_end%queue.size();
        queue[q_end] = value;
        q_end++;
        len++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
                return false;
        }
        len--;
        q_start++;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
                return -1;
        }
        
        return queue[q_start%queue.size()];
    }
    
    int Rear() {
        if (isEmpty()) {
                return -1;
        }
        if(q_end == 0 ){
            return queue[queue.size() - 1];
        }
        return queue[q_end - 1];

    }
    
    bool isEmpty() {
        return len == 0;
    }
    
    bool isFull() {
        return len == queue.size();
    }
};
    

int main(){
    MyCircularQueue q(3);
    cout << q.enQueue(1) <<endl;
    cout << q.enQueue(2) <<endl;
    cout << q.enQueue(3) <<endl;
    cout << q.enQueue(4) <<endl;
    // cout <<"isEmpty"<< q.isEmpty() <<endl;
    // cout <<"isFull"<< q.isFull() <<endl;
    cout <<"Front"<< q.Front() <<endl;
    // cout <<"Rear"<< q.Rear() <<endl;
    cout << q.deQueue() <<endl;
    cout << q.enQueue(4) <<endl;
    // cout <<"isEmpty"<< q.isEmpty() <<endl;
    // cout <<"isFull"<< q.isFull() <<endl;
    // cout <<"Rear"<< q.Rear() <<endl;
    cout <<"Front"<< q.Front() <<endl;
}
 