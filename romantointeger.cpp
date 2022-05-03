/*
Author: Md Ashik Khan
Problem: 13. Roman to Integer
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int romanToInt(string s) {
    
    int I=1,V=5,X=10,L=50,C=100,D=500,M=1000;
    int bI = 0, bX = 0, bC =0;
    int out =0;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'I'){
            bI = 1;
            out += 1;
            
        }else if(s[i] == 'V'){
            out += 5;
            if(bI == 1){
                out = out - 2;
                bI = 0;
            }
            
        }else if(s[i] == 'X'){
            out += 10;
            if(bI == 1){
                out = out - 2;
                bI = 0;
            }
            bX =1;
            
        }else if(s[i] == 'L'){
            out += 50;
            if(bX == 1){
                out = out - 20;
                bX = 0;
            }
            
        }else if(s[i] == 'C'){
            out += 100;
            if(bX == 1){
                out = out - 20;
                bX = 0;
            }
            bC =1;
            
        }else if(s[i] == 'D'){
            out += 500;
            if(bC == 1){
                out = out - 200;
                bC = 0;
            }
            
        }else if(s[i] == 'M'){
            out += 1000;
            if(bC == 1){
                out = out - 200;
                bC = 0;
            }
            
        }
        
    }
    return out;
}

int main(){
    string str="MCMXCIV";
    int out = romanToInt(str);
    cout<<out<<endl;
}