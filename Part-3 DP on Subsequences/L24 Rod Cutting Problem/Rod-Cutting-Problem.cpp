//* https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://youtu.be/mO8XpGoJwuo


#include <bits/stdc++.h>
using namespace std;

int rec(int ind, int target, vector<int>& val, vector<vector<int>>& dp){
	if(ind == 0){
		return target*val[0];
	}

	if(dp[ind][target] != -1){
		return dp[ind][target];
	}

	int notCut = 0 + rec(ind-1, target, val, dp);
	int cut = 0;
	if(target >= (ind+1)){
		cut = val[ind] + rec(ind, target-(ind+1), val, dp);
	}

	return dp[ind][target] = max(cut, notCut);
}

int tab(vector<int> len, vector<int> val, int n, int maxLength){
	vector<vector<int>> dp(n, vector<int> (maxLength+1, 0));
	
	// Base Cases->
	for(int l = 0; l <= maxLength; ++l){
		dp[0][l] = l * val[0];
	}

	for(int ind = 1; ind < n; ++ind){
		for(int l = 0; l <= maxLength; ++l){
			int notTake = 0 + dp[ind-1][l];
			int take = INT_MIN;

			if(l >= len[ind]){
				take = val[ind] + dp[ind][l-len[ind]];
			}

			dp[ind][l] = max(take, notTake);
		}
	}

	return dp[n-1][maxLength];
}

int so(vector<int> len, vector<int> val, int n, int maxLength){
	vector<int> prev(maxLength+1, 0), curr(maxLength+1, 0);
	
	// Base Cases->
	for(int l = 0; l <= maxLength; ++l){
		prev[l] = l * val[0];
	}

	for(int ind = 1; ind < n; ++ind){
		for(int l = 0; l <= maxLength; ++l){
			int notTake = 0 + prev[l];
			int take = INT_MIN;

			if(l >= len[ind]){
				take = val[ind] + curr[l-len[ind]];
			}

			curr[l] = max(take, notTake);
		}
		prev = curr;
	}

	return prev[maxLength];
}

int soo(vector<int> len, vector<int> val, int n, int maxLength){
	vector<int> prev(maxLength+1, 0);
	
	// Base Cases->
	for(int l = 0; l <= maxLength; ++l){
		prev[l] = l * val[0];
	}

	for(int ind = 1; ind < n; ++ind){
		for(int l = 0; l <= maxLength; ++l){
			int notTake = 0 + prev[l];
			int take = INT_MIN;

			if(l >= len[ind]){
				take = val[ind] + prev[l-len[ind]];
			}

			prev[l] = max(take, notTake);
		}
	}

	return prev[maxLength];
}


int cutRod(vector<int> &price, int n)
{
	// Write your code here.

	//* Recursive Approach->
	// return rec(n-1, n, price);

	//* DP Memoization->
	// vector<vector<int>> dp(n, vector<int>(n+1, -1));
	// return rec(n-1, n, price, dp);

	//* Dp Tabulaton->
	// vector<int>len(n,0);
	// for(int i = 0; i < n; ++i){
	// 	len[i] = i+1;
	// }
	// return tab(len, price, n, n);

	//* DP Space Optimisation->
	// vector<int>len(n,0);
	// for(int i = 0; i < n; ++i){
	// 	len[i] = i+1;
	// }
	// return so(len, price, n, n);

	//* DP Single array space optimisation->
	vector<int>len(n,0);
	for(int i = 0; i < n; ++i){
		len[i] = i+1;
	}
	return soo(len, price, n, n);
}

