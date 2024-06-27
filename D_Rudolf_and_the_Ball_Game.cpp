#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m >> x;
        vector<int> times(n + 1, 0);

        set<int> st;
        st.insert(x);
        for (int j = 0; j < m; j++)
        {
            int a;
            char icon;
            cin >> a >> icon;
            if (icon == '0')
            {
                vector<int> vis;
                for (auto i = st.begin(); i != st.end(); i++)
                {
                    vis.push_back(*i);
                }
                st.clear();
                for (int i = 0; i < vis.size(); i++)
                {
                    int index = ((vis[i] + a) % n);
                    times[index]++;
                    st.insert(index);
                }
            }
            else if (icon == '1')
            {
                vector<int> vis;
                for (auto i = st.begin(); i != st.end(); i++)
                {
                    vis.push_back(*i);
                }
                st.clear();
                for (int i = 0; i < vis.size(); i++)
                {
                    int index = ((vis[i] - a + n) % n);
                    times[index]++;
                    st.insert(index);
                }
            }
            else
            {
                vector<int> vis;

                for (auto i = st.begin(); i != st.end(); i++)
                {
                    vis.push_back(*i);
                }
                st.clear();
                for (int i = 0; i < vis.size(); i++)
                {
                    int index1 = ((vis[i] + a) % n);
                    int index2 = ((vis[i] - a + n) % n);
                    times[index1]++;
                    times[index2]++;
                    st.insert(index1);
                    st.insert(index2);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << times[i] << " ";
        }
        cout << endl;
    }
    return 0;
}