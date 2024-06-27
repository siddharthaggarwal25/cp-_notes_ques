#include <bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> vf(n);
    vector<int> vr(n);
    for (int i = 0; i < n; i++)
    {
        vf[i] = v[i];
        vr[i] = v[i];
    }
    for (int i = 1; i < n; i++)
    {
        vf[i] += vf[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        vr[i] += vr[i + 1];
    }
    int low = 0;
    int high = n - 1;
    int ans = 0;
   
    while (low < high)
    {
        if (vf[low] == vr[high])
        {
            ans = max(vf[low], ans);
            low++;
        }
        else if (vf[low] < vr[high])
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    cout << ans  << endl;
    return 0;
}