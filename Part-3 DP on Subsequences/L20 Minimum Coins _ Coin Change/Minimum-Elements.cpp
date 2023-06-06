//* https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0
//* https://www.youtube.com/watch?v=myPeWb3Y68A

#include <bits/stdc++.h> 
using namespace std;

int rec(int ind, int target, vector<int>& num, vector<vector<int>>& dp){
    if(ind == 0){
        // target == 0 or target is divisble by num[0]
        if(target%num[0] == 0){
            return target/num[0];
        }
        else{
            return 1e9; // avoid INT_MAX to prevent overflow
        }
    }

    if(dp[ind][target] != -1){
        return dp[ind][target];
    }

    int notTake = 0 + rec(ind-1, target, num, dp);
    int take = INT_MAX;

    if(target >= num[ind]){
        take = 1 + rec(ind, target-num[ind], num, dp);
    }

    return dp[ind][target] = min(take, notTake);
}

int tab(int n, int x, vector<int>& num){
    vector<vector<int>> dp(n, vector<int> (x+1, 0));

    // Base Cases->
    for(int target = 0; target <= x; ++target){
        if(target%num[0] == 0){
            dp[0][target] = target/num[0];
        }
        else{
            dp[0][target] = 1e9; // not to use INT_MAX to avoid overflow
        }
    }

    for(int ind = 1; ind < n; ++ind){
        for(int target = 0; target <= x; ++target){
            int notTake = 0 + dp[ind-1][target];
            int take = INT_MAX;

            if(target >= num[ind]){
                take = 1 + dp[ind][target-num[ind]];
            }

            dp[ind][target] = min(take, notTake);
        }
    }

    return (dp[n-1][x] >= 1e9 ? -1 : dp[n-1][x]);
}

int so(int n, int x, vector<int>& num){
    vector<int> prev(x+1, 0), curr(x+1, 0);

    // Base Cases->
    for(int target = 0; target <= x; ++target){
        if(target%num[0] == 0){
            prev[target] = target/num[0];
        }
        else{
            prev[target] = 1e9; // not to use INT_MAX to avoid overflow
        }
    }

    for(int ind = 1; ind < n; ++ind){
        for(int target = 0; target <= x; ++target){
            int notTake = 0 + prev[target];
            int take = INT_MAX;

            if(target >= num[ind]){
                take = 1 + curr[target-num[ind]]; // important step
            }

            curr[target] = min(take, notTake);
        }
        prev = curr;
    }

    return (prev[x] >= 1e9 ? -1 : prev[x]);
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.

    int n = num.size();

    //* Recursive  Approach-> TLE
    // int ans = rec(n-1, x, num);
    // if(ans >= 1e9){
    //     return -1;
    // }
    // return ans;

    //* DP Memoization->
    // vector<vector<int>> dp(n, vector<int> (x+1, -1));
    // int ans = rec(n-1, x, num, dp);
    // if(ans >= 1e9){
    //     return -1;
    // }
    // return ans;

    //* DP Tabulation->
    // return tab(n, x, num);

    //* DP Space Optimisation->
    return so(n, x, num);
}