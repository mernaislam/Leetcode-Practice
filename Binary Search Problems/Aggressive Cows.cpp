bool isPossible(vector<int> &stalls, int k, int distance){
    int j = 0;
    int cnt = 1;
    for(int i = 1; i < stalls.size(); i++){
       if(stalls[i] - stalls[j] >= distance){
           cnt++;
           j = i;
       } 

       if(cnt == k) {
           return true;
       };
    }

    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int l = 1, h = stalls[n-1] - stalls[0], mid;
    int ans = 0;

    while(l <= h){
        mid = (l + h) / 2;

        bool result = isPossible(stalls, k, mid);

        if(result){
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    return ans;
}
