#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if( v[n-1] <0){
            v.push_back(INT16_MAX);
        }else{
            v.push_back(-1);
        }


        int sum = 0;
        int value = INT64_MIN;
      
        for (int i = 0; i < n; i++)
        {
            if (v[i] > 0 && v[i + 1] < 0)
            {
                value = max( value ,v[i]);
                sum  +=value;
           
                value=INT64_MIN;
            }
            else if (v[i] < 0 && v[i + 1] > 0)
            {
                value = max( value ,v[i]);
                sum += value;
            
                value=INT64_MIN;
            }
            else if (v[i] > 0 && v[i + 1] > 0)
            {
                value = max(value ,v[i]);
            }
            else if (v[i] < 0 && v[i + 1] < 0)
            { 
                value=max(value ,v[i]);
            }
            
        }
        cout<<sum<<endl;
    }

    return 0;
}