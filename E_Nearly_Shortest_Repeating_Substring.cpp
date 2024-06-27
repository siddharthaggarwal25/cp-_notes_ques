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
        string s;
        cin >> s;
        s = " " + s;
        int ans = n;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                string str = "";
                string str2 = "";
                for (int k = 1; k <= i; k++)
                {
                    str += s[k];
                }
                for (int k = n - i + 1; k <= n; k++)
                {
                    str2 += s[k];
                }
                int count = 0;
                int count2 = 0;
                
                for (int j = i + 1; j <= n; j++)
                {
                    for (int k = 0; k < i; k++)
                    {
                        if (str[k] != s[j])
                        {
                            count++;
                        }
                        j++;
                    }
                    j--;
                }
                for (int j = 1; j <= n-i ; j++)
                {
                    for (int k = 0; k < i; k++)
                    {
                        if (str2[k] != s[j])
                        {
                            count2++;
                        }
                        j++;
                    }
                    j--;
                }
            
                if (count <2 || count2 <2)
                {
                    ans = i;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}