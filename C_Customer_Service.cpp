#include <bits/stdc++.h>
using namespace std;

int findMEX(vector<int> &nums , int n )
{
    unordered_set<int> numSet(nums.begin(), nums.end());
    int mex = 0;
    while (numSet.count(mex))
    {
        mex++;
    }
    return mex;
}
int solve(int ind, vector<int> &temp, vector<vector<int>> &v, int n)
{
    if (ind == n)  return findMEX(temp, n);

    for (int i = 0; i < n; i++)  temp[i] += v[ind][i];
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int q = temp[i];
        temp[i] = 0;
        ans = max(solve(ind + 1, temp, v, n), ans);
        temp[i] = q;
    }
    for (int i = 0; i < n; i++) temp[i] -= v[ind][i];
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> v[i][j];
        }
        vector<int> temp(n, 0);
        int ans = solve(0, temp, v, n);
        cout << ans << endl;
    }
    return 0;
}