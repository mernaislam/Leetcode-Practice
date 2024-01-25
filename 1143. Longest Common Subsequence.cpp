/// @author Merna Islam
/// @date 25/01/2024.
/// @link https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int dp[1004][1003];
    string s1, s2;
    int solve(int i = 0, int j = 0){
        if(i == s1.length() || j == s2.length()){
            return 0;
        }

        int &ret = dp[i][j];
        if(~ret) return ret;

        int opt1 = 0;
        if(s1[i] == s2[j]) {
            opt1 = solve(i+1, j+1) + 1;
        }

        int opt2 = solve(i+1, j);
        int opt3 = solve(i, j+1);

        return ret = max(opt1, max(opt2, opt3));
    }

    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1;
        s2 = text2;

        memset(dp, -1, sizeof dp);

        return solve();
    }
};