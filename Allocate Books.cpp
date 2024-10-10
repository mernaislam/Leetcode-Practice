#include <bits/stdc++.h> 

int numberOfNinja(vector<int> &pages, int mid){
	int n = pages.size();
	int sum = 0;
	int cnt = 1;
	for(int i = 0; i < n; i++){
		if(sum + pages[i] <= mid){
			sum += pages[i];
		} else {
			cnt++;
			sum = pages[i];
		}
	}
	return cnt;
}

int allocateBooks(vector<int> &pages, int n, int b)
{
	if(n < b) return -1;

	int l = *max_element(pages.begin(), pages.end());
	int h = accumulate(pages.begin(), pages.end(),0);
	int mid;
	int ans = INT_MAX;

	while(l <= h){
		mid = (l + h) / 2;

		int result = numberOfNinja(pages, mid);
		
		if(result <= b){
			h = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return l;

}
