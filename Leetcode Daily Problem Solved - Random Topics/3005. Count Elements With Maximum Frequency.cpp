/// @author Merna Islam
/// @date 08/03/2024.
/// @link https://leetcode.com/problems/count-elements-with-maximum-frequency/

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxFreq = 0;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            maxFreq = max(maxFreq, mp[nums[i]]);
        }

        int cnt = 0;
        for(auto i: mp){
            if(i.second == maxFreq) cnt += maxFreq;
        }
        return cnt;
    }
};