#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)\
    {
        int n;
        cin >> n;
        vector<int> v(n);
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            s.insert(v[i]);
        }

        int length = 1;
        int ans = 1;
        sort(v.begin(), v.end());
        for (int i = 1; i < n; i++)
        {

            if (v[i - 1] == v[i])
            {
                length++;
                ans = max(ans, length);
            }
            else
            {
                length = 1;
                continue;
            }
        }

      int a= s.size();
      int b= ans;

      a=a;
      b=b-1;

      if(b>=a){
        cout<<a<<endl;
      }else{
        if(a-b ==1  ){
            cout<<b<<endl;
        }else{
            cout<<b+1<<endl;
        }
      }
    }
    return 0;
}