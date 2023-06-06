//* https://www.codingninjas.com/codestudio/problems/divisible-set_3754960?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://youtu.be/gDuZwBW9VvM

#include <bits/stdc++.h> 
using namespace std;

vector<int> f(vector<int>& arr, int n){
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;

    sort(begin(arr), end(arr));

    for(int i = 0; i < n; ++i){
        hash[i] = i;
        for(int prev = 0; prev < i; ++prev){
            if(arr[i]%arr[prev] == 0 && dp[i] < (1 + dp[prev])){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(maxi < dp[i]){
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> ans;
    ans.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }

    return ans;
}

vector<int> divisibleSet(vector<int> &arr){
    // Write your code here.

    //* DP (Longest Increasing Subsequence)->
    int n = arr.size();
    return f(arr, n);
}