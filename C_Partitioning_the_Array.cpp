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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
             int count =0;
        for(int i=1 ;i<= n;i++){
            if( n%i == 0){
                int g=0;
                for(int j=0 ;j +i < n ;j++){
                    g = __gcd( g ,abs( arr[j+i] -arr[j]));
                }
                if( g!=1){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}