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
        string s;
        cin >> s;
        map<pair<int, int>  , int > mp;
        int a = 0, b = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'D')
                a++;
            else
                b++;

            int q = a, w = b;
            if (w == 0)q = 1;
            else if (q == 0) w = 1;
            else {

                int value = __gcd( q , w );
                q = q/value ;
                w = w/value ;
            }

            mp[{q, w}]++;
            cout << mp[{q, w}] <<" ";
        }
        cout<<endl;
    }
    return 0;
}