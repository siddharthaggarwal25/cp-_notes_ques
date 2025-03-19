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
        vector<int> v(2 * n);
        for (int i = 0; i < 2 * n; i++)
            cin >> v[i];

         sort( v.begin() , v.end() , greater< int > ())   ;
          int sum =0 ;
           for( int i =0 ;i< n  ;i++){
             sum = sum + v[i]  - v[ 2*n -i -1];
           }
           cout<<sum<<" ";
           for( int i =0 ;i< n  ;i++){
             cout<<v[i] <<" "<< v[ 2*n -1- i]<<" ";

           }
           cout<<endl;`
    }
    return 0;
}