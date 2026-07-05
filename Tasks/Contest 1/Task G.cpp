#include <iostream>

using namespace std;

int main() {
    long long n, k;
    if (!(cin >> n >> k)) return 0;

    long long total_distance = 0;
    long long current_row = 1;

    while (k > 0) {
        long long seats_in_row = 4 * n + 4 * current_row - 4;

        if (k < seats_in_row) {
            seats_in_row = k;
        }

        total_distance += seats_in_row * current_row;
        k -= seats_in_row;
        current_row++;
    }

    cout << total_distance << "\n";
    return 0;
}
