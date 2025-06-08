#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    bool check = true;
    vector<vector<char>> v(n, vector<char>(m, '.'));
    for (int i = 0; i< n; i++)
    {

        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                v[i][j] = '#';
            }
        }
        else
        {
            if (check)
            {
                v[i][m - 1] = '#';
                check = false;
            }
            else
            {
                v[i][0] = '#';
                check = true;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
    return 0;
}