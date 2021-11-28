/*
Author: Md Ashik Khan
Problem: Largest Number At Least Twice of Others
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dominantIndex(vector<int>& nums) {
    int largest = -1;
    int largestNum = 0;
    if(nums.size() == 1){
        return 0;
    }
    for(int i=0; i<nums.size(); i++){
        if(nums[i] >largestNum){
            largestNum = nums[i];
            largest = i;
        }
    }

    for(int i=0; i<nums.size(); i++){
        if(largestNum / nums[i] < 2 && nums[i]  != 0  && i != largest){
            largest = -1;
        }
    }

    return largest;
}
 
int main(){
    vector<int> nums= {1};
    int largest;
    largest = dominantIndex(nums);

    cout<<"largest Index in an Array:"<<largest<<endl;
}
