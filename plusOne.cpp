/*
Author: Md Ashik Khan
Problem: Largest Number At Least Twice of Others
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int dig_size = digits.size()-1;
    int j = 1;
    while(j > 0){
        if(digits[dig_size] == 9){
            if(dig_size == 0){
                digits[dig_size] = 0;
                j = 0;

                digits.push_back(0);
                digits[0] = 1;
            }else{
                digits[dig_size] = 0;
                dig_size--;
            }
        }else{
            digits[dig_size] = digits[dig_size] + 1;
            j = 0;
        }
        
    }

    return digits;
}
 
int main(){
    vector<int> nums= {9};
    vector<int> largest;
    largest = plusOne(nums);

    cout<<"largest Index in an Array:"<<endl;
    for(int i=0; i<largest.size(); i++){
        cout<<largest[i]<<endl;
    }
}
