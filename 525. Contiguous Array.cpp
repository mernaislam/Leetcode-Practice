/// @author Merna Islam
/// @date 16/03/2024.
/// @link https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0;
        int sum = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i] == 0 ? -1 : 1;
            int len;

            if (sum == 0) {
                len = i + 1;
                maxLen = max(maxLen, len);
            } else if (mp.count(sum) != 0) {
                len = i - mp[sum];
                maxLen = max(maxLen, len);
            } else {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};