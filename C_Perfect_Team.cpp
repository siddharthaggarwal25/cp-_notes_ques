#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int c, m, x;
        cin >> c >> m >> x;
     int ans= min((c+x+m)/3 ,min(c,m));
     cout<<ans<<endl;
    }

    return 0;
}