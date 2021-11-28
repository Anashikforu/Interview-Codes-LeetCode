/*
Author: Md Ashik Khan
Problem: Remove Duplicates from Sorted Array
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0){
        return 0;
    }
    int mem=1;
    int tIndex=1;
    int init = nums[0];
    for(int i=1; i<nums.size(); i++){
        if(nums[i] != init){
            mem++;
            init = nums[i];
            nums[tIndex] = nums[i];
            tIndex++;
        }
    }

    return mem;
}
 
int main(){
    vector<int> nums= {1,1,2};
    int mem;
    mem = removeDuplicates(nums);

    cout<<"Sorted Square Array:"<<mem<<endl;
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<endl;
    }
    
}
