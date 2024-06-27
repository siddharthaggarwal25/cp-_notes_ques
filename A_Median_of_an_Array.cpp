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
        int arr[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        sort( arr+1 , arr+1 + n );
        int index  = ceil( n*1.0/2);
        int count =0 ;
        for ( int i= index ;i<=n ;i++){
            if( arr[index] == arr[i]){
                count ++ ;
            }
        }
        cout<<count<<endl;
    }

    return 0;
}