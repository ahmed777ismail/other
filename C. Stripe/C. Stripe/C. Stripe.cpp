#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;  // Number of squares

    vector<int> arr(n);
    long long total_sum = 0;

    // Read input and compute total sum
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total_sum += arr[i];
    }

    // If total sum is odd, it's impossible to split
    if (total_sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long half_sum = total_sum / 2;
    long long prefix_sum = 0;
    int ways = 0;

    // Find valid cut positions
    for (int i = 0; i < n - 1; i++) {  // Avoid cutting at the last position
        prefix_sum += arr[i];
        if (prefix_sum == half_sum) {
            ways++;
        }
    }

    cout << ways << endl;
    return 0;
}
