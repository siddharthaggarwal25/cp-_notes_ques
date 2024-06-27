#include <bits/stdc++.h>
using namespace std;
int dp[100000][6][2];
int solve(int ind, int moves, bool leftcall, int leftmoves, int n, int k, int z, vector<int> &v)
{
    if (moves == k + 1)
        return 0;
    if (dp[ind][leftmoves][leftcall] != -1)
        return dp[ind][leftmoves][leftcall];
    int left = 0;
    int right = 0;
    if (ind < n - 1)
        right = solve(ind + 1, moves + 1, false, leftmoves, n, k, z, v);
    if (ind > 0 && leftmoves < z && leftcall == false)
        left = solve(ind - 1, moves + 1, true, leftmoves + 1, n, k, z, v);
    return dp[ind][leftmoves][leftcall] = v[ind] + max(left, right);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, z;

        cin >> n >> k >> z;
        memset(dp, -1, sizeof(dp));
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int val = solve(0, 0, false, 0, n, k, z, v);
        cout << val << endl;
    }
    return 0;
}