/*
Author: Md Ashik Khan
Problem: Check If N and Its Double Exist
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool checkIfExist(vector<int>& arr) {

    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i] == 2*arr[j] || 2*arr[i] == arr[j]){
                return true;
            }
        }
    }

    return false;
}
 
int main(){
    vector<int> nums= {-2,0,10,-19,4,6,-8};
    bool exist;
    exist = checkIfExist(nums);
    
    cout<<"If N and Its Double Exist:"<<exist<<endl;
    
}
