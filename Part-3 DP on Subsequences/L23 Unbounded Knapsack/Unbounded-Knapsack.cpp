//* https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://youtu.be/OgvOZ6OrJoY


#include <bits/stdc++.h> 
using namespace std;

int rec(int ind, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
	if(ind == 0){
        return ((int)(W/wt[0]) * val[0]);
	}

	if(dp[ind][W] != -1){
		return dp[ind][W];
	}

	int notTake = 0 + rec(ind-1, W, val, wt, dp);
	int take = INT_MIN;

	if(W >= wt[ind]){
		take = val[ind] + rec(ind, W-wt[ind], val, wt, dp);
	}

	return dp[ind][W] = max(take, notTake);
}

int tab(vector<int> wt, vector<int> val, int n, int maxWeight){
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));
	
	// Base Cases->
	for(int w = wt[0]; w <= maxWeight; ++w){
		dp[0][w] =((int)w/wt[0]) * val[0];
	}

	for(int ind = 1; ind < n; ++ind){
		for(int w = 0; w <= maxWeight; ++w){
			int notTake = 0 + dp[ind-1][w];
			int take = INT_MIN;

			if(w >= wt[ind]){
				take = val[ind] + dp[ind][w-wt[ind]];
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
		prev[w] = w/wt[0] * val[0];
	}

	for(int ind = 1; ind < n; ++ind){
		for(int w = 0; w <= maxWeight; ++w){
			int notTake = 0 + prev[w];
			int take = INT_MIN;

			if(w >= wt[ind]){
				take = val[ind] + curr[w-wt[ind]];
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
		prev[w] = ((int)w/wt[0]) * val[0];
	}

	for(int ind = 1; ind < n; ++ind){
		for(int w = 0; w <= maxWeight; ++w){
			int notTake = 0 + prev[w];
			int take = 0;

			if(w >= wt[ind]){
				take = val[ind] + prev[w-wt[ind]];
			}

			prev[w] = max(take, notTake);
		}
	}
	return prev[maxWeight];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.

    //* Recursive Approach-> TLE
	// return rec(n-1, w, profit, weight);

	//* DP Memoization->
	// vector<vector<int>> dp(n, vector<int> (w + 1, -1));
	// return rec(n-1, w, profit, weight, dp);

	//* DP Tabulation->
	// return tab(weight, profit, n, w);

	//* DP Space Optimisation->
	// return so(weight, profit, n, w);

	//* DP Single array space optimisation->
	return soo(weight, profit, n, w);
}
