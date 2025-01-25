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
        vector<int> odd, even;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a % 2 == 1)
                odd.push_back(a);
            else
                even.push_back(a);
        }

        for (int i = 0; i < n; i++)

        {

            if (sum % 2 == 0)
            {
                if (even.size() > 0)
                {
                    sum += even.back();
                    even.pop_back();
                }
                else
                {
                    sum += odd.back();
                    odd.pop_back();
                }
            }
            else
            {

                if (odd.size() > 0)
                {
                    sum += odd.back();
                    odd.pop_back();
                }
                else 
                {
                    sum += even.back();
                    even.pop_back();
                }
            }

            if (sum % 2 == 0)

            {
                ans++;
                while (sum % 2 == 0)
                {
                    sum = sum / 2;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}