//* https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://www.youtube.com/watch?v=yMnH0jrir0Q

#include <bits/stdc++.h> 
using namespace std;

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
	int n = s.length();
	int m = t.length();

	//* DP Tabulation->
	// return tab(n, m, s, t);

	//* DP Space Optimisation->
	return so(n, m, s, t);
}
int canYouMake(string &str, string &ptr)
{
    // Write your code here.

    return (str.size() + ptr.size() - 2 * lcs(str, ptr));
}