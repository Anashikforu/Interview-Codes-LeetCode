/*
Author: Md Ashik Khan
Problem: Minimum Size Subarray
*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define INT_MAX 9000000

int minSubArrayLen(vector<int>& numbers, int target) {
    int sum =0;
    int ans = INT_MAX;
    int left =0;
    int n = numbers.size();
    for(int i=0; i<n; i++){
        sum = sum + numbers[i];
        while(sum  >= target){
            ans = min(ans,i+1-left);
            sum = sum - numbers[left++];
        }
    }

    return (ans != INT_MAX)?ans:0;
}
 
int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int length;
    int target = 7;
    length = minSubArrayLen(nums,target);
    cout<<length<<endl;
}
