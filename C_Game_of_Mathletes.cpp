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
        vector<int> v(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        int score =0 ;
        for( int i=0  ;i< n  ;i++){
             int a = mp[v[i]];
             int b = mp[ k-v[i]];

             if( v[i] == k-v[i]){
                 if( a >=2){
                    score++;
                    mp[v[i]] --;
                    mp[v[i]] --;
                 }
             }
             else if( a != 0 && b!=0){
                score++;
                mp[v[i]]--;
                mp[k - v[i]]-- ;
             }
        }
        cout<<score<<endl;
    }
    return 0;
}