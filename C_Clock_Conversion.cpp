#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int hr = 10 * (s[0] - '0') + (s[1] - '0');
        // cout<<hr<<endl;
        if (hr >= 12)
        {
            if (hr > 12)
            {
                hr = hr - 12;
            }
            if (hr < 10)
            {
                cout << 0;
            }
            cout << hr << ":" << s[3] << s[4] << " "
                 << "PM" << endl;
        }
        else
        {
            if (hr == 00)
            {
                hr = 12;
            }
            if (hr < 10)
            {
                cout << 0;
            }
            cout << hr << ":" << s[3] << s[4] << " "
                 << "AM" << endl;
        }
    }
    return 0;
}