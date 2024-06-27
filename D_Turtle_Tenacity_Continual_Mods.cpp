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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        if (arr[0] != arr[1])
        {
            cout << "YES" << endl;
        }
        else
        {
            bool check = false;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] % arr[0] != 0)
                {
                    check = true;
                    break;
                }
            }
            if( check) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}