#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int maxi = max_element(v.begin(), v.end()) - v.begin();
    int mini = min_element(v.rbegin(), v.rend()) - v.rbegin();
    int ans = maxi + mini;
    if ((n -1- mini) < maxi)
        ans--;

    cout << ans << endl;

    return 0;
}