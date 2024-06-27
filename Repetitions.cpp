#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int count = 0;
        char ch = s[i];

        while (s[i] == ch ){
            count++;
            i++;
        }
        i--;

        ans = max ( ans , count );
    }

    cout<<ans<<endl;
    return 0;
}