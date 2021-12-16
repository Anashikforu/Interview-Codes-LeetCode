/*
Author: Md Ashik Khan
Problem: tWO sUM
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        int x = 0,y =  0; 
        for(x = 0; x<nums.size(); x++){
            for(y = x+1; y<nums.size(); y++){
                if(nums[x] + nums[y] == target){
                    return {x,y};
                }
            }
        }
        return {x,y};
    }

int main() {
    vector<int> input = {2,7,11,15};
    int target = 9;

    vector<int> result = twoSum(input,target);

    for(auto i: result){
        cout<<i<<endl;
    }

    return 0;
}