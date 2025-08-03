#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int low = 0;
    int high = n/2 + n%2;
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = high; i < n; i++)
    {
        if (v[i] >= 2 * v[low])
        {
            cnt++;
            // cout<<v[low]<<" "<<v[i]<<endl;
            low++;
        }
    }
    cout << n -cnt << endl;
    return 0;
}