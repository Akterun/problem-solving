#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int count[100005] = {0};
    double mid = (m + 1) / 2.0;

    for(int ball = 1; ball <= n; ball++) {

        int best = 1;

        for(int i = 2; i <= m; i++) {
            if(count[i] < count[best]) {
                best = i;
            }
            else if(count[i] == count[best]) {
                if(abs(i - mid) < abs(best - mid)) {
                    best = i;
                }
                else if(abs(i - mid) == abs(best - mid)) {
                    if(i < best) {
                        best = i;
                    }
                }
            }
        }

        cout << best << "\n";
        count[best]++;
    }

    return 0;
}
