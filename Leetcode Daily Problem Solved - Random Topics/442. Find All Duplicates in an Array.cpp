/// @author Merna Islam
/// @date 25/03/2024.
/// @link https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> vec;
        for(int i = 0; i < nums.size(); ++i){
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0){
                vec.push_back(idx + 1);
            } else {
                nums[idx] = -nums[idx];
            }
        }
        return vec;
    }
};