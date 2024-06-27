#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> all;
    vector<int> temp;
    vector<int> temp2;
    temp.push_back(1);

    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            int new1 = temp[i] * (10) + 0;
            int new2 = temp[i] * (10) + 1;
            all.push_back(new1);
            all.push_back(new2);
            temp2.push_back(new1);
            temp2.push_back(new2);
        }
        temp.clear();
        temp = temp2;
        temp2.clear();
    }
   

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool check = false;
        for (int i = all.size() -1; i >=0 ; i--)
        {
            if (n % all[i] == 0)
            {
                n = n / all[i];
                i =  all.size();
            }
            if (n == 1)
            {
                check = true;
                break;
            }
        }
        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}