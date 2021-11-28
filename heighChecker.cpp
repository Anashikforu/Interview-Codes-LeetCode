/*
Author: Md Ashik Khan
Problem: Height Checker
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int heightChecker(vector<int>& heights) {
    int val=0;
    vector<int> nums= heights;
    sort(nums.begin(),nums.end());
    for(int i=0; i<heights.size(); i++){
        if(heights[i] != nums[i]){
            val++;
        }
    }
    return val;
}
 
int main(){
    vector<int> nums= {5,1,2,3,4};
    int disVal;
    disVal = heightChecker(nums);
    
    cout<<"Sorted Square Array:"<<disVal<<endl;
}
