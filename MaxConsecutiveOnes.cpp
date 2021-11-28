/*
Author: Md Ashik Khan
Problem: Max Consecutive Ones
*/

#include<iostream>
#include<vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
        int r=0,x=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1 ){
                x += 1;
            }
            if(r<x){
                    r = x;
            }
            if(nums[i] != 1 ){
                x = 0;
            }
        }
        return r;
    }

int main(){
    std::vector<int> nums;
    int k,l,m;
    cout<<"Number of thye element of array:";
    cin>>k;
    cout<<"Enter the array elements: \n";
    for(int i=0; i<k; i++){
        cin>>l;
        nums.push_back(l);
    }

    m = findMaxConsecutiveOnes(nums);

    cout<<"Max Consecutive Ones: "<<m<<endl;
    
}
