// Iterative approach , bottom to top

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     int dp[n] ={0};
//     dp[1] = abs( arr[0] - arr[1]);

//     for (int i = 2; i < n; i++)
//     {
//         dp[i] = INT_MAX;
//         for (int j = 1; j <= k ; j++)
//         {
//             if (i - j >= 0)
//             {
//                 dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i-j]));
//             }
//         }
//     }
//     cout<<dp[n-1]<<endl;
// }

// Recurcive approach ;

#include <bits/stdc++.h>
using namespace std;
int dp[100001];

int solve(int i, int k, int height[])
{  
    if (i == 0)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    dp[i]=INT_MAX;
    // dp[i]= min(dp[i] , solve(i-1 , k ,height) + abs( height[i] - height[i-1]) );
    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 0)
        {
             dp[i]=min(dp[i], solve(i-j,k,height)+abs(height[i]-height[i-j]));
        }
    }
    return dp[i] ;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<solve(n - 1, k, arr);
    return 0;
}