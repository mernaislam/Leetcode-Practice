/// @author Merna Islam
/// @date 09/02/2024.
/// @link https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n+1, 1);
        int hash[n+1];
        for(int i = 1; i < n; ++i){
            for(int prev = 0; prev < i; ++prev){
                if(nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1){
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
        }

        int maxIdx = 0, maxVal = 0;
        for(int i = 0; i < n; ++i){
            if(maxVal < dp[i]){
                maxVal = dp[i];
                maxIdx = i;
            }
        }

        vector<int> result;
        result.push_back(nums[maxIdx]);

        while(dp[maxIdx] != 1){
            maxIdx = hash[maxIdx];
            result.push_back(nums[maxIdx]);
        }

        return result;
    }
};