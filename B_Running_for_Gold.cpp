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
        vector<vector<int>> v(n, vector<int>(5));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> v[i][j];
            }
        }

        int winner = 0;
        for (int i = 1; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < 5; j++)
            {
                if (v[winner][j] < v[i][j])
                    count++;
            }
            if (count < 3)
                winner = i;
        }
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (i != winner)
            {
                int c = 0;
                for (int j = 0; j < 5; j++)
                {
                    if (v[winner][j] < v[i][j])
                        c++;
                }
                if (c < 3)
                    ans = false;
            }
        }
        if (ans)
            cout << winner + 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}