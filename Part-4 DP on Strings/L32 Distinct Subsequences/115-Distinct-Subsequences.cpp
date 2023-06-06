//* https://leetcode.com/problems/distinct-subsequences/description/
//* https://youtu.be/nVG7eTiD2bY

class Solution {
public:
    // 0-based indexing
    int rec(int i, int j, string s, string t){
        // Base Cases
        if(j < 0){
            return 1;
        }
        if(i < 0){
            return 0;
        }

        // Recursive Cases
        if(s[i] == t[j]){
            return (rec(i-1, j-1, s, t) + rec(i-1, j, s, t));
        }
        else{
            return (rec(i-1, j, s, t));
        }
    }

    // 1-based indexing
    int f(int i, int j, string s, string t, vector<vector<int>>& dp){
        // Base Cases
        if(j == 0){
            return 1;
        }
        if(i == 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // Recursive Cases
        if(s[i-1] == t[j-1]){
            return dp[i][j] = (f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp));
        }
        else{
            return dp[i][j] = (f(i-1, j, s, t, dp));
        }
    }

    int tab(int n, int m, string s, string t){
        // 2-D of type "double" to avoid integer overflow issues
        vector<vector<double>> dp(n+1, vector<double> (m+1, 0));

        // Base Case->
        for(int i = 0; i < n; ++i) dp[i][0] = 1;
        // for(int j = 1; j < m; ++j) dp[0][j] = 0; 
        // can be omitted as vector is already initialized with 0

        for(int i = 1; i <=n; ++i){
            for(int j = 1; j <= m; ++j){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (int)dp[n][m]; // type casted back to int
    }

    int so(int n, int m, string s, string t){
        // 1-D of type "double" to avoid integer overflow issues
        vector<double> prev(m+1, 0), curr(m+1, 0);

        // Base Case->
        prev[0] = curr[0] = 1;

        for(int i = 1; i <=n; ++i){
            for(int j = 1; j <= m; ++j){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }
                else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return (int)prev[m]; // type casted back to int
    }

    int soo(int n, int m, string s, string t){
        // 1-D of type "double" to avoid integer overflow issues
        vector<double> prev(m+1, 0);

        // Base Case->
        prev[0] = 1;

        for(int i = 1; i <=n; ++i){
            for(int j = m; j >= 1; --j){ // running j loop from m -> 1
                if(s[i-1] == t[j-1]){
                    prev[j] = prev[j-1] + prev[j];
                }
                // else{
                //     prev[j] = prev[j];
                // }
            }
        }

        return (int)prev[m]; // type casted back to int
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        //* Recursive Approach-> TLE
        // 0-based indexing
        // return rec(n-1, m-1, s, t);
        // 1-Based Indexing
        // return f(n, m, s, t);

        //* DP Memoization->
        // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        // return f(n, m, s, t, dp);

        //* DP Tabulation->
        // return tab(n, m, s, t);

        //* DP Space Optimisation->
        // return so(n, m, s, t);

        //* DP Single Array Space Optimisation->
        return soo(n, m, s, t);
    }
};