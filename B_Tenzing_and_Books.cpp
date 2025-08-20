#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, tar;
        cin >> n >> tar;
        vector<vector<int>> v(3, vector<int>(n));
        for (int i = 0; i < n; i++)
            cin >> v[0][i];
        for (int i = 0; i < n; i++)
            cin >> v[1][i];
        for (int i = 0; i < n; i++)
            cin >> v[2][i];

        int val = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = v[i][j];
                bool check = true;
                for (int k = 0; k <= 31; k++)
                {

                    if (((tar & (1 << k)) == 0) && ((temp & (1 << k)) != 0))
                        check = false;
                }
                if (check)
                    val = val | temp;
                else
                    break;
            }
        }

        if (val == tar)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}