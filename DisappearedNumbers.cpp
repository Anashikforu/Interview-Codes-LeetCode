/*
Author: Md Ashik Khan
Problem: Find All Numbers Disappeared in an Array
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// vector<int> findDisappearedNumbers(vector<int>& nums) {
//     vector<int> disappr;
//     int arrSize = nums.size(),appear = 0;
//     for(int i=1; i<=nums.size(); i++){
//         for(int j=0; j<nums.size(); j++){
//             if(i == nums[j]){
//                 appear = 1;
//             }
//         }
//         if(appear == 0){
//             disappr.push_back(i);
//         }
//          appear = 1;
//     }
//     return disappr;
// }

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> disappr;
    vector<int> record(nums.size()+1,0);
    for(int i=0; i<nums.size(); i++){
        record[nums[i]] = 1;
    }
    for(int i=1; i<record.size(); i++){
        if(record[i] == 0){
            disappr.push_back(i);
        }
    }
    return disappr;
}
 
int main(){
    vector<int> nums= {4,3,2,7,8,2,3,1};
    vector<int> disappr;
    disappr = findDisappearedNumbers(nums);
    
    cout<<"Numbers Disappeared in an Array:"<<endl;
    for(int i=0; i<disappr.size(); i++){
        cout<<disappr[i]<<endl;
    }
}
