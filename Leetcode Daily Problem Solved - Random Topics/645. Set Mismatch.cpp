/// @author Merna Islam
/// @date 22/01/2024.
/// @link https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> vec(nums.size()+1, 0);

        for(int i = 0; i < nums.size(); i++){
            vec[nums[i]]++;
        }

        int repeated, missing;
        for(int i = 1; i <= nums.size(); i++){
            if(vec[i] == 0){
                missing = i;
            }
            if(vec[i] == 2){
                repeated = i;
            }
        }
        return {repeated, missing};
    }
};