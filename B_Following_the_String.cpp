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
        int alpha[26];
        for (int i = 0; i < 26; i++)
        {
            alpha[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (arr[i] == alpha[j])
                {
                    cout << char('a' + j);
                    alpha[j]++;
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}