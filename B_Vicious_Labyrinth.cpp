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
        vector<int > ans ( n , n );
        ans[n-1] = n-1;
        if(  k%2 ==0){
             for( int i=0 ;i< n-2  ;i++){
                 ans[i]--;
             }
        }
        for( auto it : ans )cout<<it<<" ";
        cout<<endl;
        
    }
    return 0;
}