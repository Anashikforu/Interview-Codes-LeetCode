/*
Author: Md Ashik Khan
Problem: Rotate Array
*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size(),m=k;
    vector<int> firstPart;
    if(k > n){
        k = k%n;
    }
    for(int i=0; i<k; i++){
        firstPart.push_back(nums[n-i-1]);
    }
    while(n>k){
        n--;
        nums[n] = nums[n-k];
    }
    for(int i=0; i<k; i++){
        nums[i] = firstPart[i];
    }    
}
 
int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int target = 45;
    rotate(nums,target);
    for(auto i: nums){
        cout<<i<<endl;
    }
}
