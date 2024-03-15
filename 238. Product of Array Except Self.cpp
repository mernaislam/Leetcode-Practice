/// @author Merna Islam
/// @date 15/03/2024.
/// @link https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1;
        int cntZeros = 0;

        for(int i = 0; i < nums.size(); ++i){
            // count number of zeros
            if(nums[i] == 0) {
                cntZeros++;
            }
            else {
                sum *= nums[i];
            }
        }

        // means that any answer will give zero
        if(cntZeros > 1){
            for(int i = 0; i < nums.size(); ++i){
                nums[i] = 0;
            }
            return nums;
        }

        // any answer will give zero except that with value zero
        if(cntZeros == 1){
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] != 0) nums[i] = 0;
                else nums[i] = sum;
            }
            return nums;
        }

        // the normal scenario with no zeros
        for(int i = 0; i < nums.size(); ++i){
            nums[i] = sum / nums[i];
        }

        return nums;

    }
};