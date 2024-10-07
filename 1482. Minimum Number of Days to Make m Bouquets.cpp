/// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    int getMax(vector<int>& bloomDay){
        int mx = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            mx = max(mx, bloomDay[i]);
        }
        return mx;
    }

    int getBouquetCollected(vector<int>& bloomDay, int d, int k){
        int flowers = 0;
        int cnt = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= d){
                cnt++;
            } else {
                cnt = 0;
            }
            if(cnt == k){
                flowers++;
                cnt = 0;
            }
        }
        return flowers;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0, h = getMax(bloomDay), mid, ans = INT_MAX;

        if(bloomDay.size() / k < m) return -1;

        while(l <= h){
            mid = (l + h) / 2;

            int result = getBouquetCollected(bloomDay, mid, k);
            if(result < m){
                l = mid + 1;
            } else {
                ans = min(ans, mid);
                h = mid - 1;
            }
        }
        return ans;
    }
};
