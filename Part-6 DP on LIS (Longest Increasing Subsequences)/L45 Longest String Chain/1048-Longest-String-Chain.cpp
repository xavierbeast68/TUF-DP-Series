//* https://leetcode.com/problems/longest-string-chain/
//* https://youtu.be/YY8iBaYcc4g

bool comp(const string& s1, const string& s2){
    return s1.size() < s2.size();
}
class Solution {
public:
    bool checkPossible(string& s1, string& s2){
        if(s1.size() != (s2.size()+1)){
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
    int f(vector<string>& words, int n){
        // * Sorting Using Lambda Expression->
        // sort(words.begin(), words.end(), 
        // [](const string& s1, const string& s2) -> bool{
        //     return s1.size() < s2.size();
        // });

        //* Sorting using Custom Comparator->
        sort(words.begin(), words.end(), comp);

        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i = 0; i < n; ++i){
            for(int prev = 0; prev < i; ++prev){
                if(checkPossible(words[i], words[prev]) && dp[i] < (1 + dp[prev])){
                    dp[i] = 1 + dp[prev];
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
            }
        }
        return maxi;
    }
    int longestStrChain(vector<string>& words) {
        //* DP (Longest Increasing Subsequence)->
        int n = words.size();
        return f(words, n);   
    }
};