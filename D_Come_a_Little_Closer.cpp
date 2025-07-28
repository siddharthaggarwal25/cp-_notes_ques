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
        vector<int> x;
        vector<int> y;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin>>a>>b;
            x.push_back(a);
            y.push_back(b);
        }
        sort( x.begin() , x.end());
        sort( y.begin() , y.end());

        int area = (x[n-1] - x[0] + 1) * (y[n-1] - y[0] + 1);
        if (n == area)
        {
            cout << n << endl;
        }
        else
        {
            
        }
    }
    return 0;
}