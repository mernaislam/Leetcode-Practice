/// @author Merna Islam
/// @date 18/01/2024.
/// @link https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int dp[50];
    int solve(int n){
        if(n == 0){
            return 1;
        }

        // memoization
        int &ret = dp[n];
        if(~ret) return ret;

        int ans = 0;

        // climb 2 steps
        if(n >= 2) ans += solve(n-2);

        // climb 1 step
        ans += solve(n-1);
        return ret = ans;
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof dp);
        return solve(n);
    }
};