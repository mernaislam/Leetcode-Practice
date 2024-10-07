/// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int getMax(vector<int>& nums){
        int mx = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
        }
        return mx;
    }

    int isPossible(vector<int>& nums, int threshold, int divisor){
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += ceil(nums[i] / (double) divisor);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, h = *max_element(nums.begin(), nums.end()), mid;

        while(l <= h){
            mid = (l + h) / 2;

            int result = isPossible(nums, threshold, mid);

            if(result <= threshold){
                h = mid - 1;
            } else {
                l = mid + 1;
            }

        }

        return l;
    }
};
