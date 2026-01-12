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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, v[i]);
            if (i % 2 == 1)
                v[i] = maxi;
        }

        int ans = 0;
        for (int i = 1; i < n; i += 2)
        {
            if( v[i-1] == v[i]){
                 ans++;
            }
             if( i+1 < n && v[i] <= v[i+1]){
                 ans += v[i+1]- v[i] +1;
                 v[i+1] = v[i]-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}