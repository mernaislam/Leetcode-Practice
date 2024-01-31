/// @author Merna Islam
/// @date 31/01/2024.
/// @link https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        deque<int> dq;
        vector<int> result(temperatures.size());

        for(int i = temperatures.size() - 1; i >= 0; --i){
            if(dq.empty()){
                dq.push_front(i);
                result[i] = 0;
            } else {
                while(!dq.empty() && temperatures[i] >= temperatures[dq.front()]){
                    dq.pop_front();
                }

                if(dq.empty()){
                    result[i] = 0;
                } else {
                    result[i] = dq.front() - i;
                }

                dq.push_front(i);
            }
        }
        return result;
    }
};