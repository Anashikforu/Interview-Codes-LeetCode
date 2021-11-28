/*
Author: Md Ashik Khan
Problem: Third Maximum Number
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int thirdMax(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        int first_max =-2147483648, second_max =-2147483648, third_max =-2147483648, check_3rd =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]> first_max){
                first_max = nums[i];
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]< first_max && nums[i]> second_max){
                second_max = nums[i];
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]< second_max && nums[i]>= third_max){
                third_max = nums[i];
                check_3rd = 1;
            }
        }
        
        if(check_3rd == 0){
            return first_max;
        }
        
        return third_max;
    }
 
int main(){
    vector<int> nums= {1,2,-2147483648};
    int disVal;
    disVal = thirdMax(nums);
    
    cout<<"Third max:"<<disVal<<endl;
}
