/// Search in Rotated Sorted Array II
/// https://leetcode.com/problems/search-in-rotated-sorted-array-ii
/*
    It is the same as the Search in Rotated Sorted Array I, except the edge case and return type

    The average time complexity = O(log n)

    In the worst case, it may be shrinking all the way done to the middle,
    therefore, this may result in a complexity of O(n/2)
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1, mid;

        while(l <= h){
            mid = (l + h)/2;

            if(nums[mid] == target) return true;

            // edge case
            if(nums[l] == nums[mid] && nums[mid] == nums[h]){
                l++;
                h--;
                continue;
            }

            // left half is sorted?
            if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target <= nums[mid]){
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            // right half is sorted 
            else {
                if(nums[mid] <= target && target <= nums[h]){
                    l = mid + 1;
                } else {
                    h = mid - 1;                    
                }
            }
        } 

        return false;
    }
};
