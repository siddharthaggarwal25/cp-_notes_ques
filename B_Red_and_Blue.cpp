#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i > 0)
                a[i] += a[i - 1];
        };
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            if (i > 0)
                b[i] += b[i - 1];
        }
        int x = *max_element(a.begin(), a.end());
        int y = *max_element(b.begin(), b.end());
        int ans = 0 ;
        if( x>0 ) ans+= x ;
        if( y >0 ) ans+= y ;
        cout <<  ans  << endl;
    }
    return 0;
}