#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector< vector< int >>  dp ;
vector< vector< int >>  sp ;

int maxHappi(int curmoney, int curhappiness, int index, int salary, int months, vector<pair<int, int>> &data)
{
    if (index == months) return curhappiness;
    if( dp[index ] [curhappiness ] != -1 && sp[index][curhappiness] >=  salary) return dp[index][curhappiness];
    sp[index] [ curhappiness] = curmoney;
    int left = 0;
    int right = 0;
    if (data[index].first <= curmoney) left = maxHappi(curmoney - data[index].first + salary, curhappiness + data[index].second, index + 1, salary, months, data);
    right = maxHappi(curmoney + salary, curhappiness, index + 1, salary, months, data);
    return  dp[index][curhappiness] =  max(left, right);
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int months, salary;
        cin >> months >> salary;
        int sum=0 ;
        vector<pair<int, int>> data;
        for (int i = 0; i < months; i++)
        {
            int x, y;
            cin >> x >> y;
            sum += y ; 
            data.push_back({x, y});
        }
        dp.assign( months , vector< int > ( sum , -1));
        sp.assign( months , vector< int > ( sum  ));

        int ans = maxHappi(salary, 0, 1, salary, months, data);
        if (data[0].first == 0)
        {
            cout << ans + data[0].second << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}