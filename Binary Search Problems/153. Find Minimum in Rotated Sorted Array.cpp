/// 153. Find Minimum in Rotated Sorted Array
/// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
/// This algorithm depends on getting the first element in the sorted half of the array and minimize it every time with the answer.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size() - 1, mid;
        int ans = INT_MAX;

        while(l <= h){
            mid = (l+h)/2;

            // if search space is already sorted
            // then always arr[l] is the smaller no need for BS
            if(nums[l] <= nums[h]){
                ans = min(ans, nums[l]);
                return ans;
            } 

            // if left is sorted
            if(nums[l] <= nums[mid]){
                ans = min(ans, nums[l]);
                l = mid + 1;
            } else {
               ans = min(ans, nums[mid]); 
               h = mid - 1;
            }
        }
        return ans;
    }
};
