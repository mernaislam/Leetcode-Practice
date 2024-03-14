/// @author Merna Islam
/// @date 14/03/2024.
/// @link https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:
    vector<int> nums;

    int solve(int x){
        if(x < 0) return 0;

        int l = 0, r = 0, result = 0, curr = 0;

        for(r = 0; r < nums.size(); ++r){
            curr += nums[r];

            while(curr > x){
                curr -= nums[l];
                l++;
            }
            result += r - l + 1;
        }

        return result;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        this->nums = nums;
        return solve(goal) - solve(goal - 1);
    }

};