/*
Author: Md Ashik Khan
Problem: Two Sum II
*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> sum;
    for(int i=0; i<numbers.size(); i++){
        if(sum.size() == 2){
            break;
        }
        if(numbers[i] <= target && (i>0? numbers[i] != numbers[i-1]: 1)){
            for(int j=i+1; j<numbers.size(); j++){
                if( numbers[i] + numbers[j] == target ){
                    sum.push_back(i+1);
                    sum.push_back(j+1);
                    break;
                }
            }
        }
    }
    

    return sum;
}
 
int main(){
    vector<int> nums = {2,3,4};
    vector<int> sum;
    int target = 6;
    sum = twoSum(nums,target);
    for(auto i: sum){
        cout<<i<<endl;
    }
}
