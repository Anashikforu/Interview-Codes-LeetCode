/*
Author: Md Ashik Khan
Problem: Squares of a Sorted Array
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {

        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
     
        return nums;
}

int main(){
    vector<int> nums= {-7,6,4,10,2};
    vector<int> sortedSq;
    sortedSq = sortedSquares(nums);

    cout<<"Sorted Square Array:"<<endl;
    for(int i=0; i<sortedSq.size(); i++){
        cout<<sortedSq[i]<<endl;
    }
    
}
