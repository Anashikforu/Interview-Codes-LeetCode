/*
Author: Md Ashik Khan
Problem: Remove Element
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == val  ){
                for(int j=i; j<nums.size()-1; j++){
                    nums[j] = nums[j+1];
                }
                nums.pop_back();
                i--;
            }
        }

        return nums.size();
}
 
int main(){
    vector<int> nums= {0,1,2,2,3,0,4,2};
    int val = 2;
    int mem;
    mem = removeElement(nums,val);

    cout<<"Array Member:"<<mem<<endl;

    cout<<"Sorted Square Array:"<<endl;
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<endl;
    }
    
}
