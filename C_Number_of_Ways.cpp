#include <bits/stdc++.h>
using namespace std;
#define int long long 

int ncr(int n, int r) {
    int res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int32_t main() {
    int n;
    cin >> n;
    int total = 0;
    vector<int> v(n), prefix(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        prefix[i] = v[i];
        total += v[i];
    }
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        prefix[i] += prefix[i - 1];
    }

    if (total % 3 == 0) {
        if (total == 0) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (prefix[i] == 0)
                    cnt++;
            }
            int val = ncr(cnt - 1, 2); 
            cout << max( val , (int)1 ) << endl;
            return 0 ;
        } else {
            int target1 = total / 3;
            int target2 = 2 * target1;
            int cnt = 0, count_target1 = 0;
            for (int i = 0; i < n - 1; i++) { 
                if (prefix[i] == target2)
                    cnt += count_target1;
                if (prefix[i] == target1)
                    count_target1++;
            }
            cout << cnt << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
