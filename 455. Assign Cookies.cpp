/// @author Merna Islam
/// @date 01/01/2024.
/// @link https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        int j = 0, i = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i != s.size() && j != g.size()){
            if(g[j] <= s[i]){
                count++;
                i++;
                j++;
            } else {
                i++;
            }
        }
        return count;
    }
};
