/// @author Merna Islam
/// @date 17/01/2024.
/// @link https://leetcode.com/problems/unique-number-of-occurrences

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