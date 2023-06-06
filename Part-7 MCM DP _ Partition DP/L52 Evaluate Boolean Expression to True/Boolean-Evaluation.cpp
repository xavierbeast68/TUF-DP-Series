//* https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://youtu.be/MM7fXopgyjw

#include <bits/stdc++.h> 
using namespace std;

int mod = 1e9+7;
typedef long long ll;

ll modAdd(ll a, ll b){
    return ((a%mod) + (b%mod))%mod;
}
ll modMul(ll a, ll b){
    return ((a%mod) * (b%mod))%mod;
}

ll f(int i, int j, int isTrue, string& exp, vector<vector<vector<ll>>>& dp){
    // Base Case
    if(i > j){
        return 0;
    }
    if(i == j){
        // wanted true
        if(isTrue){
            return exp[i] == 'T';
        }
        // wanted false
        else{
            return exp[i] == 'F';
        }
    }

    if(dp[i][j][isTrue] != -1){
        return dp[i][j][isTrue];
    }

    ll ways = 0;
    // Recursive Case->
    // Method-1->
    // for(int ind = i; ind < j; ind++){
        // define isOperator a boolean fn, 
        // that return true if exp[i] is &, |, ^
    //     if(isOpertor(exp[i])){
    //         -------
    //         -------
    //     }
    // }
    // Method-2->
    for(int ind = i+1; ind <= j-1; ind += 2){
        ll LT = f(i, ind-1, 1, exp, dp); // left true
        ll LF = f(i, ind-1, 0, exp, dp); // left false
        ll RT = f(ind+1, j, 1, exp, dp); // right true
        ll RF = f(ind+1, j, 0, exp, dp); // right false

        if(exp[ind] == '&'){
            if(isTrue){
                // ways = (ways + (LT*RT)%mod)%mod;
                ways = modAdd(ways, modMul(LT, RT));
            }
            else{
                // ways = (ways + (LT*RF)%mod + (LF*RT)%mod + (LF*RF)%mod)%mod;
                ways = modAdd(ways, modAdd(modMul(LT, RF), modAdd(modMul(LF, RT), modMul(LF, RF))));
            }
        }
        else if(exp[ind] == '|'){
            if(isTrue){
                // ways = (ways + (LT*RT)%mod + (LT*RF)%mod + (LF*RT)%mod)%mod;
                ways = modAdd(ways, modAdd(modMul(LT, RT), modAdd(modMul(LT, RF), modMul(LF, RT))));
            }
            else{
                // ways = (ways + (LF*RF)%mod)%mod;
                ways = modAdd(ways, modMul(LF, RF));
            }
        }
        else if(exp[ind] == '^'){
            if(isTrue){
                // ways = (ways + (LT*RF) + (LF*RT)%mod)%mod;
                ways = modAdd(ways, modAdd(modMul(LT, RF), modMul(LF, RT)));
            }
            else{
                // ways = (ways + (LT*RT)%mod + (LF*RF)%mod)%mod;
                ways = modAdd(ways, modAdd(modMul(LT, RT),  modMul(LF, RF)));
            }
        }
    }

    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string & exp) {
    // Write your code here.

    int n = exp.size();
    //* Recursive Approach-> TLE
    // return f(0, n-1, 1,exp);

    //* DP Memoization->
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, -1)));
    return f(0, n-1, 1, exp, dp);
}