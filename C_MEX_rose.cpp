#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        int cnt = 0;
        for (int i = 0; i < k; i++)
        {
            if (mp[i] == 0)
                cnt++;
        }

        if (mp[k] != 0)
        {
            int val = mp[k];;

            if( val > cnt ){
                cnt  = val ;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}