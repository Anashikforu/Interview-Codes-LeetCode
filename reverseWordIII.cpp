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
    int n= s.length()-1;
    string srev = swap(s,start,n);

    string sspace;
    vector<string> word;

    int wordCount=0,checker=0;
    word.push_back({});

    for(int i=0; i<srev.length(); i++){
        if(srev[i] != ' '){
            word[wordCount] += srev[i];
            checker = 1;
        }else if(srev[i] == ' ' && srev[i+1] != ' ' && i<srev.length()-1 && checker == 1){
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
    string s = "Let's take LeetCode contest";
    string res = reverseWords(s);

    cout<<res<<endl;
}
