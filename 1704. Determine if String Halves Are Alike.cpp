/// @author Merna Islam
/// @date 12/01/2024.
/// @link https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length()/2;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string s1 = s.substr(0,n);
        string s2 = s.substr(n);
        int v1 = 0, v2 = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u'){
                v1++;
            }
            if(s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u'){
                v2++;
            }
        }
        return v1 == v2;
    }
};