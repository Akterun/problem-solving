#include <bits/stdc++.h>
using namespace std;

// comparator for numeric strings
bool cmp(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

// function to sort big numbers
vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), cmp);
    return unsorted;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;   // number of strings

    vector<string> arr(n);

    // input array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // sorting call
    vector<string> result = bigSorting(arr);

    // output result
    for (int i = 0; i < n; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
