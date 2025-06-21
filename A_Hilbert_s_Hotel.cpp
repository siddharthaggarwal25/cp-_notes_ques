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

        map<int, int> mp;
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            int x = i +( v[i] % n);
            if (mp[x] == 1 || i== x)
            {
                ans = false;
                // break;
            }
            else
            {
                mp[x] = 1;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        if( t==0){
            for ( auto it: mp)cout<<it.first<<" ";
        }    
    }
    return 0;
}