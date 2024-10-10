/// @author Merna Islam
/// @date 02/02/2024.
/// @link https://leetcode.com/problems/sequential-digits/description

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        /// First time approach
        // vector<int> result;
        // int lowCnt = log10(low) + 1;
        // int highCnt = log10(high) + 1;
        // highCnt = min(9,highCnt);
        // for(int k = lowCnt; k <= highCnt; k++){
        //     long long num = 0;
        //     int add = 0;
        //     int cnt = k - 1;
        //     for(int i = 1; i <= k; i++){
        //         num += pow(10, cnt) * i;
        //         add += pow(10, cnt);
        //         cnt--;
        //     }
        //     if(num <= high && num >= low){
        //         result.push_back(num);
        //     }
        //     while(num%10 != 9){
        //         num += add; 
        //         if(num <= high && num >= low){
        //             result.push_back(num);
        //         } else if(num < low){
        //             continue;
        //         } else{
        //             break;
        //         }
        //     }
        // }
        // return result;



        /// Efficient approach
        vector<int> result;
        for(int i = 1; i < 9; i++){
            int num = i;
            int nextDigit = i + 1;

            while(num <= high && nextDigit <= 9){
                num = num * 10 + nextDigit;

                if(num <= high && num >= low){
                    result.push_back(num);
                }

                ++nextDigit;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};