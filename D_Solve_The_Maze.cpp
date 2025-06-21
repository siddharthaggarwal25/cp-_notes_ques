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
        vector<vector<char>> v(n, vector<char>(m));
        int GS = 0, BS = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
                if (v[i][j] == 'G')
                    GS++;
                if (v[i][j] == 'B')
                    BS++;
            }
        }

        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 'B')
                {
                    if (j - 1 >= 0 && v[i][j - 1] != '.' && v[i][j - 1] != '#')
                        ans = false;
                    if (j + 1 < m && v[i][j + 1] != '.' && v[i][j + 1] != '#')
                        ans = false;
                    if (i - 1 >= 0 && v[i - 1][j] != '.' && v[i - 1][j] != '#')
                        ans = false;
                    if (i + 1 < n && v[i + 1][j] != '.' && v[i + 1][j] != '#')
                        ans = false;
                }
            }
        }

        if (GS == 0)
            cout << "YES" << endl;
        else if (BS == 0)
            cout << "YES" << endl;
        else if (v[n - 1][m - 2] == 'B')
            cout << "NO" << endl;
        else if (v[n - 2][m - 1] == 'B')
            cout << "NO" << endl;
        else if ( n >1 && m >1 && v[n - 2][m - 2] == 'B')
            cout << "NO" << endl;
        else if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}