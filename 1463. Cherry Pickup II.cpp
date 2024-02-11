/// @author Merna Islam
/// @date 11/02/2024.
/// @link https://leetcode.com/problems/cherry-pickup-ii/

class Solution {
public:
    int rows, cols;
    int dp[71][71][71];
    int solve(int i, int c1, int c2, vector<vector<int>>& vec)
    {
        if(c1 < 0 || c2 < 0 || c1 >= cols || c2 >= cols) return 0;

        if(i == rows){
            return 0;
        }

        int &ret = dp[i][c1][c2];
        if(~ret) return ret;

        int result = 0;
        result += vec[i][c1];
        result += vec[i][c2];

        int mx = 0;
        for(int x = c1 - 1; x <= c1 + 1; ++x){
            for(int y = c2 - 1; y <= c2 + 1; ++y){
                if(x < y){
                    mx = max(mx, solve(i+1, x, y, vec));
                }
            }
        }

        result += mx;
        return ret = result;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        rows = grid.size();
        cols = grid[0].size();
        return solve(0, 0, cols - 1, grid);
    }
};