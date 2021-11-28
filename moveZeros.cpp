/*
Author: Md Ashik Khan
Problem: Move Zeros
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 0 && i<nums.size()-1){
            for(int j=i; j<nums.size()-1; j++){
                nums[j] = nums[j+1];
            }
            nums[nums.size()-1]  = 0;
        }
    }

    for(int i=0; i<nums.size()-1; i++){
        if(nums[i] == 0 && nums[i+1] != 0){
            moveZeroes(nums);
        }
    }
}
 
int main(){
    vector<int> nums= {1,0,0,0,0,1};
    moveZeroes(nums);
    
    cout<<"Sorted Square Array:"<<endl;
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<endl;
    }
    
}
