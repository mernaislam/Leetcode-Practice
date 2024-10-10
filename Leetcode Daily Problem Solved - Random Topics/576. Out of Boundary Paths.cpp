/// @author Merna Islam
/// @date 26/01/2024.
/// @link https://leetcode.com/problems/out-of-boundary-paths

class Solution {
public:
    int m, n;
    int dp[55][55][55];
    long long MOD = 1e9 + 7;

    int solve(int row, int col, int moves){
        // base case
        if((row < 0 || row >= m || col < 0 || col >= n) && moves >= 0){
            return 1;
        }
        if(moves <= 0){
            return 0;
        }

        // memoization
        int &ret = dp[row][col][moves];
        if(~ret) return ret;

        long long ans = 0;

        // move up
        ans += solve(row - 1, col, moves - 1);

        // move down
        ans += solve(row + 1, col, moves - 1);

        // move left
        ans += solve(row, col - 1, moves - 1);

        // move right
        ans += solve(row, col + 1, moves - 1);

        return ret = ans % MOD;
    }


    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        memset(dp, -1, sizeof dp);
        return solve(startRow, startColumn, maxMove);
    }
};