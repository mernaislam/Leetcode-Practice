/// @author Merna Islam
/// @date 21/01/2024.
/// @link https://leetcode.com/problems/house-robber

class Solution {
public:
    vector<int> arr;
    int dp[405][405];
    int n;

    int solve(int prev, int i){
        int &ret = dp[prev+1][i];
        if(~ret) return ret;

        if(i == n) return 0;

        int opt1 = -1;
        if(prev == -1 || i - prev > 1){
            opt1 = solve(i, i+1) + arr[i];
        }

        int opt2 = solve(prev, i+1);

        return ret = max(opt1, opt2);
    }

    int rob(vector<int>& nums) {
        this->arr = nums;
        n = nums.size();
        memset(dp, -1, sizeof dp);
        return solve(-1, 0);
    }
};