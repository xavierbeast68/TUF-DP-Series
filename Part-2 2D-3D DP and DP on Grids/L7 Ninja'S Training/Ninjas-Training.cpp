//* https://youtu.be/AE39gJYuRog
//* https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h>

int rec(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
    int maxi = INT_MIN;
    if(day == 0){
        for(int task = 0; task < 3; ++task){
            if(task != last){
                maxi = max(maxi, points[day][task]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1){
        return dp[day][last];
    }

    for(int task = 0; task < 3; ++task){
        if(task != last){
            int point = points[day][task] + rec(day-1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    //* Recursive Soln-> TLE
    // return rec(n-1, 3, points);

    //* DP Memoization->
    // vector<vector<int>> dp(n,vector<int>(4,-1));
    // return rec(n-1, 3, points, dp);

    //* DP Tabulation->
    // int dp[n][4];
    // dp[0][0] = max(points[0][1], points[0][2]);
    // dp[0][1] = max(points[0][0], points[0][2]);
    // dp[0][2] = max(points[0][0], points[0][1]);
    // dp[0][3] = max({points[0][0], points[0][1], points[0][2]});
    // for(int day = 1; day < n; ++day){
    //     for(int last = 0; last < 4; ++last){
    //         dp[day][last] = 0;
    //         int maxi = 0;
    //         for(int task = 0; task < 3; ++task){
    //             if(task != last){
    //                 int point = points[day][task] + dp[day-1][task];
    //                 maxi = max(maxi, point);
    //             }
    //         }
    //         dp[day][last] = maxi;
    //     }
    // }
    // return dp[n-1][3];

    //* DP (Tabulation + Space Optimisation)->
    vector<int> prev(4);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});

    for(int day = 1; day < n; ++day){
        vector<int> temp(4);
        for(int last = 0; last < 4; ++last){
            int maxi = 0;
            for(int task = 0; task < 3; ++task){
                if(task != last){
                    int point = points[day][task] + prev[task];
                    maxi = max(maxi, point);
                }
            }
            temp[last] = maxi;
        }
        prev = temp;
    }
    return prev[3];
}