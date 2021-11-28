/*
Author: Md Ashik Khan
Problem: Sort Array By Parity
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    int even =0,num;
    for(int i=0; i<nums.size(); i++){
        num = nums[i];
        if(nums[i]%2 == 0 ){
            for(int j=i; j>even; j--){
                nums[j] = nums[j-1];
            }
            nums[even] = num;
            even++;
        }
    }
    return nums;
}
 
int main(){
    vector<int> nums= {1,0,0,0,1};
    vector<int> sortArr;
    sortArr = sortArrayByParity(nums);
    
    cout<<"Sorted Square Array:"<<endl;
    for(int i=0; i<sortArr.size(); i++){
        cout<<sortArr[i]<<endl;
    }
    
}
