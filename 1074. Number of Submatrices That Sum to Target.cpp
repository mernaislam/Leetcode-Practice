/// @author Merna Islam
/// @date 28/01/2024.
/// @link https://leetcode.com/problems/number-of-submatrices-that-sum-to-target

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;

        for(int i = 0; i < matrix.size(); i++)
        {
            vector<int> sum(matrix[0].size(),0);
            for(int j = i; j < matrix.size(); j++)
            {
                for(int k = 0; k < matrix[0].size(); k++)
                {
                    sum[k] += matrix[j][k];
                }

                ans += subarraySum(sum, target);
            }
        }

        return ans;
    }

    int subarraySum(vector<int>& nums, int k)
    {
        int preSum[nums.size()+3];
        preSum[0] = nums[0];

        for(int i = 1; i < nums.size(); i++){
            preSum[i] = preSum[i-1] + nums[i];
        }

        unordered_map<int, int> mp;
        int count = 0;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++){

            if(mp.find(preSum[i] - k) != mp.end()){
                count += mp[preSum[i] - k];
            }

            mp[preSum[i]]++;
        }

        return count;
    }
};