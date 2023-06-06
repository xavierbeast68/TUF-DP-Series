//* https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://www.youtube.com/watch?v=GqOmJHQZivw

#include <bits/stdc++.h> 
int rec(int ind, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
	if(ind == 0){
		if(W >= wt[0]){
			return val[0];
		}
		return 0;
	}

	if(dp[ind][W] != -1){
		return dp[ind][W];
	}

	int notTake = 0 + rec(ind-1, W, val, wt, dp);
	int take = INT_MIN;

	if(W >= wt[ind]){
		take = val[ind] + rec(ind-1, W-wt[ind], val, wt, dp);
	}

	return dp[ind][W] = max(take, notTake);
}

int tab(vector<int> wt, vector<int> val, int n, int maxWeight){
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));
	
	// Base Cases->
	for(int w = wt[0]; w <= maxWeight; ++w){
		dp[0][w] = val[0];
	}

	for(int ind = 1; ind < n; ++ind){
		for(int w = 0; w <= maxWeight; ++w){
			int notTake = 0 + dp[ind-1][w];
			int take = INT_MIN;

			if(w >= wt[ind]){
				take = val[ind] + dp[ind-1][w-wt[ind]];
			}

			dp[ind][w] = max(take, notTake);
		}
	}

	return dp[n-1][maxWeight];
}

int so(vector<int> wt, vector<int> val, int n, int maxWeight){
	vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);
	
	// Base Cases->
	for(int w = wt[0]; w <= maxWeight; ++w){
		prev[w] = val[0];
	}

	for(int ind = 1; ind < n; ++ind){
		for(int w = 0; w <= maxWeight; ++w){
			int notTake = 0 + prev[w];
			int take = INT_MIN;

			if(w >= wt[ind]){
				take = val[ind] + prev[w-wt[ind]];
			}

			curr[w] = max(take, notTake);
		}
		prev = curr;
	}

	return prev[maxWeight];
}

int soo(vector<int> wt, vector<int> val, int n, int maxWeight){
	vector<int> prev(maxWeight+1, 0);
	
	// Base Cases->
	for(int w = wt[0]; w <= maxWeight; ++w){
		prev[w] = val[0];
	}

	for(int ind = 1; ind < n; ++ind){
		for(int w = maxWeight; w >= 0; --w){
			int notTake = 0 + prev[w];
			int take = INT_MIN;

			if(w >= wt[ind]){
				take = val[ind] + prev[w-wt[ind]];
			}

			prev[w] = max(take, notTake);
		}
	}
	return prev[maxWeight];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here

	//* Recursive Approach-> TLE
	// return rec(n-1, maxWeight, value, weight);

	//* DP Memoization->
	// vector<vector<int>> dp(n, vector<int> (maxWeight + 1, -1));
	// return rec(n-1, maxWeight, value, weight, dp);

	//* DP Tabulation->
	// return tab(weight, value, n, maxWeight);

	//* DP Space Optimisation->
	// return so(weight, value, n, maxWeight);

	//* DP Single array space optimisation->
	return soo(weight, value, n, maxWeight);
}