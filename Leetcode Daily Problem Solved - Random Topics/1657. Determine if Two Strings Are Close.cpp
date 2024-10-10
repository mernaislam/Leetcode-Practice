/// @author Merna Islam
/// @date 14/01/2024.
/// @link https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> vec1; // save occurrences of word1  
        vector<int> vec2; // save occurrences of word2

        if(word1.length() != word2.length()){
            return false;
        }

        map<char, int> mp1;
        map<char, int> mp2;

        for(int i = 0; i < word1.length(); i++) mp1[word1[i]]++;
        for(int i = 0; i < word2.length(); i++) mp2[word2[i]]++;

        for(auto i: mp1){
            // if different frequency of characters
            if(i.second != mp2[i.first]){
                vec1.push_back(i.second);
            }
        }

        for(auto i: mp2){
            // if different frequency of characters and character exists in word1
            if(i.second != mp1[i.first] && mp1[i.first] != 0){
                vec2.push_back(i.second);
            }
        }

        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());

        if(vec1.size() != vec2.size()){
            return false;
        }

        for(int i = 0; i < vec1.size(); i++){
            if(vec1[i] != vec2[i]){
                return false;
            }
        }
        return true;
    }
};