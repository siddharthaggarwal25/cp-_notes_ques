#include <bits/stdc++.h>
using namespace std;
int solve(int n, int m)
{
    int cnt = 0;
    while (n > 1)
    {
        cnt++;
        n = ( n+1) / 2;
    }
    while (m > 1)
    {
        cnt++;
        m = ( m+1) / 2;
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int ans = 1 + min(min(solve(n, b), solve(n, m - b + 1)), min(solve(a, m), solve(n - a + 1, m)));
        cout << ans << endl;
    }
    return 0;
}