#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int b_latest=-1;
        int B_latest=-1;
        for(int i=0 ;i< n ;i++){
            if(s[i]=='b'){
                s[b_latest]='0';

            }else if( s[i]=='B'){
                s[B_latest]='0';

            }else{
                if( s[i]>='a'){
                    b_latest=i;
                }else{
                    B_latest=i;
                }
            }


        }
    }
    return 0;
}