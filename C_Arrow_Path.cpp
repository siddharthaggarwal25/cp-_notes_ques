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
        char s[2][n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[0][i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> s[1][i];
        }
        bool check = true;
        for( int i=1;i< n  ;i+=2){
            if( i!=n-1){
                if(s[0][i]=='<' &&(  s[1][i-1]== '<' || s[1][i+1]=='<') ){
                  check = false;
                  break;
                    
                }
            }
            if( i == n-1){
                if( s[1][i-1] == '<'){
               check = false;
               break;
                   
                }
            }
        }
        if( check)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
     
    }
    return 0;
}