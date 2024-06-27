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
        vector<vector<char> > arr(2);
        for (int i = 0; i < n; i++)
        {   char x;
            cin >>x;
            arr[0].push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            char x;
            cin >>x;
            arr[1].push_back(x);
        }

    

        bool check = true;
        for (int i = 0; i < n; i++)
        {
            if (arr[0][i] == '1' && arr[1][i] == '1')
            {
                check = false;
                cout << "NO" << endl;
                break;
            }
        }
        if (check)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}