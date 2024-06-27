#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define optimize() ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
 
int main()
{
    optimize();
   
   ll t;
   cin>>t;
   while(t--)
   {
         ll n, s;
    cin >> n >> s;
    vector<ll> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }
    vector<ll> pre(n + 1);
    pre[0] = 0;
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + vc[i];
    }
    ll mn = 1e18 + 10;
    
    for (int i = 0; i < n; i++)
    {
        ll p = s + pre[i];
        auto ic = upper_bound(pre.begin(), pre.end(), p) - pre.begin();
        if (pre[ic-1] == p)
        {
            mn = min(mn, i + n - ic+1);
        }
    }
    if (mn == 1e18 + 10)
        cout << "-1\n";
    else
        cout << mn << "\n";
   }   
    
           
    }