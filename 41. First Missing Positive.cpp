/// @author Merna Islam
/// @date 26/03/2024.
/// @link https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minNumber = 1;

        for(int j = 0; j < nums.size(); j++){
            if(nums[j] < 1) continue;
            if(minNumber == nums[j]){
                minNumber = nums[j] + 1;
            }
        }

        return minNumber;
    }
};