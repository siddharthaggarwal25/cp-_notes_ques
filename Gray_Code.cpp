#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p = pow(2, n);
    vector<vector<int>> v(p, vector<int>(n));

    int change = p / 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            int val = change;
            while (val && j < p)
            {
                v[j][i] = 0;
                j++;
                val--;
            }
            
            val = change;
            while (val && j < p)
            {
                v[j][i] = 1;
                j++;
                val--;
            }
            j--;
        }
        change = change/2;
    }

 for (int i = 0; i < p; i++)
    {
        for (int j = 1; j < n; j++)
        {
           v[ i][j]= v[i][j-1] ^ v[i][j];  
        } 
        
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
    return 0;
}