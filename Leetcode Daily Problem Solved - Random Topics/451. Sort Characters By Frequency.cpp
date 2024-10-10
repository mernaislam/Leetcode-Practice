/// @author Merna Islam
/// @date 07/02/2024.
/// @link https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    unordered_map<char, int> mp;

    string frequencySort(string s) {
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        for(char c : s){
            ++mp[c];
        }

        for(const auto& i: mp){
            pq.push(make_pair(i.first, i.second));
        }

        string result = "";

        while(!pq.empty()){
            pair<char, int> p = pq.top();
            result.append(p.second, p.first);
            pq.pop();
        }

        return result;
    }
};