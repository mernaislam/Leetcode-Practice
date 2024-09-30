/// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, h = n - 2;

        // Handle edge cases
        if (n == 1) return nums[0]; // Single element
        if (nums[0] != nums[1]) return nums[0]; // Single element at the start
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1]; // Single element at the end

        // Binary search for the single element
        while (l <= h) {
            int mid = (l + h) / 2;

            // Check if mid is the single element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // If we're in the left half (even, odd pattern)
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || 
                (mid % 2 != 0 && nums[mid] == nums[mid - 1])) {
                l = mid + 1;
            } 
            // If we're in the right half (odd, even pattern)
            else {
                h = mid - 1;
            }
        }

        return 0; // Should never reach here
    }
};
