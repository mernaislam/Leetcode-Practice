/// @author Merna Islam
/// @date 01/02/2024.
/// @link https://leetcode.com/problems/divide-array-into-arrays-with-max-difference

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result(nums.size() / 3, vector<int>(3));

        int cnt = 0;

        for(int i = 0; i < nums.size(); i += 3){
            if(i + 2 >= nums.size()){
                break;
            }
            if(nums[i + 2] - nums[i] > k){
                return vector<vector<int>>();
            } else {
                result[cnt][0] = nums[i];
                result[cnt][1] = nums[i+1];
                result[cnt][2] = nums[i+2];
                cnt++;
            }
        }
        return result;
    }
};