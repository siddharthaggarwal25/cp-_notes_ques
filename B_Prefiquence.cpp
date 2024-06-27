#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        int p1 = 0;
        int p2 = 0;
        int count = 0;
        while (p1 < n && p2 < m)
        {
            if (a[p1] == b[p2])
            {
                p1++;
                p2++;
                count++;
            }
            else
            {
                p2++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}