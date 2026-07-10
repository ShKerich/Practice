#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long total_triplets = 0;
    int R = 0;

    for (int L = 0; L < n; L++) {

        while (R < n && a[R] - a[L] <= k) {
            R++;
        }

        long long count_elements = R - L - 1;

        if (count_elements >= 2) {
            long long ways = (count_elements * (count_elements - 1)) / 2;
            total_triplets += ways;
        }
    }

    cout << total_triplets << "\n";

    return 0;
}
