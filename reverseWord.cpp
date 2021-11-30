/*
Author: Md Ashik Khan
Problem: Reverse Word in a string 
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string swap(string s,int start,int n){
    char temp;
    while(start < n){
        temp = s[start];
        s[start] = s[n];
        s[n] = temp;
        start++;
        n--;
    }
    return s;
}

string reverseWords(string s) {
    int start=0;

    string sspace;
    vector<string> word;

    int wordCount=0,checker=0;
    word.push_back({});

    for(int i=0; i<s.length(); i++){
        if(s[i] != ' '){
            word[wordCount] += s[i];
            checker = 1;
        }else if(s[i] == ' ' && s[i+1] != ' ' && i<s.length()-1 && checker == 1){
            wordCount++;
            word.push_back({});
        }
    }

    while(wordCount >= 1){
        sspace += word[wordCount--]+' ';
    }
    sspace += word[wordCount--];

    return sspace;
     
}

int main(){
    string s = " asdasd df f    ";
    string res = reverseWords(s);

    cout<<res<<endl;
}
