//* https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://youtu.be/_wP9mWNPL5w

#include <bits/stdc++.h> 
using namespace std;

int tab(int n, int m, string s, string t){
	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
	int ans = 0;

	// Base Cases
	for(int ind2 = 0; ind2 <= m; ++ind2) dp[0][ind2] = 0;
	for(int ind1 = 0; ind1 <= n; ++ind1) dp[ind1][0] = 0;

	for(int ind1 = 1; ind1 <= n; ++ind1){
		for(int ind2 = 1; ind2 <= m; ++ind2){
			if(s[ind1-1] == t[ind2-1]){
				dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
				ans = max(ans, dp[ind1][ind2]);
			}
			else{
				dp[ind1][ind2] = 0;
			}
		}
	}

	return ans;
}

int so(int n, int m, string s, string t){
	vector<int> prev(m+1, 0), curr(m+1, 0);
	int ans = 0;

	// Base Cases
	for(int ind2 = 0; ind2 <= m; ++ind2) prev[ind2] = 0;

	for(int ind1 = 1; ind1 <= n; ++ind1){
		for(int ind2 = 1; ind2 <= m; ++ind2){
			if(s[ind1-1] == t[ind2-1]){
				curr[ind2] = 1 + prev[ind2-1];
				ans = max(ans, curr[ind2]);
			}
			else{
				curr[ind2] = 0;
			}
		}
		prev = curr;
	}

	return ans;
}

int lcs(string &str1, string &str2){
	//	Write your code here.

	int n = str1.length();
	int m = str2.length();

	//* DP Tabulation->
	// return tab(n, m, str1, str2);

	//* DP Space Optimisation->
	return so(n, m, str1, str2);
}