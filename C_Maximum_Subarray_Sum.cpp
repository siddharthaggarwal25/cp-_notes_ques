#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> v(n);
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (s[i] == '0')
                cnt++;
        }

        int maxSum = 0, currSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                currSum += v[i];
                maxSum = max(maxSum, currSum);
            }
            else
            {
                currSum = 0;
            }
        }

        if (maxSum > k)
        {
            cout << "NO" << endl;
            continue;
        }

        if (cnt == 1)
        {
            int oneSum = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                    oneSum += v[i];
            }

            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                {
                    v[i] = k - oneSum;
                    break;
                }
            }

            

        }
        else
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                {
                    v[i] = -sum;
                    sum = 0;
                }
                else
                {
                    sum += v[i];
                }
            }
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
