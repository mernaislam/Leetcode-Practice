/// @author Merna Islam
/// @date 04/01/2024.
/// @link https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty

class Solution {
public:
    const static int N = 1e6 + 7;
    int dp[N];

    int solve(int count){
        if(count == 0){
            return 0;
        }

        if(count < 0){
            return 1e8;
        }
        int &ret = dp[count];
        if(~ret) return ret;

        // minus 2
        int opt1 = solve(count - 2) + 1;

        // minus 3
        int opt2 = solve(count - 3) + 1;

        return ret = min(opt1, opt2);
    }

    int minOperations(vector<int>& nums) {
        int count = 0;
        int freq[N];
        memset(dp, -1, sizeof dp);
        memset(freq, 0, sizeof freq);
        set<int> st;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
            st.insert(nums[i]);
        }
        for(auto i: st){
            count += solve(freq[i]);
            if(count >= 1e8) {
                return -1;
            }
        }
        return count;
    }
};