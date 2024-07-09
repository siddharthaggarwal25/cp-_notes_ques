#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(6, 0));
    dp[0][1] = 1;
    dp[0][2] = 1;
    dp[0][3] = 1;
    dp[0][4] = 1;
    dp[0][5] = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            dp[i][2] = dp[i - 1][1];
            dp[i][3] = dp[i - 1][2] | dp[i - 1][1];
            dp[i][4] = dp[i - 1][3] | dp[i - 1][2] | dp[i - 1][1];
            dp[i][5] = dp[i - 1][4] | dp[i - 1][3] | dp[i - 1][2] | dp[i - 1][1];
        }
        else if (arr[i] < arr[i - 1])
        {
            dp[i][4] = dp[i - 1][5];
            dp[i][3] = dp[i - 1][4] | dp[i - 1][5];
            dp[i][2] = dp[i - 1][3] | dp[i - 1][4] | dp[i - 1][5];
            dp[i][1] = dp[i - 1][5] | dp[i - 1][4] | dp[i - 1][3] | dp[i - 1][2];
        }
        else
        {
            dp[i][1] = dp[i - 1][5] | dp[i - 1][4] | dp[i - 1][3] | dp[i - 1][2];
            dp[i][2] = dp[i - 1][5] | dp[i - 1][4] | dp[i - 1][3] | dp[i - 1][1];
            dp[i][3] = dp[i - 1][5] | dp[i - 1][4] | dp[i - 1][1] | dp[i - 1][3];
            dp[i][4] = dp[i - 1][5] | dp[i - 1][1] | dp[i - 1][3] | dp[i - 1][2];
            dp[i][5] = dp[i - 1][1] | dp[i - 1][4] | dp[i - 1][3] | dp[i - 1][2];
        }
    }
    int anss = dp[n - 1][5] | dp[n - 1][4] | dp[n - 1][3] | dp[n - 1][2] | dp[n - 1][1];
    if (anss)
    {
        vector<int> ans;
        int x = 0;
        int a = n - 1;
        int lastval = 0;
        while (a >= 0)
        {
            if (arr[a] > lastval)
            {
                for (int j  = ++x; j <= 5; j++)
                {
                    if (dp[a][j] == 1)
                    {
                        ans.push_back( j);
                        lastval  = arr[a];
                        x = j;
                        break ;
                    }
                }
            }
            else if (arr[a] < lastval)
            {
                 for (int j  = --x; j >=1 ; j--)
                {
                    if (dp[a][j] == 1)
                    {
                        ans.push_back( j);
                        lastval  = arr[a];
                         x = j  ;
                        break ;
                    }
                }
            }
            else
            {
                 for (int j  = 1 ; j <= 5 ; j++)
                {
                    if (dp[a][j] == 1 && j!=x )
                    {
                        ans.push_back( j);
                        lastval  = arr[a];
                        x = j ;
                        break ;
                    }
                }
                 
            }
            a-- ;
        }

        reverse( ans.begin() , ans.end());
        for( auto it: ans)cout<<it<<" ";
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}