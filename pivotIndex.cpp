/*
Author: Md Ashik Khan
Problem: Find Pivot Index
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int pivot = -1;

    vector<int> rightSum;
    vector<int> leftSum;

    int righ_sum_val =0,left_sum_val =0;

    for(int i=0; i<nums.size(); i++){
        righ_sum_val += nums[i];
        rightSum.push_back(righ_sum_val);
    }

    for(int i=nums.size()-1; i>= 0; i--){
        left_sum_val += nums[i];
        leftSum.push_back(left_sum_val);
    }

    for(int i=1; i<nums.size(); i++){
        cout<<rightSum[i] << "==" <<leftSum[nums.size()-1-i]<<endl;
        if(rightSum[i] == leftSum[nums.size()-1-i]){
            pivot = i;
            break;
        }
    }

    if(leftSum[nums.size()-2] == 0){
        return 0;
    }

    return pivot;
}
 
int main(){
    vector<int> nums= {-1,-1,0,0,-1,-1};
    int pivot;
    pivot = pivotIndex(nums);

    cout<<"Pivot Index in an Array:"<<pivot<<endl;
}
