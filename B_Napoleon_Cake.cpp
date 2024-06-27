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
        vector<int> v(n);
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int sum =0 ;
        for(int i= n-1 ;i>=0 ;i--){
            sum = max( sum , v[i]);
            if( sum >0){
               ans[i] = 1;
            }else{
                ans[i]=0;
            }
            sum--;
        }

        for(int i=0 ;i< n;i++){
            cout<<ans[i] <<" ";
        }
        cout<<endl;

    }
    return 0;
}