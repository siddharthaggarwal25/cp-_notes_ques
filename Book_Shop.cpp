#include <bits/stdc++.h>
using namespace std;
int f(int ind, int money, vector<int> &price, vector<int> &value, vector<vector<int>> &dp)
{
    if (ind < 0)
        return 0;
    if (dp[ind][money] != -1)
        return dp[ind][money];
    int nottake = f(ind - 1, money, price, value, dp);
    int take = -1e8;
    if (money - price[ind] >= 0)
        take = value[ind] + f(ind - 1, money - price[ind], price, value, dp);

    return dp[ind][money] = max(take, nottake);
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> price(n), value(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> value[i];
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    cout << f(n - 1, k, price, value, dp);
    return 0;
}