/*
Author: Md Ashik Khan
Problem: Duplicate Zeros
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void duplicateZeros(vector<int>& arr) {

    for(int i=0; i<arr.size(); i++){
        if(arr[i] == 0 && i < arr.size()-1){
            for(int j=arr.size()-1; j>i+1; j--){
                arr[j] = arr[j-1];
            }
            arr[i+1] = 0;
            i++;
        }
    }
}

int main(){
    vector<int> nums= {1,12,0,5,2,1};
    duplicateZeros(nums);

    cout<<"Sorted Square Array:"<<endl;
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<endl;
    }
    
}
