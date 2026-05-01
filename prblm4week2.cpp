#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins, coins + n);  // begin/end লাগছে না

    long long res = 1;

    for (int i = 0; i < n; i++) {
        if (coins[i] > res) break;
        res += coins[i];
    }

    cout << res << endl;

    return 0;
}
