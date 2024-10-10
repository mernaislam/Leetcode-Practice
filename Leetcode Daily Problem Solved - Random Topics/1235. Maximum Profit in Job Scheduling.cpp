/// @author Merna Islam
/// @date 06/01/2024.
/// @link https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
public:
    struct job {
        int start, end, profit;
        job(int startTime, int endTime, int pro){
            start = startTime;
            end = endTime;
            profit = pro;
        }
    };

    static bool compareByStartTime(const job &a, const job &b){
        return a.start < b.start;
    }

    int n = 0;
    int dp[50005];
    vector<job> vec;
    vector<int> startTime;

    int solve(int curr){
        if(curr >= n){
            return 0;
        }

        // mem
        int &ret = dp[curr];
        if(~ret) return dp[curr];

        // take        
        int next = lower_bound(startTime.begin(), startTime.end(), vec[curr].end) - startTime.begin();
        int opt1 = solve(next) + vec[curr].profit;

        // leave
        int opt2 = solve(curr+1);

        // maximize
        return ret = max(opt1, opt2);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        for(int i = 0; i < n; i++){
            vec.push_back(job(startTime[i], endTime[i], profit[i]));
        }
        sort(vec.begin(), vec.end(), compareByStartTime);
        memset(dp, -1, sizeof dp);
        this->startTime = startTime;
        sort(this->startTime.begin(), this->startTime.end());
        return solve(0);
    }
};