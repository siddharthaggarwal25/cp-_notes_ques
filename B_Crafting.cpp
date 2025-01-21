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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (a[i] < b[i])
                cnt++;
        if (cnt == 0)
        {
            cout << "YES" << endl;
        }
        else if (cnt == 1)
        {
            int diff;
             int ind ;
            for (int i = 0; i < n; i++)
                if (a[i] < b[i])
                    diff = b[i] - a[i] ,  ind  = i ;
            bool ans = true;
            for (int i = 0; i < n; i++)
            {   
                 if ( i == ind)continue;
                 else if( a[i] - diff <b[i])ans = false ;
            }
            if (ans)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}