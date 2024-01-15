/// @author Merna Islam
/// @date 13/01/2024.
/// @link https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram

class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> mp;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }
        for(int i = 0; i < t.length(); i++){
            mp[t[i]]--;
        }
        int count = 0;
        for (auto i = mp.begin(); i != mp.end(); i++){
            count += abs(i->second);
        }
        return count/2;
    }
};