/// https://leetcode.com/problems/split-array-largest-sum/

#include <bits/stdc++.h>
class Solution {
public:
    int countSubArrays(vector<int>& nums, int result){
        int cnt = 1;
        int n = nums.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            if(sum + nums[i] <= result){
                sum += nums[i];
            } else {
                sum = nums[i];
                cnt++;
            }
        }

        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);
        int mid;

        while(l <= h){

            mid = (l + h) / 2;

            int result = countSubArrays(nums, mid);

            if(result <= k){
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};
