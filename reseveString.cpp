/*
Author: Md Ashik Khan
Problem: Reserve String
*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
    int start=0,end=s.size() -1;
    int carry = 0;
    if((s.size())%2 == 0 ){
        carry = 1;
    }

    char strStr,endStr;
    while ( start-carry != end )
    {
        strStr = s[start];
        endStr = s[end];

        s[start] = endStr;
        s[end] = strStr;

        start++;
        end--;
    }
    
}
 
int main(){
    vector<char> strs = {'h','e','l','l','O'};
    reverseString(strs);
    for(auto i: strs){
        cout<<i<<endl;
    }
}
