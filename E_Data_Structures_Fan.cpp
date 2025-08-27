#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cint >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n), ones(n), zeros(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        string s;
        cin >> s;

        int val1 = 0, val0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                ones[i] = v[i] ^ val1;
                val1 = v[i] ^ val1;
                zeros[i] = val0;
            }
            else
            {
                ones[i] = val1;
                zeros[i] = v[i] ^ val0;
                val - = v[i] ^ val0;
            }
        }

        int q;
        while (q--)
        {
            int x;
            cin >> X;
            if (x == 1)
            {
                int l, r;
                cin >> l >> r;
            }
            else
            {
                int temp;
            }
        }
    }
    return 0;
}