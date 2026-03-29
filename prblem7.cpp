#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[1000];
    for(int i = 0; i < n; i++) cin >> nums[i];

    int target;
    cin >> target;

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = i; j < n; j++) {
            if(nums[j] == target) count++;
            int length = j - i + 1;
            if(count > length / 2) ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
