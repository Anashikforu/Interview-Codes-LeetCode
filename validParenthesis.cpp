/*
Author: Md Ashik Khan
Problem: 20. Valid Parentheses
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isValid(string s) {
    int len = s.length();
    char str[len] = {'\0'};
    int j =0;


    if(len%2 == 1 || len == 0){
        return false;
    }
    for(int i=0;i<len;i++){
        if(s[i] == '(' && s[i+1] == ')'){
            i++;
        }else if(s[i] == '{' && s[i+1] == '}'){
            i++;
        }else if(s[i] == '[' && s[i+1] == ']'){
            i++;
        }else if(j> 0 && (s[i] == ')' && str[j-1] == '(' ||s[i] == '}' && str[j-1] == '{'||s[i] == ']' && str[j-1] == '[')){
            j--;
            str[j] = '\0';
        }else{
            str[j] = s[i];
            j++;
        }

    }
    
    return (j>0);
}

int main(){
    string str="(([]){}]";
    cout<<isValid(str)<<endl;
}