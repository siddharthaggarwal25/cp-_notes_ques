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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int low = 0;
        int high = n - 1;
        int min = 1;
        int max = n;
        while (low < high)
        {

            if (v[low] == min)
            {
                min++;
                low++;
            }
            else if (v[high] == min)
            {
                min++;
                high--;
            }
            else if (v[low] == max)
            {
                max--;
                low++;
            }
            else if (v[high] == max)
            {
                high--;
                max--;
            }
            else
            {
                break;
            }
        }
        if (low < high)
        {
            cout << low + 1 << " " << high + 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}