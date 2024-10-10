/// @author Merna Islam
/// @date 30/01/2024.
/// @link https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                int result;
                if(tokens[i] == "*"){
                    result = val1 * val2;
                } else if(tokens[i] == "-"){
                    result = val1 - val2;
                } else if(tokens[i] == "+"){
                    result = val1 + val2;
                } else {
                    result = val1 / val2;
                }
                st.push(result);
            } else {
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};