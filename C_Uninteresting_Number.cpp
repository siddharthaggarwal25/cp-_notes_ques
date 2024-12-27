#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int n = str.length();
        int sum = 0;
        vector<int> v(10, 0);
        for (int i = 0; i < n; i++)
        {
            int a = str[i] - '0';
            v[a]++;
            sum += a;
        }
        cout<< str <<" "<<sum<<endl;
    }
    return 0;
}