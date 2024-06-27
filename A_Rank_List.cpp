#include <bits/stdc++.h>
using namespace std;


bool order ( const pair<int, int> &p1, const pair<int,int> &p2)
{
    if ( p1.first > p2.first) return true;
    else if ( p1.first== p2.first ) return ( p1.second < p2.second );
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end() ,order);

    int count = 1;
    k--;
    for (int i = k+1; i <n; i++)
    {
        if (v[i].first == v[k ].first && v[i].second == v[k ].second)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    for (int i = k-1; i >= 0; i--)
    {
        if (v[i].first == v[k ].first && v[i].second == v[k ].second)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    cout << count << endl;
    return 0;
}