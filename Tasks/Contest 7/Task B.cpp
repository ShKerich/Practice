#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int, long long>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({ v, w });
    }

    vector<long long> dist(n, INF);
    dist[0] = 0;

    vector<int> parent(n, -1);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;
        if (u == n - 1) break;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({ dist[v], v });
            }
        }
    }

    if (dist[n - 1] == INF) {
        cout << -1 << "\n";
    }
    else {
        vector<int> path;
        for (int v = n - 1; v != -1; v = parent[v]) {
            path.push_back(v);
        }

        reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] + 1 << (i == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
