//* https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://youtu.be/NPZn9jBrX8U

#include <bits/stdc++.h>
using namespace std;

int rec(int ind1, int ind2, string s, string t, vector<vector<int>>& dp){
	// base case
	if(ind1 < 0 || ind2 < 0){
		return 0;
	}

	if(dp[ind1][ind2] != -1){
		return dp[ind1][ind2];
	}

	if(s[ind1] == t[ind2]){
		return (1 + rec(ind1-1, ind2-1, s, t, dp));
	}
	else{
		return (0 + max(rec(ind1-1, ind2, s, t, dp), rec(ind1, ind2-1, s, t, dp)));
	}
}

// shifting of indexes
int f(int ind1, int ind2, string s, string t, vector<vector<int>>& dp){
	// base case
	if(ind1 == 0 || ind2 == 0){
		return 0;
	}

	if(dp[ind1][ind2] != -1){
		return dp[ind1][ind2];
	}

	if(s[ind1-1] == t[ind2-1]){
		return (1 + f(ind1-1, ind2-1, s, t, dp));
	}
	else{
		return (0 + max(f(ind1-1, ind2, s, t, dp), f(ind1, ind2-1, s, t, dp)));
	}
}

int tab(int n, int m, string s, string t){
	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

	// Base Cases
	for(int ind2 = 0; ind2 <= m; ++ind2) dp[0][ind2] = 0;
	for(int ind1 = 0; ind1 <= n; ++ind1) dp[ind1][0] = 0;

	for(int ind1 = 1; ind1 <= n; ++ind1){
		for(int ind2 = 1; ind2 <= m; ++ind2){
			if(s[ind1-1] == t[ind2-1]){
				dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
			}
			else{
				dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
			}
		}
	}

	return dp[n][m];
}

int so(int n, int m, string s, string t){
	vector<int> prev(m+1, 0), curr(m+1, 0);

	// Base Cases
	for(int ind2 = 0; ind2 <= m; ++ind2) prev[ind2] = 0;

	for(int ind1 = 1; ind1 <= n; ++ind1){
		for(int ind2 = 1; ind2 <= m; ++ind2){
			if(s[ind1-1] == t[ind2-1]){
				curr[ind2] = 1 + prev[ind2-1];
			}
			else{
				curr[ind2] = 0 + max(prev[ind2], curr[ind2-1]);
			}
		}
		prev = curr;
	}

	return prev[m];
}

int lcs(string s, string t)
{
	//Write your code here

	int n = s.length();
	int m = t.length();

	//* Recursive Approach-> TLE
	// return rec(n-1, m-1, s, t);

	//* Recursive Approach using Shifting of indexes-> TLE
	// return f(n, m, s, t);

	//* DP Memoization -> TLE
	// vector<vector<int>> dp(n, vector<int> (m, -1));
	// return rec(n-1, m-1, s, t, dp);
	// vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
	// return f(n, m, s, t, dp);

	//* DP Tabulation->
	// return tab(n, m, s, t);

	//* DP Space Optimisation->
	return so(n, m, s, t);
}