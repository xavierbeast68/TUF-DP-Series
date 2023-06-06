//* https://leetcode.com/problems/edit-distance/
//* https://youtu.be/fJaKO8FbDdo

class Solution{
public:
    // 0-based indexing
    int rec(int i, int j, string s, string t){
        // Base Cases
        if(i < 0){
            return (j+1);
        }
        if(j < 0){
            return (i+1);
        }

        if(s[i] == t[j]){
            return rec(i-1, j-1, s, t);
        }
        else{
            return (1 + min({rec(i-1, j, s, t), rec(i, j-1, s, t), rec(i-1, j-1, s, t)}));
        }
    }
    // 1-based indexing
    int f(int i, int j, string s, string t, vector<vector<int>>& dp){
        // Base Cases
        if(i == 0){
            return j;
        }
        if(j == 0){
            return i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i-1] == t[j-1]){
            return dp[i][j] = f(i-1, j-1, s, t, dp);
        }
        else{
            return dp[i][j] = (1 + min({f(i-1, j, s, t, dp), f(i, j-1, s, t, dp), f(i-1, j-1, s, t, dp)}));
        }
    }
    int tab(int n, int m, string s, string t){
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        // Base Cases->
        for(int i = 0; i <= n; ++i) dp[i][0] = i;
        for(int j = 0; j <= m; ++j) dp[0][j] = j;

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = (1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}));
                }
            }
        }
        return dp[n][m];
    }
    int so(int n, int m, string s, string t){
        vector<int> prev(m+1, 0), curr(m+1, 0);

        // Base Cases->
        for(int j = 0; j <= m; ++j) prev[j] = j;

        for(int i = 1; i <= n; ++i){
            curr[0] = i; // imp
            for(int j = 1; j <= m; ++j){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    curr[j] = (1 + min({prev[j], curr[j-1], prev[j-1]}));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
    int minDistance(string word1, string word2){

        int n = word1.length();
        int m = word2.length();

        //* Recursive Approach-> TLE
        // 0-based indexing
        // return rec(n-1, m-1, word1, word2);
        // 1-Based indexing
        // return f(n, m, word1, word2);

        //* DP Memoization->
        // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        // return f(n, m, word1, word2, dp);

        //* DP Tabulation->
        // return tab(n, m, word1, word2);

        //* DP Space Optimisation->
        return so(n, m, word1, word2);
    }
};
