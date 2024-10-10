#include <bits/stdc++.h> 

int numberOfNinja(vector<int> &boards, int mid){
	int n = boards.size();
	int sum = 0;
	int cnt = 1;
	for(int i = 0; i < n; i++){
		if(sum + boards[i] <= mid){
			sum += boards[i];
		} else {
			cnt++;
			sum = boards[i];
		}
	}
	return cnt;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
	int l = *max_element(boards.begin(), boards.end());
	int h = accumulate(boards.begin(), boards.end(),0);
	int mid;

	while(l <= h){
		mid = (l + h) / 2;

		int result = numberOfNinja(boards, mid);
		
		if(result <= k){
			h = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return l;

}
