/// @author Merna Islam
/// @date 13/02/2024.
/// @link https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

/// Space Complexity: O(1)
/// Time Complexity: O(n * max_len)
/// n = size of vector
/// max_len = maximum length of the string

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0 ; i < words.size(); ++i){
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            if(temp == words[i]){
                return words[i];
            }
        }
        return "";
    }
};