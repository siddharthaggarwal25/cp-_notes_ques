#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, int cnt , map<int , int >&mp)
{

    if (n == k)
        return cnt;
    if (n < k)
        return 1e9;
     if( mp.find( n) != mp.end())return  mp[n]  ;

    if (n % 2 == 0)
        return mp[n] = solve(n / 2, k, cnt + 1 ,mp) ;
    return mp[n] = min(solve(n / 2, k, cnt + 1 , mp), solve((n + 1) / 2, k, cnt + 1 ,mp) );
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<int , int > mp;
        int ans = solve(n, k, 0 , mp);
        if (ans == 1e9)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}