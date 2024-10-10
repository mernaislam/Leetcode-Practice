/// @author Merna Islam
/// @date 03/01/2024.
/// @link https://leetcode.com/problems/number-of-laser-beams-in-a-bank

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int M = 0;
        vector<int> vec;
        for(int j = 0; j < bank.size(); j++){
            int count = 0;
            for(int i = 0; i < bank[j].size(); i++){
                if(bank[j][i] == '1'){
                    count++;
                }
            }
            if(count != 0){
                vec.push_back(count);
                M++;
            }
        }
        int result = 0;
        if(!vec.empty()){
            for(int i = 0; i < vec.size() - 1; i++){
                result += vec[i] * vec[i+1];
            }
        }
        return result;
    }
};