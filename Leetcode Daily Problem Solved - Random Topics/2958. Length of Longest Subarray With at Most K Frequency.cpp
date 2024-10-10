/// @author Merna Islam
/// @date 28/03/2024.
/// @link https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int longest = 0;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            mp[nums[r]]++;
            if(mp[nums[r]] > k){
                while(mp[nums[r]] > k){
                    mp[nums[l]]--;
                    l++;
                }
            }
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};