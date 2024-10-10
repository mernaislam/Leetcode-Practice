/// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    int getMax(vector<int>& piles){
        int mx = 0;
        for(int i = 0; i < piles.size(); i++){
            mx = max(mx, piles[i]);
        }
        return mx;
    }

    int canEatAll(vector<int>& piles, int k, int h){
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] <= k){
                h--;
            } else {
                h -= ceil(piles[i] / double(k));
            }
            if(h < 0) return 0;  // k is not enough, we need larger k
        }

        // k is enough, we can try with smaller k
        return 1;
    }

    int minEatingSpeed(vector<int>& piles, int x) {
        int l = 1, h = getMax(piles), mid;

        while(l <= h){
            mid = (l + h) / 2;

            int result = canEatAll(piles, mid, x);

            if(result == 0) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return l;
    }
};
