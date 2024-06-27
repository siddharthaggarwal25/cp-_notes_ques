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
        vector<int> gcd(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            gcd[i] = __gcd(v[i], v[i + 1]);
        };

        int cnt = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (gcd[i] <= gcd[i + 1])
            {
                continue;
            }
            else
            {
                cnt++;
                i++;
            }
        }

        if (cnt == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            int val = gcd[0];
            int c1 =0;
            int c2  =0 ;
            for (int i = 0; i < n - 2; i++)
            {
                if (gcd[i] > gcd[i + 1])    c1++;
            }
            for (int i = 1; i < n - 1; i++)
            {
                if (gcd[i] > gcd[i + 1])    c2++;
            }

            if( c1 == 0  || c2==0 ){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}