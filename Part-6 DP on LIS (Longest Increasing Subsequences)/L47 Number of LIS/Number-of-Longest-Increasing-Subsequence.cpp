//* https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://youtu.be/cKVl1TFdNXg

#include <bits/stdc++.h> 
using namespace std;

int f(vector<int>& arr, int n){
	vector<int> dp(n, 1), cnt(n, 1);
    int maxi = 1;

	// LIS from Front->
	for(int i = 0; i < n; i++){
		for(int prev = 0; prev < i; prev++){
			if(arr[prev] < arr[i] && (1+dp[prev] > dp[i])){
				dp[i] = 1+ dp[prev];
                cnt[i] = cnt[prev];
			}
            else if(arr[prev] < arr[i] && (1+dp[prev] == dp[i])){
                cnt[i] += cnt[prev];
            }
		}
        maxi = max(maxi, dp[i]);
	}

    int nos = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == maxi){
            nos += cnt[i];
        }
    }
	return nos;
}

int findNumberOfLIS(vector<int> &arr)
{
    // Write your code here.

    int n = arr.size();
    //* DP (LIS)->
    return f(arr, n);
}