//* https://atcoder.jp/contests/dp/tasks/dp_b?lang=en

#include <bits/stdc++.h>
using namespace std;

int frogJump(int ind, int k, vector<int> &heights, vector<int>& dp)
{
    //* Memoization
    // if(ind == 0){
    //     return 0;
    // }

    // if(dp[ind] != -1){
    //     return dp[ind];
    // }

    // int minSteps = INT_MAX;
    // for(int j = 1; j <=k; ++j){
    //     if(ind-j < 0){
    //         break;
    //     }
    //     int jumpEnergy = (frogJump(ind-j, k, heights, dp) + abs(heights[ind] - heights[ind-j]));
    //     minSteps = min(minSteps, jumpEnergy);
    // }

    // return dp[ind] = minSteps;

    //* Tabulation->
    dp[0] = 0;
    for(int i = 1; i < ind+1; ++i){
        int minSteps = INT_MAX;
        for(int j = 1; j <= k; ++j){
            if(i-j < 0){
                break;
            }

            int jumpEnergy = dp[i-j] + abs(heights[i]-heights[i-j]);
            minSteps = min(minSteps, jumpEnergy);
        }
        dp[i] = minSteps;
    }
    return dp[ind];
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    vector<int> dp(n+1,-1);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int ans = frogJump(n-1, k, h, dp);
    cout << ans << endl;
}