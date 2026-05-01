#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> songs(n);
    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }

    unordered_set<int> s;
    int left = 0, ans = 0;

    for (int right = 0; right < n; right++) {
        while (s.count(songs[right])) {
            s.erase(songs[left]);
            left++;
        }
        s.insert(songs[right]);
        ans = max(ans, right - left + 1);
    }

    cout << ans << endl;

    return 0;
}
