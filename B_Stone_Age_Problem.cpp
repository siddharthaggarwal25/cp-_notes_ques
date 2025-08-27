#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int n, q;
    cin >> n >> q;
    map <int , int > mp;
    int sum = 0;
    for (int i = 1; i <=n; i++)
    {
        int x  ;
        cin>>x ;
        mp[i] += x;
        sum += x ;
    }
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int ind, val;
            cin >> ind >> val;
            if( mp[ind] == 0){
                sum = sum - mp[0] + val;
            }else{
                 sum = sum -mp[ind] + val ;
            }
             mp[ind] = val ;
                cout<< sum <<endl;
        }
        else
        {
            int val;
            cin >> val;
            mp.clear();
            sum = val*n;
            mp[0] = val ;
            cout<<sum<<endl;
        }
    }
    return 0;
}