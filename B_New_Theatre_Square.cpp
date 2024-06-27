#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        char arr[n][m + 1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            arr[i][m] = '*';
        }

        if (2 * x < y)
        {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (arr[i][j] == '.')
                    {
                        count++;

                    }
                }
            }
            cout << count * x << endl;
         
        }
        else
        {
            int singleCount = 0;
            int doubleCount = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (arr[i][j] == '.' && arr[i][j + 1] == '*')
                    {
                        singleCount++;
                    }
                    else if (arr[i][j] == '.' && arr[i][j + 1] == '.')
                    {
                        doubleCount++;
                        j++;
                    }
                }
            }
                cout << singleCount * x + doubleCount * y << endl;
        }
    }
    return 0;
}