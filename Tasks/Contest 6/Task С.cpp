#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    long long s, f;
    if (!(cin >> n >> m >> s >> f)) return 0;

    --s; --f;

    vector<vector<int>> g(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> pw(n, -1);
    vector<char> used(n, 0);

    used[s] = 1;


    auto dfs = [&](auto&& self, int u) -> bool {

        if (u == f) {
            return true;
        }

        for (int v : g[u]) {
            if (!used[v]) {
                used[v] = 1;
                pw[v] = u;

                if (self(self, v)) {
                    return true;
                }
            }
        }
        return false;
        };

    dfs(dfs, s);

    if (!used[f]) {
        cout << -1 << "\n";
    }
    else {
        vector<int> path;
        for (int curr = f; curr != -1; curr = pw[curr]) {

            path.push_back(curr);
        }

        reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] + 1 << (i + 1 == path.size() ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
