/// https://leetcode.com/problems/search-in-rotated-sorted-array
/// This problem is dependent on checking which side is sorted before searching

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1, mid;

        while(l <= h){
            mid = (l + h)/2;

            if(nums[mid] == target) return mid;

            // left half is sorted?
            if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target <= nums[mid]){
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            } 
            // right half is definitely sorted
            else {
                if(nums[mid] <= target && target <= nums[h]){
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};
