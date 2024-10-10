/// @author Merna Islam
/// @date 13/03/2024.
/// @link https://leetcode.com/problems/find-the-pivot-integer/

class Solution {
public:
    int pivotInteger(int n) {
        int arr[n+1];
        arr[0] = 0;
        for(int i = 1; i <= n; ++i){
            arr[i] = arr[i-1] + i;
        }

        for(int i = 1; i <= n; ++i){
            if(arr[i] == arr[n] - arr[i-1]){
                return i;
            }
        }
        return -1;
    }
};