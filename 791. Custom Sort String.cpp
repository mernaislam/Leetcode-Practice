/// @author Merna Islam
/// @date 11/03/2024.
/// @link https://leetcode.com/problems/custom-sort-string/

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<int, int> mp;
        unordered_map<int, int> mpOrder;
        for(int i = 0; i < s.length(); ++i){
            mp[s[i]]++;
        }
        for(int i = 0; i < order.length(); ++i){
            mpOrder[order[i]] = 1;
        }

        string common = "";
        string uncommon = "";
        for(int i = 0; i < order.length(); ++i){
            if(mp[order[i]] > 0){
                while(mp[order[i]]--)
                    common += order[i];
            }
        }

        for(int i = 0; i < s.length(); ++i){
            if(mpOrder[s[i]] != 1){
                uncommon += s[i];
            }
        }

        return common + uncommon;

    }
};