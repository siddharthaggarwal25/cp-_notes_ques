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
        string arr;
        cin >> arr;
        int r = sqrt(n);
        if (r * r != n)
            cout << "NO" << endl;
        else
        {
            int index = 0;
            bool ans = true;

            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    if (i == 0 || i == r - 1)
                    {
                        if (arr[index] != '1')
                            ans = false;
                    }
                    else if (j == 0 || j == r - 1)
                    {
                        if (arr[index] != '1')
                            ans = false;
                    }
                    else
                    {
                        if (arr[index] != '0')
                            ans = false;
                    }
                    index++;
                }
            }

            if (ans)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}