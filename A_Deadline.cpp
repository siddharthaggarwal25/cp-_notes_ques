#include <bits/stdc++.h>
#define int double
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int  n, d;
        bool check =true;
        cin >> n >> d;
        for (int i = 0; i < n ;i++){
            int ans = i + ceil((d/(i+1)));
            if( ans <= n){
                cout<<"YES"<<endl;
                check =false;
                break;
            }
        }
        if(check){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}