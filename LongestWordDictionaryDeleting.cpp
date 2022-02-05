//Leetcode 524 
/*
Author: Md Ashik Khan
Problem: Longest Word in Dictionary through Deleting
*/

#include <iostream>
#include<vector>

using namespace std;

    int check(string y,string x) {
            int res = 0,j =0;
            for (int i = 0; i < y.length() && j < x.length(); i++){
                if (x[j] == y[i]){
                    j++;
                }
            }
        
        if(j == x.length()){
            res =1;
        }
        return res;
    }
    
    string findLongestWord(string s, vector<string>& dictionary) {
        string result = "";
        int brk=0;
        for(int i =0; i<dictionary.size(); i++){
            if (check(s,dictionary[i]) == 1){
                if( (result.length() < dictionary[i].length() || (result.length() ==  dictionary[i].length() && result > dictionary[i]))){
                    result = dictionary[i];
                }
            }
        }
        
        return result;
    }


int main()
{   
    vector<string> dictionary = {"apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"};
    string r = findLongestWord("aewfafwafjlwajflwajflwafj",dictionary);
    cout<<r<<endl;
    return 0;
}
