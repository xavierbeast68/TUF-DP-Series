//* https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://youtu.be/ekcwMsSIzVc

#include <bits/stdc++.h>
using namespace std;


int printLIS(int n, int arr[]){
    vector<int> dp(n, 1);
    vector<int> hash(n); // backtrack array
    int maxi = 1;
    int lastIndex = 0;

    for(int ind = 0; ind < n; ++ind){
        hash[ind] = ind;
        for(int prev_ind = 0; prev_ind < ind; ++prev_ind){
            if(arr[prev_ind] < arr[ind]&& dp[ind] < (1 + dp[prev_ind])){
                dp[ind] = 1 + dp[prev_ind];
                hash[ind] = prev_ind;
            }
        }
        if(maxi < dp[ind]){
            maxi = dp[ind];
            lastIndex = ind;
        }
    }
    
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    // Printing LIS->
    for(auto i : temp){
        cout << i << " ";
    }
    cout << endl;
    return maxi;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here

    //* Printing LIS-> TLE, TC-> O(n^2)
    return printLIS(n, arr);
}
