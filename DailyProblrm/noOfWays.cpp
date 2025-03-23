class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            const int MOD = 1e9 + 7;
            
            // Step 1: Graph Representation (Adjacency List)
            vector<vector<pair<int, int>>> graph(n);
            for (auto& road : roads) {
                int u = road[0], v = road[1], time = road[2];
                graph[u].push_back({v, time});
                graph[v].push_back({u, time});
            }
            
            // Step 2: Dijkstra's Algorithm
            vector<long long> dist(n, LONG_LONG_MAX); // Store shortest distances
            vector<int> ways(n, 0); // Store number of ways to reach a node
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            
            // Start from node 0
            dist[0] = 0;
            ways[0] = 1;
            pq.push({0, 0}); // (distance, node)
    
            while (!pq.empty()) {
                auto [currDist, u] = pq.top();
                pq.pop();
    
                if (currDist > dist[u]) continue; // Ignore outdated distances
    
                for (auto& [v, time] : graph[u]) {
                    long long newDist = currDist + time;
    
                    // Found a shorter path to v
                    if (newDist < dist[v]) {
                        dist[v] = newDist;
                        ways[v] = ways[u];
                        pq.push({dist[v], v});
                    }
                    // Found an alternative shortest path to v
                    else if (newDist == dist[v]) {
                        ways[v] = (ways[v] + ways[u]) % MOD;
                    }
                }
            }
    
            return ways[n - 1];
        }
    };