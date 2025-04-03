#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 1-indexed array for convenience.
    vector<long long> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    // Build prefix sum for the original array.
    vector<long long> origPrefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        origPrefix[i] = origPrefix[i - 1] + v[i];
    }

    // Create a copy for sorting.
    vector<long long> sortedV(v.begin() + 1, v.end());
    sort(sortedV.begin(), sortedV.end());

    // Build prefix sum for the sorted array.
    vector<long long> sortedPrefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        sortedPrefix[i] = sortedPrefix[i - 1] + sortedV[i - 1];
    }

    int m;
    cin >> m;
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            // Answer for the original array.
            cout << origPrefix[r] - origPrefix[l - 1] << "\n";
        }
        else {
            // Answer for the sorted array.
            cout << sortedPrefix[r] - sortedPrefix[l - 1] << "\n";
        }
    }

    return 0;
}
