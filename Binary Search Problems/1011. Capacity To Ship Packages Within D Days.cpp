/// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    int isPossible(vector<int>& weights, int weight){
        int n = weights.size();
        int load = 0;
        int days = 1;
        for(int i = 0; i < n; i++){
           if(load + weights[i] > weight){
            days++;
            load = weights[i];
           } else {
            load += weights[i];
           }
        }
        return days;
    }


    int shipWithinDays(vector<int>& weights, int days) {
      int l = *max_element(weights.begin(), weights.end());
      int h = accumulate(weights.begin(),weights.end(),0);
      int mid;

      while(l <= h){
        mid = (l + h) / 2;

        int result = isPossible(weights, mid);

        if(result <= days){
            h = mid - 1;
        } else {
            l = mid + 1;
        }

      }
      return l; 
    }
};
