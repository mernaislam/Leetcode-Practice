/// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    int firstPosition(vector<int>& nums, int target){
        int first = -1;
        int l = 0;
        int h = nums.size() - 1;
        
        while(l <= h){
            int mid = (l + h)/2;
            if(nums[mid] == target) {
                first = mid;
                h = mid - 1; // keep searching to find another one on the left
            } else if(nums[mid] > target){
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << first;
        return first;
    }

    int lastPosition(vector<int>& nums, int target){
        int last = -1;
        int l = 0;
        int h = nums.size() - 1;
        
        while(l <= h){
            int mid = (l + h)/2;
            if(nums[mid] == target) {
                last = mid;
                l = mid + 1; // keep searching to find another one on the right
            } else if(nums[mid] > target){
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstPosition(nums, target);
        int last = lastPosition(nums, target);
        return {first, last};
    }
};
