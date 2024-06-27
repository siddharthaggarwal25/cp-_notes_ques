#include <bits/stdc++.h>
using namespace std;
int f(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
{
    if (ind2 < 0)
        return 1;
    if (ind1 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = f(ind1 - 1, ind2 - 1, s1, s2, dp) + f(ind1 - 1, ind2, s1, s2, dp);
    return dp[ind1][ind2] = f(ind1 - 1, ind2, s1, s2, dp);
}
int main()
{
    string str1;
    cin >> str1;
    int n = str1.length();
    string str2 = "QAQ";
    vector<vector<int>> dp(n, vector<int>(3, -1));
    cout << f(n - 1, 2, str1, str2, dp);

    return 0;
}