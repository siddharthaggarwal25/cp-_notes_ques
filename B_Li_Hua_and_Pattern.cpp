#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v( n*n);
        for (int i = 0; i < n * n; i++)
        {
            cin >> v[i];
        }

        int cnt = 0;
        for (int i =0 ;i < n * n; i++)
        {
            int temp = n * n -1 - i;
            if (i == temp)
                continue;

            if (v[i] != v[temp])
                cnt++;
        }

        cnt  = cnt/2;
       
         int temp = k-cnt ;

         if( temp< 0 )cout<<"NO"<<endl;
         else if( temp%2 ==  0 || n%2 ==1)cout<<"YES"<<endl;
         else cout<<"NO"<<endl;
    }
    return 0;
}