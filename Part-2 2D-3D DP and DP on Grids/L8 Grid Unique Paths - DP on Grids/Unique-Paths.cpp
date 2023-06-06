//* https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://youtu.be/sdE0A2Oxofw

#include <bits/stdc++.h> 

int rec(int row, int col, vector<vector<int>>& dp){
	if(row == 0 && col == 0){
		return 1;
	}
	if(row < 0 || col < 0){
		return 0;
	}

	if(dp[row][col] != -1){
		return dp[row][col];
	}

	int up = rec(row-1,col, dp);
	int left = rec(row,col-1, dp);
	return dp[row][col] = up+left;
}

int uniquePaths(int m, int n) {
	// Write your code here.

	//* Recrusive Soln-> TLE
	// return rec(m-1,n-1);

	//* DP Memoization->
	// vector<vector<int>> dp(m, vector<int>(n,-1));
	// return rec(m-1,n-1,dp);

	//* DP Tabulation->
	// int dp[m][n];
	// for(int i = 0; i < m; ++i){
	// 	for(int j = 0; j < n; ++j){
	// 		if(i == 0 && j == 0){
	// 			dp[i][j] = 1;
	// 		}
	// 		else{
	// 			int up = 0, left = 0;
	// 			if(i > 0){
	// 				up = dp[i-1][j];
	// 			}
	// 			if(j > 0){
	// 				left = dp[i][j-1];
	// 			}

	// 			dp[i][j] = up + left;
	// 		}
	// 	}
	// }
	// return dp[m-1][n-1];

	//* DP (Tabulation + Space Optimisation)
	vector<int> prev(n, 0);
	for(int i = 0; i < m; ++i){
		vector<int> temp(n, 0);
		for(int j = 0; j < n; ++j){
			if(i == 0 && j == 0){
				temp[j] = 1;
			}
			else{
				int up = 0, left = 0;
				if(i > 0){
					up = prev[j];
				}
				if(j > 0){
					left = temp[j-1];
				}

				temp[j] = up + left;
			}
		}
		prev = temp;
	}
	return prev[n-1];
}