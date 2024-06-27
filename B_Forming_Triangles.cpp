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
       vector<int> arr(n+1 ,0);

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr[x]++;
        }
        int count =0 ;

        for(int i =n ;i >= 0;i--){
            int value = arr[i];
            n -=value;

            if( arr[i] >=3){
                count += ((value)*(value-1)*(value -2))/6;
            }
            if( arr[i] >=2){
                count +=  (n)*((value)*(value-1)/2);
            } 

        }

        cout<<count<<endl;

    }
    return 0;
}