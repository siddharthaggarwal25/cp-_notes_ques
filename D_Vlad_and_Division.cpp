#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr[i] =x;
            mp[x]++;

        }
        int count =0;

        for(int i=0 ;i< n ;i++){
                if( mp[arr[i] ^ ( (1ll<<31) -1) ] != 0){
                    mp[arr[i] ^ ( (1ll<<31)  -1) ]-- ;
                    count ++;
                }  
        }
        cout<< n -(count /2)<<endl;

    }
    return 0;
}