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
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> v[i][j];
        bool ans = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (v[i][j] == 1)
                {
                    bool temp1 = true ;
                    bool  temp2 = true;

                    for (int k = 0; k < i; k++)
                        if (v[k][j] == 0)
                            temp1 = false;
                    for (int k = 0; k < j; k++)
                        if (v[i][k] == 0)
                            temp2 = false;

                    if (temp1 == false && temp2 == false)
                        ans = false;
                }
            }
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}