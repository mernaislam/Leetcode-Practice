class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int max = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max) max = nums[i];
        }

        int l = 0;
        int cnt = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == max) cnt++;

            if(cnt >= k){
                while(cnt >= k){
                    if(nums[l] == max) cnt--;
                    l++;
                    ans += nums.size() - r;
                }
            }
        }
        return ans;
    }
};