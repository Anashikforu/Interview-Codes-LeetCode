/*
Author: Md Ashik Khan
Problem: Array Partition I
*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;



int arrayPairSum(vector<int>& nums) {
    int sum =0;
    int pair = nums.size()/2;

    if(nums.size() == 0){
        return sum;
    }
    
    sort(nums.begin(),nums.end());

    for(int i=0; i<pair; i++){
        sum += nums[i*2];
    }

    return sum;
}
 
int main(){
    vector<int> nums = {6,2,6,5,1,2};
    int arrPair;
    arrPair = arrayPairSum(nums);
    cout<<arrPair<<endl;
}
