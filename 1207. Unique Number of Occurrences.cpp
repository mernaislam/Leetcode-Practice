/// @author Merna Islam
/// @date 29/03/2024.
/// @link https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int> st;
        map<int, int> mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        for(auto i: mp){
            int n = st.size();
            st.insert(i.second);
            if(n == st.size()){
                return false;
            }
        }
        return true;
    }
};