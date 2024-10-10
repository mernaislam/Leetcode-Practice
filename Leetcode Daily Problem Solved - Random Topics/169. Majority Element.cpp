/// @author Merna Islam
/// @date 12/02/2024.
/// @link https://leetcode.com/problems/majority-element/

/// Time complexity: O(n)
/// Space complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size()/2;
        int element = nums[0];
        int cnt = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == element){
                ++cnt;
            } else {
                element = nums[i];
                cnt = 1;
            }
            if(cnt > n){
                break;
            }
        }
        return element;
    }
};