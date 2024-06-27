#include <bits/stdc++.h>
using namespace std;
vector<pair<int, string>> v;
int price(int ind, int vit, int n , vector<vector<int  >> & dp )
{  
     if( vit == 7) return 0 ;
    if( ind == n ) return 1e9 ;
    if( dp[ind][vit] != -1 ) return  dp[ind][vit];
    int p = v[ind].first;
    string  str = v[ind].second;
    int nottake = price(ind + 1, vit, n , dp );
    int nvit  = vit ; 
    for(int i=0; i< v[ind].second.length(); i++){
         
        nvit|=1<<(v[ind].second[i]-'A');
    
    }

    int  take =  p + price( ind +1 , nvit  , n , dp );
    return  dp[ind][vit] = min( take , nottake );
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        string s;
        cin >> a >> s;
        v.push_back({a, s});
    }
    vector< vector< int >> dp( n , vector< int >  ( 8 , -1 ));
   int val = price(0, 0, n  , dp );
   if( val == 1e9 ){
    cout<<-1<<endl;
   }else{
    cout<<val<<endl;
   }
    return 0;
}