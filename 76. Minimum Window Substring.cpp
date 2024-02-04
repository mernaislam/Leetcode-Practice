/// @author Merna Islam
/// @date 04/02/2024.
/// @link https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        if(t == "") return "";

        int m = s.length();
        int n = t.length();
        int left, right, minLen = 1e8;
        int have = 0, need;

        map<char, int> mpT;
        map<char, int> mpWindow;

        for(int i = 0; i < n; ++i){
            ++mpT[t[i]];
        }

        need = mpT.size();

        int tempL = 0;
        for(int r = 0; r < m; ++r){
            ++mpWindow[s[r]];

            if(mpT.find(s[r]) != mpT.end() && mpT[s[r]] == mpWindow[s[r]]){
                ++have;
            }

            while(have == need){
                // update the minimum length if found
                if((r - tempL + 1) < minLen){
                    left = tempL;
                    right = r;
                    minLen = (r - tempL + 1);
                }

                // shrink the window from right
                --mpWindow[s[tempL]];
                if(mpT.find(s[tempL]) != mpT.end() && mpT[s[tempL]] > mpWindow[s[tempL]]){
                    --have;
                }
                ++tempL;
            }
        }
        if(minLen == 1e8){
            return "";
        } else {
            return s.substr(left, minLen);
        }
    }
};