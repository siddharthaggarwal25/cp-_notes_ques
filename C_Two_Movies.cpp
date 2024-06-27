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
            vector<int> a(n), b(n);
            for( auto &i : a)cin>>i;
            for( auto &i : b)cin>>i;
        

            int positive = 0;
            int negative = 0;
            int a_only = 0;
            int b_only = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == 1 && b[i] == 1)
                    positive++;
                else if (a[i] == -1 && b[i] == -1)
                    negative++;
                else if (a[i] == 1)
                    a_only++;
                else if (b[i] == 1)
                    b_only++;
            }
            int maxi = max(a_only, b_only);
            int mini = min(a_only, b_only);
            while (positive > 0)
            {
                if (mini < maxi)
                    mini++;
                else
                    maxi++;

                positive--;
            }
            while (negative > 0)
            {
                if (mini < maxi)
                    maxi--;
                else
                    mini--;

                negative--;
            }
            cout << min(mini, maxi) << endl;
        }
        return 0;
    }