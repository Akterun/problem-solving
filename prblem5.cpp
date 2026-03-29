#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int nums1[1000];
    int nums2[1000];

    for(int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    for(int i = m; i < m+n; i++) nums1[i] = 0;

    for(int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while(j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }


    for(int t = 0; t < m+n; t++) {
        cout << nums1[t] << " ";
    }
    cout << "\n";

    return 0;
}
