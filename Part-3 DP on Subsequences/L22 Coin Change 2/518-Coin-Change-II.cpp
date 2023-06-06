//* https://leetcode.com/problems/coin-change-ii/description/
//* https://www.youtube.com/watch?v=HgyouUi11zk

class Solution {
public:
    int rec(int ind, int target, vector<int>& num, vector<vector<int>>& dp){
        if(ind == 0){
            // target == 0 or target is divisble by num[0]
            if(target%num[0] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }

        int notTake = rec(ind-1, target, num, dp);
        int take = 0;

        if(target >= num[ind]){
            take = rec(ind, target-num[ind], num, dp);
        }

        return dp[ind][target] = take + notTake;
    }

    int tab(int n, int x, vector<int>& num){
        vector<vector<int>> dp(n, vector<int> (x+1, 0));

        // Base Cases->
        for(int target = 0; target <= x; ++target){
            if(target%num[0] == 0){
                dp[0][target] = 1;
            }
        }

        for(int ind = 1; ind < n; ++ind){
            for(int target = 0; target <= x; ++target){
                int notTake = dp[ind-1][target];
                int take = 0;

                if(target >= num[ind]){
                    take = dp[ind][target-num[ind]];
                }

                dp[ind][target] = take + notTake;
            }
        }

        return dp[n-1][x];
    }

    int so(int n, int x, vector<int>& num){
        vector<int> prev(x+1, 0), curr(x+1, 0);

        // Base Cases->
        for(int target = 0; target <= x; ++target){
            if(target%num[0] == 0){
                prev[target] = 1;
            }
        }

        for(int ind = 1; ind < n; ++ind){
            for(int target = 0; target <= x; ++target){
                int notTake = prev[target];
                int take = 0;

                if(target >= num[ind]){
                    take = curr[target-num[ind]]; // important step
                }

                curr[target] = take + notTake;
            }
            prev = curr;
        }

        return prev[x];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        //* Recursive Approach-> TLE
        // return rec(n-1, amount, coins);

        //* DP Memoization->
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // return rec(n-1, amount, coins, dp);

        //* DP Tabulation->
        // return tab(n, amount, coins);

        //* DP Space Optimisation->
        return so(n, amount, coins);
    }
};