//* https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0, prev2 = 0;
    for (int i = 1; i < n; ++i)
    {
        int left = prev1 + abs(heights[i] - heights[i - 1]);

        int right = INT_MAX;
        if (i > 1)
        {
            right = prev2 + abs(heights[i] - heights[i - 2]);
        }

        prev2 = prev1;
        prev1 = min(left, right);
    }
    return prev1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int ans = frogJump(n, h);
    cout << ans << endl;
}