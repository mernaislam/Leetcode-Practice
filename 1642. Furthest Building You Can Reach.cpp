/// @author Merna Islam
/// @date 17/02/2024.
/// @link https://leetcode.com/problems/furthest-building-you-can-reach/

/// Time complexity: O(n)
/// Space complexity: O(n)

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        priority_queue<int> pq;
        int i, diff;

        for(i = 0; i < heights.size() - 1; ++i){
            diff = heights[i+1] - heights[i];

            if(diff <= 0) continue;

            bricks -= diff;
            pq.push(diff);

            if(bricks < 0){
                bricks += pq.top();
                pq.pop();
                --ladders;
            }

            if(ladders < 0) break;
        }

        return i;
    }
};