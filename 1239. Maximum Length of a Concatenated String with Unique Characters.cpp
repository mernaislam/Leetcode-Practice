/// @author Merna Islam
/// @date 23/01/2024.
/// @link https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

class Solution {
public:
    int solve(const vector<string>& vec, int i, string currentString){
        // base case
        if(i == vec.size()){
            return 0;
        }

        // take if unique characters
        int opt1 = -1;
        if(isValid(currentString, vec[i])){
            opt1 = solve(vec, i+1, currentString + vec[i]) + vec[i].length();
        }

        // leave
        int opt2 = solve(vec, i+1, currentString);


        return min(26, max(opt1, opt2));
    }

    bool isValid(const string& currentString, const string& newString) {
        unordered_set<char> charSet;

        for (char ch : newString) {
            if (charSet.count(ch) > 0) {
                return false;
            }

            charSet.insert(ch);

            if (currentString.find(ch) != string::npos) {
                return false;
            }
        }

        return true;
    }

    int maxLength(vector<string>& arr) {
        return solve(arr, 0, "");
    }
};