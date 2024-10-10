/// @author Merna Islam
/// @date 15/01/2024.
/// @link https://leetcode.com/problems/find-players-with-zero-or-one-losses

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mpLoss;
        for(int i = 0; i < matches.size(); i++){
            mpLoss[matches[i][0]] = -1;
            mpLoss[matches[i][1]] = -1;
        }
        for(int i = 0; i < matches.size(); i++){
            mpLoss[matches[i][1]]++;
        }

        vector<vector<int>> result;
        result.push_back({});
        result.push_back({});

        for(auto i: mpLoss){
            if(i.second == -1){
                result[0].push_back(i.first);
            }
            else if(i.second == 0){
                result[1].push_back(i.first);
            }
        }
        return result;
    }
};