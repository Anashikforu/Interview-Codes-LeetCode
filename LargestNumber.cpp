/*
Author: Md Ashik Khan
Problem: Largest Number
*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int getLargestValue(int num){
        int greater=0,change=0;
        int a,x,y=0,z,k=0,l;
        a= num;
        y=0;
        k=0;
        while (a > 0) {
            if(a % 10 > greater){
                greater =  a % 10 ;
                l=k;
            }
            a = a / 10; 
            k++;        
        }

        x= num;
        while (x > 0) {
            if(x%10 !=greater){
                change = x%10;
                z= y;
            }
            x = x / 10;
            y++;             
        }
        
        return num - change*pow(10, z) + greater*pow(10, z) + change*pow(10, l) - greater*pow(10, l);
}

int main(){
    vector<int> nums;
    vector<int> digitArr;
    int length;
    int digit;
    int number;
    

    cout<<"Enter the length of  Array:"<<endl;
    cin>>length;

    for(int i=0; i<length; i++){
        cin>>digit;
        digitArr.push_back(digit);
        cin>>number;
        nums.push_back(number);
    }

    
    for(int i=0; i<length; i++){
        
        nums[i] = getLargestValue(nums[i]);
    }

    cout<<"The  Array:"<<endl;
    for(int i=0; i<length; i++){
        cout<<nums[i]<<endl;
    }
    
}
