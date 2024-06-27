#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char arr[6];
        for (int i = 0; i < 6; i++)
        {
            cin >> arr[i];
        }
        bool check = false ;
        for (int i = 0; i < 4; i++)
        {
            if (arr[i] == 'W' && arr[i + 1] == 'W' && arr[i + 2] == 'W')
            {
                check = true;
                break;
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