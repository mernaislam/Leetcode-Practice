/// @author Merna Islam
/// @date 02/01/2024.
/// @link https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> vec;
        sort(nums.begin(), nums.end());
        int count = 0, maxCount = 0;
        vec.resize(nums.size());
        vec[0].push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
                maxCount = max(count + 1, maxCount);
                vec[count].push_back(nums[i]);
            } else {
                count = 0;
                vec[count].push_back(nums[i]);
            }
        }
        if (maxCount == 0)
            maxCount = 1;
        vec.resize(maxCount);
        return vec;
    }
};