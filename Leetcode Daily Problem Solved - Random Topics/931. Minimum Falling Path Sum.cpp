/// @author Merna Islam
/// @date 19/01/2024.
/// @link https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    vector<vector<int>> arr;
    int n;
    int dp[105][105];

    int solve(int i, int j){
        // base case
        if(i == n || j == n) return 0;

        // memoization
        int &ret = dp[i][j];
        if(ret != -100000) return ret;

        int opt1 = INT_MAX;
        if(j > 0) opt1 = solve(i + 1, j - 1);

        int opt2 = solve(i + 1, j);

        int opt3 = INT_MAX;
        if(j < n - 1) opt3 = solve(i + 1, j + 1);

        return ret = min(opt1, min(opt2, opt3)) + arr[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        this->arr = matrix;
        n = matrix.size();

        for(int i = 0; i < 101; ++i)
            for(int j=0; j < 101; ++j)
                dp[i][j] = -100000;

        // try starting from each column
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, solve(0, i));
        }

        return ans;
    }
};