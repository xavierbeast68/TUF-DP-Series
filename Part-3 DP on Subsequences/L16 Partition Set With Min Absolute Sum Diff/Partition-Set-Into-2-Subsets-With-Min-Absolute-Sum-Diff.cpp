//* https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://www.youtube.com/watch?v=GS_OqZb2CWc

#include <bits/stdc++.h>

int rec(int ind, int sack1, int sack2, vector<int>& arr, vector<vector<int>>& dp){
	if(ind < 0){
		return abs(sack1 - sack2);
	}

	if(dp[ind][sack1] != -1){
		return dp[ind][sack1];
	}

	int addToSack1 = rec(ind-1, sack1 + arr[ind], sack2, arr, dp);
	int addToSack2 = rec(ind-1, sack1, sack2 + arr[ind], arr, dp);

	return dp[ind][sack1] = min(addToSack1, addToSack2);
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int sum = accumulate(arr.begin(), arr.end(), 0);

	//* Recursive Approach-> TLE (My method)
	// return rec(n-1, 0, 0, arr);

	//* DP Memoization
	// vector<vector<int>> dp(n, vector<int> (sum+1, -1));
	// return rec(n-1, 0, 0, arr, dp);

	//* Another Approach-> (Striver Method)
	//* DP tabulation->
	int k = sum;
	vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
    for(int ind = 0; ind < n; ++ind){
        dp[ind][0] = true;
    }
    if(arr[0] <= k) dp[0][arr[0]] = true;
    for(int ind = 1; ind < n; ++ind){
        for(int target = 1; target <= k; ++target){
            bool notTake = dp[ind-1][target];

            bool take = false;

            if(target >= arr[ind]){
                take = dp[ind-1][target-arr[ind]];
            }

            dp[ind][target] = (take | notTake);
        }
    }
    
	int mini = 1e8;
	// dp[n-1][col->0...sum]
	for(int s1 = 0; s1 <= sum/2; ++s1){
		if(dp[n-1][s1]){
			mini = min(mini, abs((sum-s1) - s1));
		}
	}
	return mini;
	
}
