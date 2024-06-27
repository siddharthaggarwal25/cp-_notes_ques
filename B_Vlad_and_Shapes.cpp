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
        char arr[n][n];
        int ans[n];
        int zero = 0;
        int one = 0;

        for (int i = 0; i < n; i++)
        {
            ans[i] = 0;
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == '1')
                {
                    ans[i]++;
                }
            }
        }
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] != 0)
            {
                s.insert(ans[i]);
            }
        }
        if (s.size() == 1)
        {
            cout << "SQUARE" << endl;
        }
        else
        {
            cout << "TRIANGLE" << endl;
        }
    }
    return 0;
}