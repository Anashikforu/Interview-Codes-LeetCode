/*
Author: Md Ashik Khan
Problem: Valid Mountain Array
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool validMountainArray(vector<int>& arr) {
    if(arr.size() < 3){
        return false;
    }

    int max=0,maxIn=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > max){
            max = arr[i];
            maxIn = i;
        }
    }

    if(maxIn == arr.size()-1 || maxIn == 0){
        return false;
    }

    for(int i=0; i<maxIn; i++){
        if(arr[i] >= arr[i+1]){
            return false;
        }
    }

    for(int i=maxIn; i<arr.size()-1; i++){
        if(arr[i] <= arr[i+1]){
            return false;
        }
    }

    return true;
}
 
int main(){
    vector<int> nums= {0,3,2,1};
    bool exist;
    exist = validMountainArray(nums);
    
    cout<<"Mountain Array:"<<exist<<endl;
    
}
