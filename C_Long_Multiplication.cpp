#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main()
{
    int t;
    cin >> t;
    while (t--)
    { 

        string  s1, s2;
        cin >> s1 >> s2;
        int i = 0;

        while (i < s1.size() && s1[i] == s2[i])
        {
            i++;
        }
        if (i == s1.size())
        {
            cout << s1 << endl;
            cout << s2 << endl;
            continue;
        }
        if (s1[i] < s2[i])
        {
            char temp = s1[i];
            s1[i] = s2[i];
            s2[i] = temp;
        }
        i++;
        for (i; i < s1.size(); i++)
        {
            if (s1[i] > s2[i])
            {
                char temp = s1[i];
                s1[i] = s2[i];
                s2[i] = temp;
            }
        }
        cout << s1 << endl;
        cout << s2 << endl;
    }
    return 0;
}