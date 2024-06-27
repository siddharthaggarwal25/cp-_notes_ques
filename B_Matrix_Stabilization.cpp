#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> ind(m) , temp ;;
        set< int >st;
        for (int i = 0; i < m; i++)
        {
            cin >> ind[i];
            ind[i]--;
            st.insert( ind[i]);
        }
       for(auto it : st)temp.push_back( it);
        string c;
        cin >> c;
        sort( c.begin() , c.end());
        for( int i=0 ;i< temp.size() ;i++){
            s[temp[i]] = c[i];
        }
        cout<<s<<endl;
       
    }
    return 0;
}