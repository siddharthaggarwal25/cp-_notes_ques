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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        bool check = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[0])
                check = false;
        }

        if (check)
        {
            cout << "NO" << endl;
        }
        else
        {

            int ind = max_element(a.begin(), a.end()) - a.begin();
            cout<<"YES"<<endl;
            for (int i = 0; i < n; i++)
            {
                if (i != ind)
                    cout << 1 << " ";
                else
                    cout << 2 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
