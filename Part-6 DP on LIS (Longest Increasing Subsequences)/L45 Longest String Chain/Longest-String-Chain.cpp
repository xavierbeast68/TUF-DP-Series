//* https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://youtu.be/YY8iBaYcc4g

#include <bits/stdc++.h> 
using namespace std;

bool checkPossible(string& s1, string& s2){
    if(s1.size() != 1+s2.size()){
        return false;
    }

    int first = 0, second = 0;
    while(first < s1.size()){
        if(s1[first] == s2[second]){
            first++, second++;
        }
        else{
            first++;
        }
    }

    if(first == s1.size() && second == s2.size()){
        return true;
    }
    return false;
}

int f(vector<string>& arr){
    int n = arr.size();

    vector<int> dp(n, 1);
    int len = 1;

    for(int i = 1; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(checkPossible(arr[i], arr[prev]) && (dp[i] < 1+dp[prev])){
                dp[i] = 1 + dp[prev];
            }
        }
        if(len < dp[i]){
            len = dp[i];
        }
    }

    return len;
}

bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &arr)
{
    // Write your code here.

    sort(arr.begin(), arr.end(), comp);
    //* DP (LIS)->
    return f(arr);
}