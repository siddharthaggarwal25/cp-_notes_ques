#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, sum;
    cin >> num >> sum;

    if ((sum == 0 && num > 1) || sum > 9 * num) {
        cout << "-1 -1" << endl;
        return 0;
    }

    string largest = "", smallest;

    int temp_sum = sum;
    for (int i = 0; i < num; i++) {
        if (temp_sum >= 9) {
            largest += '9';
            temp_sum -= 9;
        } else {
            largest += '0' + temp_sum;
            temp_sum = 0;
        }
    }

    smallest = largest;
    reverse(smallest.begin(), smallest.end());


    if (smallest[0] == '0'  && sum != 0) {
        smallest[0] = '1';
        for (int i = 1; i < num; i++) {
            if (smallest[i] != '0') {
                smallest[i]--;
                break;
            }
        }
    }

    cout << smallest << " " << largest << endl;
    return 0;
}
