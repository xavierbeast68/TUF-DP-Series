//* https://leetcode.com/problems/coin-change/
//* https://www.youtube.com/watch?v=myPeWb3Y68A

class Solution {
public:
    int rec(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            // target == 0 or target is divisble by coins[0]
            if(target%coins[0] == 0){
                return target/coins[0];
            }
            else{
                return 1e9; // avoid INT_MAX to prevent overflow
            }
        }

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }

        int notTake = 0 + rec(ind-1, target, coins, dp);
        int take = INT_MAX;

        if(target >= coins[ind]){
            take = 1 + rec(ind, target-coins[ind], coins, dp);
        }

        return dp[ind][target] = min(take, notTake);
    }

    int tab(int n, int amount, vector<int>& coins){
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));

        // Base Cases->
        for(int target = 0; target <= amount; ++target){
            if(target%coins[0] == 0){
                dp[0][target] = target/coins[0];
            }
            else{
                dp[0][target] = 1e9; // not to use INT_MAX to avoid overflow
            }
        }

        for(int ind = 1; ind < n; ++ind){
            for(int target = 0; target <= amount; ++target){
                int notTake = 0 + dp[ind-1][target];
                int take = INT_MAX;

                if(target >= coins[ind]){
                    take = 1 + dp[ind][target-coins[ind]];
                }

                dp[ind][target] = min(take, notTake);
            }
        }

        return (dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount]);
    }

    int so(int n, int amount, vector<int>& coins){
        vector<int> prev(amount+1, 0), curr(amount+1, 0);

        // Base Cases->
        for(int target = 0; target <= amount; ++target){
            if(target%coins[0] == 0){
                prev[target] = target/coins[0];
            }
            else{
                prev[target] = 1e9; // not to use INT_MAX to avoid overflow
            }
        }

        for(int ind = 1; ind < n; ++ind){
            for(int target = 0; target <= amount; ++target){
                int notTake = 0 + prev[target];
                int take = INT_MAX;

                if(target >= coins[ind]){
                    take = 1 + curr[target-coins[ind]]; // important step
                }

                curr[target] = min(take, notTake);
            }
            prev = curr;
        }

        return (prev[amount] >= 1e9 ? -1 : prev[amount]);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        //* Recursive  Approach-> TLE
        // int ans = rec(n-1, amount, coins);
        // if(ans >= 1e9){
        //     return -1;
        // }
        // return ans;

        //* DP Memoization->
        // vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        // int ans = rec(n-1, amount, coins, dp);
        // if(ans >= 1e9){
        //     return -1;
        // }
        // return ans;

        //* DP Tabulation->
        // return tab(n, amount, coins);

        //* DP Space Optimisation->
        return so(n, amount, coins);
    }
};