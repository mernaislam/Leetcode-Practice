/// https://leetcode.com/problems/search-insert-position
/// It's a very straightforward binary search problem

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int l = 0;
       int h = nums.size() - 1;
       int mid;
       
       while(l <= h)
       {
            mid = (l + h)/2;
            if(nums[mid] >= target)
            {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
       } 
       return l;
    }
};
