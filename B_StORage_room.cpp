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
        int m[n][n];
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = (1<<30) - 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    arr[i] &= m[i][j];
                    arr[j] &= m[i][j];
                }
            }
        }

        bool check = true;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    if ((arr[i]|arr[j]) != m[i][j])
                    {
                        check = false;
                        break;
                    }
                }
            }
            if (!check)
            {
                break;
            }
        }
        if (check)
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}