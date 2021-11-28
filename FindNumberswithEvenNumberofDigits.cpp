/*
Author: Md Ashik Khan
Problem: Find Numbers with Even Number of Digits
*/

#include<iostream>
#include<vector>
using namespace std;

int findNumbers(vector<int>& nums) {
        int r=0,c=1,x=0;
        for(int i=0; i<nums.size(); i++){
            r = nums[i];

            while (r > 9){
                r = r/10;
                c++;
            }

            if( c%2 == 0 && c >0){
                cout<<c<<endl;
                x++;
            }
            c = 1;
        }
        return x;
}

int main(){
    std::vector<int> nums;
    int k,l,m;
    cout<<"Number of thye element of array:";
    cin>>k;
    cout<<"Enter the array elements: \n";
    for(int i=0; i<k; i++){
        cin>>l;
        nums.push_back(l);
    }

    m = findNumbers(nums);

    cout<<"Numbers with Even Number of Digits: "<<m<<endl;
    
}
