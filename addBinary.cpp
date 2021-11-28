/*
Author: Md Ashik Khan
Problem: Add Binary
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

string addBinary(string a, string b) {
    int len = a.length();
    int dif,t=0;
    if(b.length() > a.length() ){
        len = b.length();
        dif = b.length() - a.length();
        t=1;
    }else{
        dif = a.length() - b.length();
    }
    for(int k=0; k<dif; k++){
        if(t == 1){
            a = "0"+a;
        }else{
            b = "0"+b;
        }
    }
cout<<a<<"+"<<b<<endl;
    int flag = 0;
    string res;
    for(int j=0; j<len; j++){
        res += '0';
    }
    for(int i=len-1; i>=0; i--){
        if(a[i] == b[i] && a[i] == '0' && flag == 0){
            res[i] = '0';
        }else if(a[i] == b[i] && a[i] == '0' && flag == 1){
            res[i] = '1';
            flag = 0;
        }else if(a[i] == b[i] && a[i] == '1' && flag == 0){
            res[i] = '0';
            flag = 1;
        }else if(a[i] == b[i] && a[i] == '1' && flag == 1){
            res[i] = '1';
            flag = 1;
        }else if(((b[i] == '0' && a[i] == '1') || (b[i] == '1' && a[i] == '0'))&& flag == 1){
            res[i] = '0';
            flag = 1;
        }else if(((b[i] == '0' && a[i] == '1') || (b[i] == '1' && a[i] == '0'))&& flag == 0){
            res[i] = '1';
        }
    }

    if(flag == 1){
        res = '1'+res;
    }

    return res;
}
 
int main(){
    string a = "11";
    string b = "1";
    string res = addBinary(a,b);
    cout<<res<<endl;
}
