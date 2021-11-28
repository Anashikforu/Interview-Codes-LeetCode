/*
Author: Md Ashik Khan
Problem: Implement strStr()
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int strStr(string haystack, string needle) {
    int res =0 , s=0;

    if(needle.length() == 0){
        return res;
    }
    res = -1;
    if(needle.length() > haystack.length()){
        return res;
    }
    for(int i=0; i<haystack.length(); i++){
        if(haystack[i] == needle[0] ){
            for(int j=0; j<needle.length(); j++){
                if(haystack[i+j] != needle[j]){
                    s =0;
                    break;
                }else{
                    s = 1;
                }
            }
            if(s == 1){
                res = i;
                break;
            }
        }
    }

    return res;
}
 
int main(){
    string a = "mississippi";
    string b = "issip";
    int res = strStr(a,b);
    cout<<res<<endl;
}
