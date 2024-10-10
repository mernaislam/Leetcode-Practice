/// @author Merna Islam
/// @date 03/02/2024.
/// @link https://leetcode.com/problems/partition-array-for-maximum-sum

class Solution {
public:
    int dp[505];
    int n;

    /// recursive approach
    // int k;
    // vector<int> vec;

    // int solve(int i = 0){
    //     if(i >= n){
    //         return 0;
    //     }

    //     int &ret = dp[i];
    //     if(~ret) return ret;

    //     int maxVal = 0, ans = 0;
    //     for(int j = i; j < min(n, i+k); ++j){
    //         maxVal = max(maxVal, vec[j]);
    //         ans = max(ans, maxVal * (j - i + 1) + solve(j+1));
    //     }

    //     return ret = ans;
    // }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();

        /// recursive approach
        // memset(dp, -1, sizeof dp);
        // vec = arr;
        // this->k = k;
        // return solve();


        /// iterative approach
        memset(dp, 0, sizeof dp);
        for(int i = arr.size() - 1; i >= 0; --i){
            int maxVal = 0;
            for(int j = i; j < min(n, i+k); ++j){
                maxVal = max(maxVal, arr[j]);
                dp[i] = max(dp[i], maxVal * (j - i + 1) + dp[j + 1]);
            }
        }
        return dp[0];
    }
};