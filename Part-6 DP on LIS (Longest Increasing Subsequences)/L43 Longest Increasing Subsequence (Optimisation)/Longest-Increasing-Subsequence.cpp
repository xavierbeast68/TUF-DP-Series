//* https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://youtu.be/ekcwMsSIzVc

#include <bits/stdc++.h>
using namespace std;

int rec(int ind, int prev_ind, int n, int arr[]){
    // Base Case
    if(ind == n){
        return 0;
    }

    // not take case
    int len = 0 + rec(ind+1, prev_ind, n, arr);
    // take case
    if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
        len = max(len, 1 + rec(ind+1, ind, n, arr));
    }

    return len;
}

int f(int ind, int prev_ind, int n, int arr[], vector<vector<int>>& dp){
    // Base Case
    if(ind == n){
        return 0;
    }

    if(dp[ind][prev_ind + 1] != -1){
        return dp[ind][prev_ind + 1];
    }

    // not take case
    int len = 0 + f(ind+1, prev_ind, n, arr, dp);
    // take case
    if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
        len = max(len, 1 + f(ind+1, ind, n, arr, dp));
    }

    return dp[ind][prev_ind + 1] = len;
}

int tab(int n, int arr[]){
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int ind = n-1; ind >= 0; --ind){
        for(int prev_ind = ind-1; prev_ind >= -1; --prev_ind){
            int len = 0 + dp[ind+1][prev_ind+1];

            if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
                len = max(len, 1 + dp[ind+1][ind+1]);
            }

            dp[ind][prev_ind+1] = len;
        }
    }

    return dp[0][0]; // dp[0][-1+1]
}

int so(int n, int arr[]){
    vector<int> next(n+1, 0), curr(n+1, 0);

    for(int ind = n-1; ind >= 0; --ind){
        for(int prev_ind = ind-1; prev_ind >= -1; --prev_ind){
            int len = 0 + next[prev_ind+1];

            if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
                len = max(len, 1 + next[ind+1]);
            }

            curr[prev_ind+1] = len;
        }
        next = curr;
    }

    return next[0]; // next[-1+1]
}

int soo(int n, int arr[]){
    vector<int> dp(n, 1);
    int maxi = 1;

    for(int ind = 0; ind < n; ++ind){
        for(int prev_ind = 0; prev_ind < ind; ++prev_ind){
            if(arr[prev_ind] < arr[ind]){
                dp[ind] = max(dp[ind], 1 + dp[prev_ind]);
            }
        }
        maxi = max(maxi, dp[ind]);
    }

    return maxi;
}

int optimised(int n, int arr[]){
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;

    for(int i = 1; i < n; ++i){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int pos = lower_bound(begin(temp), end(temp), arr[i]) - temp.begin();
            temp[pos] = arr[i];
        }
    }

    return len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here

    //* Recursive Approach-> TLE
    // return rec(0, -1, n, arr);

    //* Dp Memoization-> Runtime Error(due to 2D dp NxN, where N can be max 10^5)
    // (needs shifting of indexes)
    // TC-> O(n^2)
    // vector<vector<int>> dp(n, vector<int>(n+1, -1));
    // return f(0, -1, n, arr, dp);

    //* DP Tabulation-> Runtime Error, TC-> O(n^2)
    // return tab(n, arr);

    //* Space Optimisation-> TLE, TC-> O(n^2)
    // return so(n, arr);

    //* Using Single DP Array Method-> TLE, TC-> O(n^2)
    // return soo(n, arr);

    //* Optimised Approach (Binary Search)-> TC->O(n)
    return optimised(n, arr);
}
