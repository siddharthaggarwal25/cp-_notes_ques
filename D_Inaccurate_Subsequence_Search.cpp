#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> big(n),  small(m);
        for (int i = 0; i < n; i++) cin >> big[i];
        for (int i = 0; i < m; i++) cin >> small[i];
        map< int ,int > a , b ;
        int cur =0;
        int count =0 ;
        for(int i=0 ;i<m  ;i++)  b[small[i]]++;
        for( int i=0 ;i< m  ;i++){
            a[ big [i]]++;
            if( b[ big [i]] && a[big [i]] <= b[big[i]])  cur++;
        } 
        if( cur>=k) count++;
        for( int i=m  ;i< n ;i++){
            a[big[ i-m]] -- ;
            if( b[big[i-m]] && a[big[i-m]] <b[big[i-m ]]) cur--;
            a[big[i]]++;
            if( b[big[i]] && a[big[i]] <= b[big[i ]]) cur++;
            if( cur>= k) count++;
          
        }
        cout<<count<<endl;
    }
    return 0;
}