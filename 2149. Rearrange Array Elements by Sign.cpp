/// @author Merna Islam
/// @date 14/02/2024.
/// @link https://leetcode.com/problems/rearrange-array-elements-by-sign/

///  Time Complexity: O(n)
///  Space Complexity: O(n)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        /// First Approach

        // vector<int> positive;
        // vector<int> negative;

        // for(int i = 0; i < nums.size(); ++i){
        //     if(nums[i] < 0){
        //         negative.push_back(nums[i]);
        //     } else {
        //         positive.push_back(nums[i]);
        //     }
        // }

        // vector<int> result;
        // for(int i = 0; i < nums.size()/2; ++i){
        //     result.push_back(positive[i]);
        //     result.push_back(negative[i]);
        // }

        // return result;


        /// optimized approach
        vector<int> result(nums.size());
        int posIdx = 0;
        int negIdx = 1;

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < 0){
                result[negIdx] = nums[i];
                negIdx += 2;
            } else {
                result[posIdx] = nums[i];
                posIdx += 2;
            }
        }
        return result;
    }
};