#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;    
    while (q--)
    {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        int c_x = 0;
        int c_y = 0;
        bool check = false;
        string s_new = s;
        reverse(s_new.begin() + l - 1, s_new.begin() + r);

        if (c_x == x && c_y == y)
        {
            cout << "YES" << endl;
            continue;
        }

        for (int i = 1; i < n+ 1; i++)

        {

            if (s_new[i - 1] == 'U')
            {
                c_y++;
            }
            else if (s_new[i - 1] == 'D')
            {
                c_y--;
            }
            else if (s_new[i - 1] == 'R')
            {
                c_x++;
            }
            else
            {
                c_x--;
            }

            if (c_x == x && c_y == y)
            {
                cout << "YES" << endl;
                check = true;
                break;
            }
        }
        if (!check)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}