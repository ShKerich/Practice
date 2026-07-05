#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::priority_queue<long long> left_max;

    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> right_min;

    for (int i = 0; i < n; ++i) {
        long long val;
        std::cin >> val;

        if (left_max.empty() || val <= left_max.top()) {
            left_max.push(val);
        }
        else {
            right_min.push(val);
        }

        if (left_max.size() > right_min.size() + 1) {
            right_min.push(left_max.top());
            left_max.pop();
        }
        else if (right_min.size() > left_max.size()) {
            left_max.push(right_min.top());
            right_min.pop();
        }


        std::cout << left_max.top() << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";

    return 0;
}