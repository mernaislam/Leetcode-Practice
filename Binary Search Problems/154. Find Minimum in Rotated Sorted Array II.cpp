/// 154. Find Minimum in Rotated Sorted Array II
/// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii
/// It is the same as the first version of the problem except adding the edge case handling which shrink the search space if the three elements are equal (low, mid, high)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size() - 1, mid;
        int ans = INT_MAX;

        while(l <= h){
            mid = (l+h)/2;

            // edge case
            if(nums[l] == nums[mid] && nums[mid] == nums[h]){
                ans = min(ans, nums[l]);
                l++;
                h--;
                continue;
            }

            // left is sorted
            if(nums[l] <= nums[mid]){
                ans = min(ans, nums[l]);
                l = mid + 1;
            }
            // right is sorted 
            else {
                ans = min(ans, nums[mid]);
                h = mid - 1;
            }
        }
        return ans;
    }
};
