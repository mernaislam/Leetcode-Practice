/// https://leetcode.com/problems/kth-missing-positive-number/
/// Explanation video: https://youtu.be/uZ0N_hZpyps?si=I6Ip4xNaoYXKTBNX

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, h = arr.size() - 1, mid;

        while(l <= h){
            mid = (l + h) / 2;
            int missing = arr[mid] - (mid + 1);
            if(missing >= k){
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        } 

        // To get the formula, we need to elimiate arr[high] in the formula because high may get out of range
        // since more = k - missing
        // since missing = arr[high] - (high + 1)
        // All you need to return is (arr[high] + more)
        // return arr[high] + (k - missing)
        // return arr[high] + k - arr[high] + high + 1
        // return k + high + 1  ----> we know that high + 1 = low
        // return low + k
        return l + k;
    }
};
