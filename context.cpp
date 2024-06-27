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
        int arr[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        if (n == 1)
        {cout<<"YES"<<endl;
            cout << 1 << endl;
        }
        else
        {
            int a[n];

            for (int i = 0; i < n; i++)
            {
               ans = i?arr[i][0]:arr[i][1];
                for (int j = 0; j < n; j++)
                {
                    if (i != j)
                    {
                        ans = ans & arr[i][j];
                    }
                }
                a[i] = ans;
            }
          
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}