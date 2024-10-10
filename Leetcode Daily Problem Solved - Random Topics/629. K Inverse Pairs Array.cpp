/// @author Merna Islam
/// @date 27/01/2024.
/// @link https://leetcode.com/problems/k-inverse-pairs-array

class Solution {
public:
    long long MOD = 1e9 + 7;
    int dp[1005][1005];
    int solve(int n, int k){
        if(n == 0) return 0;
        if(k == 0) return 1;

        int &ret = dp[n][k];
        if(~ret) return ret;

        long long count = 0;

        for(int i = 0; i <= min(k, n-1); i++){
            count += solve(n-1, k-i);
        }

        return ret = count % MOD;
    }

    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof dp);
        return solve(n, k);

        /// iterative approach
//        for(int N = 1; N <= n; N++){
//            for(int K = 0; K <= k; K++){
//                if(K == 0){
//                    dp[N][K] = 1;
//                } else {
//                    for(int m = 0; m <= min(N-1, K); m++){
//                        dp[N][K] = (dp[N][K] + dp[N - 1][K - m]) % MOD;
//                    }
//                }
//            }
//        }
//        return dp[n][k];
    }
};