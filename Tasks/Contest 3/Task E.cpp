#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = grid[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) continue;

            int from_up = -1;
            int from_left = -1;
            int from_diagonal = -1;

            if (i > 0) {
                from_up = dp[i - 1][j];
            }
            if (j > 0) {
                from_left = dp[i][j - 1];
            }
            if (i > 0 && j > 0) {
                from_diagonal = dp[i - 1][j - 1];
            }

            dp[i][j] = max({ from_up, from_left, from_diagonal }) + grid[i][j];
        }
    }

    cout << dp[n - 1][m - 1] << "\n";

    return 0;
}
