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
        vector<int> a(n), b(n);
        a[0] = 1;
        for (int i = 1; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int p1 = 0;
        int p2 = 0;
        int cnt = 0;
        while (p1 < n && p2 < n)
        {
            if (a[p1] < b[p2]){
                 p1++;
                 p2++;
                 cnt++;
            }else {
                p2 ++ ;
            }
        }
        cout<<n-cnt<<endl;
    }
    return 0;
}