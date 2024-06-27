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
        vector<pair<char, int>> v;
        int one = 0;
        int two = 0;
        int three = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                one++;
            }
            if (s[i] == '2')
            {
                two++;
            }
            if (s[i] == '3')
            {
                three++;
            }

            if (v.empty() || v.back().first != s[i])
            {
                v.push_back({s[i], 1});
            }
            else
            {
                v.back().second++;
            }
        }
        int ans =1e9;

        for(int i=1 ;i< v.size()-1 ;i++){
            if(v[i-1].first !=  v[i+1].first){
                ans = min(ans , v[i].second +2);
            }
        }
        if(one || two || three){
            cout<<0<<endl;
        }else{
            cout<<ans<<endl;
        }

    }
    return 0;
}