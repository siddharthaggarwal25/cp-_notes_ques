#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int tests;
    cin >> tests;
    while (tests--)
    {

        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            string temp = s.substr(l - 1, r - l + 1);
            int left = -1;
            int right = -1;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == temp[0])
                {
                    left = i;
                    break;
                }
            }
            for (int i = s.size() - 1; i >= 0; i--)
            {
                if (s[i] == temp[temp.size() - 1])
                {
                    right = i;
                    break;
                }
            }
            if (left < l - 1 || right > r - 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}