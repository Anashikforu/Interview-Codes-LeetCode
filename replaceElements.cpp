/*
Author: Md Ashik Khan
Problem: Replace Elements with Greatest Element on Right Side
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> replaceElements(vector<int>& arr) {
    if(arr.size() == 0){
        return arr;
    }
    int max=0;
    for(int i=0; i<arr.size()-1; i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[j] > max){
                max = arr[j];
            }
        }
        arr[i] = max;
        max=0;
    }
    arr[arr.size()-1] = -1;
    return arr;
}
 
int main(){
    vector<int> nums= {0,3,2,1};
    vector<int> repEle;
    repEle = replaceElements(nums);
    
    cout<<"Sorted Square Array:"<<endl;
    for(int i=0; i<repEle.size(); i++){
        cout<<repEle[i]<<endl;
    }
    
}
