#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<vector<int>>& edges, int distanceThreshold) {
    const int INF = 1e9;
    
    vector<vector<int>> dist(n, vector<int>(n, INF));
    
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        dist[u][v] = w;
        dist[v][u] = w;
    }
    
    // Floyd-Warshall algorithm to find the shortest distance between all pairs of cities
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int minReachableCities = INF;
    int city = -1;
    
    for (int i = 0; i < n; i++) {
        int reachableCities = 0;
        
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= distanceThreshold) {
                reachableCities++;
            }
        }
        
        if (reachableCities <= minReachableCities) {
            minReachableCities = reachableCities;
            city = i;
        }
    }
    
    return city;
}

// do not modify the code below
int main() {
    int n, m, distanceThreshold;
    cin >> n >> m >> distanceThreshold;
    vector<vector<int>> edges;
    for (int i = 1; i <= m; i++) {
        int x, y, weight;
        cin >> x >> y >> weight;
        vector<int> f;
        f.push_back(x);
        f.push_back(y);
        f.push_back(weight);
        edges.push_back(f);
    }

    cout << solve(n, edges, distanceThreshold);

    return 0;
}
