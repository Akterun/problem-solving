#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long l;
    cin >> n >> l;

    long long a[1000];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    long long max_gap = 0;
    for(int i = 0; i < n - 1; i++) {
        long long gap = a[i+1] - a[i];
        if(gap > max_gap) max_gap = gap;
    }

    double d = max({
        (double)a[0],
        (double)(l - a[n-1]),
        max_gap / 2.0
    });

    cout << fixed << setprecision(10) << d << "\n";

    return 0;
}
