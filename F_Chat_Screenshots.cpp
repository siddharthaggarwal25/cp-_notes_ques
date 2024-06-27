#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[k+1][n + 1];
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int j = 0; j < n; j++)
            {
               arr[k][j]= arr[0][j];
            }
        bool check = true;
        for (int i = 0; i < k ; i++)
        {
            int val1 = arr[i][0];
            int val2 = arr[i + 1][0];
            int p1 = 1;
            int p2 = 1;
            while (p1 < n && p2 < n)
            {
                if (arr[i][p1] == val2)
                {
                    p1++;
                }
                else if (arr[i + 1][p2] == val1)
                {
                    p2++;
                }
                else if (arr[i][p1] != arr[i + 1][p2])
                {
                    check = false;
                    break;
                }
                else
                {
                    p1++;
                    p2++;
                }

                // if((p1==n && p2<n ) || (p2==n && p1<n )){
                //     check = false;
                // }
            }

         
        }
        if (check)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}