/// @author Merna Islam
/// @date 07/01/2024.
/// @link https://leetcode.com/problems/arithmetic-slices-ii-subsequence

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<long, int> mp[n];

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                long diff = (long) nums[i] - nums[j];

                auto it = mp[j].find(diff);
                int counter;
                if(it == mp[j].end()){
                    counter = 0;
                } else {
                    counter = it->second;
                }

                mp[i][diff] += counter + 1;
                ans += counter;
            }
        }
        return ans;
    }
};