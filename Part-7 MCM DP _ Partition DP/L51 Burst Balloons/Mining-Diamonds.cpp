//* https://www.codingninjas.com/codestudio/problems/mining-diamonds_4244494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://youtu.be/Yz4LlDSlkns

#include <bits/stdc++.h> 
using namespace std;

int f(int i, int j , vector<int>& arr, vector<vector<int>>& dp){
	// Base Case->
	if(i > j){
		return 0;
	}

	if(dp[i][j] != -1){
		return dp[i][j];
	}

	// Recursive Case->
	int maxCoins = INT_MIN;
	for(int ind = i; ind <= j; ind++){
		int coins = (arr[i-1] * arr[ind] * arr[j+1]) 
						+ f(i, ind-1, arr, dp) + f(ind+1, j, arr, dp);
		maxCoins = max(maxCoins, coins);
	}

	return dp[i][j] =  maxCoins;
}

int tab(vector<int>& arr){
	int n = arr.size();
	arr.insert(arr.begin(), 1);
	arr.push_back(1);

	vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

	// Base Case-> dp[i][j]=0, for every i>j

	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= n; j++){
			if(i > j){
				continue;
			}

			int maxCoins = INT_MIN;
			for(int ind = i; ind <= j; ind++){
				int coins = (arr[i-1] * arr[ind] * arr[j+1]) 
								+ dp[i][ind-1] + dp[ind+1][j];
				maxCoins = max(maxCoins, coins);
			}

			dp[i][j] =  maxCoins;
		}
	}

	return dp[1][n];
}

int maxCoins(vector<int>& arr){
	// Write your code here.

	//* Recursive Approach-> TLE
	// int n = arr.size();
	// arr.insert(arr.begin(), 1);
	// arr.push_back(1);
	// return f(1, n, arr);

	//* DP Memoization->
	// int n = arr.size();
	// arr.insert(arr.begin(), 1);
	// arr.push_back(1);
	// vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
	// return f(1, n, arr, dp);

	//* DP Tabulation->
	return tab(arr);
}