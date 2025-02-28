#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << max(n, m) + 1 << endl;
    }
    return 0;
}