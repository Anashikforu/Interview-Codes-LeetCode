//3 Longest Substring Without Repeating Characters
#include<string>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 1,i,j,check =0;
        for(i =1; i<s.length(); i++){
            check = 0;
           for(j =0; j<i; j++){
                if (s[i] == s[j]){
                    check = 1;
                }
           }
            if(check == 0){
                count++;
            }
        }
        return count;
    }
};
