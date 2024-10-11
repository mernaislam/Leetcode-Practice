/// Minimize Max Distance to Gas Station
/// https://www.naukri.com/code360/problems/minimise-max-distance_7541449?leftPanelTabValue=PROBLEM
/// priority queue approach - the problem with this approach is that it takes space complexity of O(n)
#include <bits/stdc++.h>

double minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size();
	vector<int> gasAdded(n - 1, 0);
    vector<int> initialVal(n - 1, 0);
    std::priority_queue<pair<double, int>> pq;


    for(int i = 0; i < n - 1; i++){
        initialVal[i] = arr[i + 1] - arr[i];
    }

    for(int i = 0; i < n - 1; i++){
        pq.push({initialVal[i], i});
    }


    for(int i = 0; i < k; i++){
        int idx = pq.top().second;
        double val = pq.top().first;
        pq.pop();
        
        gasAdded[idx]++;
        pq.push({initialVal[idx]/(double)(gasAdded[idx] + 1), idx});
    }

    double result = pq.top().first;

    return result;

}
