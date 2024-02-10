/// @author Merna Islam
/// @date 10/02/2024.
/// @link https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    bool isPalindrome(string s){
        int idx = s.length()-1;
        for(int i = 0; i < s.length()/2; ++i){
            if(s[i] != s[idx]){
                return false;
            }
            idx--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int cnt = s.length();
        for(int i = 0; i < s.length(); ++i){
            string temp = "";
            temp += s[i];
            for(int j = i+1; j < s.length(); ++j){
                temp += s[j];
                if(isPalindrome(temp)){
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};