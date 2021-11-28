/*
Author: Md Ashik Khan
Problem: Longest Common Prefix
*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string res = "";
    if(strs.size() == 0){
        return res;
    }
    string l_str= strs[0];
    int len  = strs.size() -1,s=0,flag=0;
    while(len>=0){
        if(strs[len].size() < l_str.size()){
            l_str = strs[len];
        }
        len--;
    }

    for(int j=0; j<l_str.size(); j++){
        for(int i=0; i<strs.size(); i++){
            if(strs[i][j] != l_str[j]){
                flag= 1;
                break;
            }
        }
        if(flag == 0 ){
            res += l_str[j];
        }
    }
    
    return res;
}
 
int main(){
    vector<string> strs = {"flower","flow","fligh"};
    string res = longestCommonPrefix(strs);
    cout<<res<<endl;
}
