// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n][3];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
//     }
//     int dp[n][3];
//     dp[0][0]=arr[0][0];
//     dp[0][1]=arr[0][1];
//     dp[0][2]=arr[0][2];
//     for(int i=1 ;i< n ;i++){
//         dp[i][0] = max( dp[i-1][1] , dp[i-1][2]) + arr[i][0];
//         dp[i][1] = max( dp[i-1][0] , dp[i-1][2]) + arr[i][1];
//         dp[i][2] = max( dp[i-1][1] , dp[i-1][0]) + arr[i][2];
//     }
//     cout<< max(dp[n-1][0] , max( dp[n-1][1] , dp[n-1][2]))<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<vector<int>> dp;

int solve(int i, int j)
{
    if (i == 0)
    {
        if (j == 0)
        {
            return v[0][0];
        }
        else if (j == 1)
        {
            return v[0][1];
        }
        else
        {
            return v[0][2];
        }
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (j == 0)
    {
        return dp[i][0] = max(solve(i - 1, 1), solve(i - 1, 2)) + v[i][0];
    }
    if (j == 1)
    {
        return dp[i][1] = max(solve(i - 1, 0), solve(i - 1, 2)) + v[i][1];
    }
    return dp[i][2] = max(solve(i - 1, 1), solve(i - 1, 0)) + v[i][2];
}

int main()
{
    int n;
    cin >> n;
    v.assign(n, vector<int>(3));
    dp.assign(n, vector<int>(3, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    cout << max(solve(n - 1, 0), max(solve(n - 1, 1), solve(n - 1, 2)));

    return 0;
}