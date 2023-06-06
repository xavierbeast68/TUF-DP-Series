//* https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
//* https://youtu.be/xwomavsC86c

class Solution {
public:
    int f(int i, int j, vector<int>& cuts, int n, vector<vector<int>>& dp){
        // Base Case
        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // Recursive Case
        int minCuts = INT_MAX;
        for(int ind = i; ind <= j; ind++){
            int cost = (cuts[j+1] - cuts[i-1]) + f(i, ind-1, cuts, n, dp) + f(ind+1, j, cuts, n, dp);
            minCuts = min(minCuts, cost);
        }

        return dp[i][j] = minCuts;
    }

    int tab(vector<int> cuts, int n, int c){
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+2, vector<int> (c+2, 0));

        // Base Case-> dp[i][j]=0, for all i > j

        for(int i = c; i >= 1; i--){
            for(int j = i; j <= c; j++){
                // if(i > j){
                //     continue;
                // }

                int minCuts = INT_MAX;
                for(int ind = i; ind <= j; ind++){
                    int cost = (cuts[j+1] - cuts[i-1]) + dp[i][ind-1] + dp[ind+1][j];
                    minCuts = min(minCuts, cost);
                }

                dp[i][j] = minCuts;
            }
        }

        return dp[1][c];
    }
    int minCost(int n, vector<int>& cuts) {

        int c = cuts.size();

        //* Recursive Soln-> TLE
        // cuts.push_back(n);
        // cuts.insert(cuts.begin(), 0);
        // sort(cuts.begin(), cuts.end());
        // return f(1, c, cuts, n);

        //* DP Memoization->
        // cuts.push_back(n);
        // cuts.insert(cuts.begin(), 0);
        // sort(cuts.begin(), cuts.end());
        // vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        // return f(1, c, cuts, n, dp);

        //* DP Tabulation->
        return tab(cuts, n, c);
    }
};