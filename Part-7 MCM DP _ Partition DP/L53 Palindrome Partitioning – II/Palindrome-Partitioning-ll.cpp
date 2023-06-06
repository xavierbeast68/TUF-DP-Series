//* https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_873266?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://youtu.be/_H8V5hJUGd0

#include <bits/stdc++.h> 
using namespace std;

bool isPalindrome(int l, int r, string s){
    while(l <= r){
        if(s[l] != s[r]){
            return false;
        }
        l++, r--;
    }
    return true;
}
int f(int i, int n, string str, vector<int>& dp){
    // Base Case->
    if(i == n){
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }

    // Recursive Case->
    int minPart = INT_MAX;
    for(int ind = i; ind < n; ind++){

        if(isPalindrome(i, ind, str)){
            int partitions = 1 + f(ind+1, n, str, dp);
            minPart = min(minPart, partitions);
        }
    }

    return dp[i] = minPart;
}

int tab(int n, string str){
    vector<int> dp(n+1, 0);

    // Base Case-> dp[n] = 0;

    for(int i = n-1; i >= 0; i--){
        int minPart = INT_MAX;
        for(int ind = i; ind < n; ind++){

            if(isPalindrome(i, ind, str)){
                int partitions = 1 + dp[ind+1];
                minPart = min(minPart, partitions);
            }
        }
        dp[i] = minPart;
    }

    return dp[0]-1;
}

int palindromePartitioning(string str) {
    // Write your code here

    int n = str.size();
    //* Recursive Approach->
    // return f(0, n, str)-1;

    //* Dp Memoization->
    // vector<int> dp(n, -1);
    // return f(0, n, str, dp)-1;

    //* Dp Tabulation->
    return tab(n, str);
}
