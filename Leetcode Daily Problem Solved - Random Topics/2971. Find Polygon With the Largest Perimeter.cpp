/// @author Merna Islam
/// @date 15/02/2024.
/// @link https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // sort in log(n)
        sort(nums.begin(), nums.end());

        long long result;
        long long sum = 0;
        int cnt = nums.size();

        // get the sum of all sides
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
        }

        // check for each element if it is smaller than all the other sides
        for(int i = nums.size() - 1; i >= 0; --i){
            sum -= nums[i];
            if(nums[i] < sum && cnt > 2){
                return sum + nums[i];
            } else {
                cnt--;
            }
        }
        return -1;
    }
};