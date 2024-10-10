/// @author Merna Islam
/// @date 22/02/2024.
/// @link https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> mpTrust;
        unordered_map<int, int> mpTrustedBy;

        for(int i = 0; i < trust.size(); ++i){
            mpTrust[trust[i][0]]++;
            mpTrustedBy[trust[i][1]]++;
        }

        for(int i = 1; i <= n; ++i){
            if(mpTrust[i] == 0 && mpTrustedBy[i] == n-1){
                return i;
            }
        }

        return -1;
    }
};