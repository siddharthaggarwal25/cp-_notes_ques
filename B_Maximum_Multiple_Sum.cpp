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
        int ans = 0;
        int start = 0;

        for (int i = 2; i <= n; i++)
        {
            int val = i;

            int temp = 0;
            int cnt = 2;
            while (val <= n)
            {
                temp += val;
                val = i*cnt;
                cnt++;
            }

            if (temp > ans)
            {
                start = i;
                ans = temp;
            }
            // cout<<temp<<" ";
        }
        // cout<<endl;
        cout << start << endl;
    }
    return 0;
}